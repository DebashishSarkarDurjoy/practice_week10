#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define M 3
#define N 4

class Node {
public:
    char ch;
    string word;
    unordered_map<char, Node*> children;
    bool isTerminal;

    Node (char c) {
        this->ch = c;
        this->word = "";
        this->isTerminal = false;
    }
};

class Trie {
public:
    Node* root;

    Trie () {
        this->root = new Node('\0');
    }

    void addWord(string word) {
        Node* temp = root;
        for (char c: word) {
            if ( temp->children.count(c) == 0 ) {
                temp->children[c] = new Node(c);
            }
            temp = temp->children[c];
        }

        temp->isTerminal = true;
        temp->word = word;
    }
    
};

void dfs(char board[M][N], Node *node, int i, int j, bool visited[][N], unordered_set<string> &output) {
        // base case
        char ch = board[i][j];
        if (node->children.count(ch) == 0) return;

        // recursive case
        visited[i][j] = true;
        node = node->children[ch];

        if (node->isTerminal) {
            output.insert(node->word);
        }

        // 8 way dfs + trie guided search
        int di[] = {0, 1, 1, 1, 0, -1, -1, -1};
        int dj[] = {-1, -1, 0, 1, 1, 1, 0, -1};

        for (int k = 0; k < 8; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];

            if (ni >= 0 && nj >= 0 && ni < M && nj < N && !visited[ni][nj]) {
                dfs(board, node, ni, nj, visited, output);
            }
        }
        visited[i][j] = false;
        return;
    }

int main(void) {
    string words[] = {"SNAKE", "FOR", "QUEZ", "SNACK", "SNACKS", "GO", "TUNES", "CAT"};
    char board[M][N] = {
        {'S', 'E', 'R', 'T'},
        {'U', 'N', 'K', 'S'},
        {'T', 'C', 'A', 'T'}
    };

    Trie t;
    for (auto w: words) {
        t.addWord(w);
    }

    unordered_set<string> output;
    bool visited[M][N] = {false};

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            dfs(board, t.root, i, j, visited, output);
        }
    }

    for (auto word: output) {
        cout << word << endl;
    }

    return 0;
}
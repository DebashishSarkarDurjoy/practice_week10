#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph {
private:
    int V;
    list<int> *l;

public:
    Graph(int v) {
        this->V = v;
        this->l = new list<int> [this->V];
    }

    void addEdge(int i, int j) {
        this->l[i].push_back(j);
    }

    void print() {
        for (int i = 0; i < this->V; i++) {
            cout << i << " : ";
            for (int node: this->l[i]) {
                cout << node << ", ";
            }
            cout << endl;
        }
    }


    bool dfs(int node, vector<bool> &call_stack, vector<bool> &visited) {
        // recursive case
        visited[node] = true;
        call_stack[node] = true;
        for (int nbr: this->l[node]) {
            if (!visited[nbr]) {
                bool inCallStack = dfs(nbr, call_stack, visited);
                if (inCallStack) return true;
            }
            else if( call_stack[node] ) return true;
        }
        
        call_stack[node] = false;
        return false;
    }

    // bool dfs(int node, vector<bool> &call_stack, vector<bool> &visited) {
    //     visited[node] = true;
    //     call_stack[node] = true;

    //     for (int nbr: this->l[node]) {
    //         if (call_stack[nbr]) return true;
    //         else if ( !visited[nbr] ) {
    //             bool cycleFound = dfs(nbr, call_stack, visited);
    //             if (cycleFound) return true;
    //         }
    //     }

    //     call_stack[node] = false;
    //     return false;
    // }

    bool containsCycle() {
        vector<bool> call_stack(this->V, false);
        vector<bool> visited(this->V, false);

        return dfs(0, call_stack, visited);
    }

};



int main(void) {
    Graph g(3);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,0);

    g.print();
    cout << ( g.containsCycle() ? "Yes" : "No" ) << endl;

    return 0;
}
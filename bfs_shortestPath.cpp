#include <iostream>
#include <list>
#include <queue>

using namespace std;

class Graph {
private:
    int V;
    list<int> *l;

public:
    Graph (int v) {
        this->V = v;
        this->l = new list<int> [this->V];
    }

    void addEdge(int i, int j) {
        this->l[i].push_back(j);
        this->l[j].push_back(i);
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

    void bfs_shortestPath(int source, int dest) {
        queue<int> q;
        bool *visited = new bool[this->V]{false};
        int *parent = new int[this->V];
        int *dist = new int[this->V]{INT_MAX};

        q.push(source);
        parent[source] = source;
        dist[source] = 0;
        while ( !q.empty() ) {
            int front = q.front();
            q.pop();

            for (int nbr: this->l[front]) {
                if (!visited[nbr]) {
                    q.push(nbr);
                    visited[nbr] = true;

                    dist[nbr] = dist[front] + 1;
                    parent[nbr] = front;
                    
                }
            }
        }

        for (int i = 0; i < this->V; i++) {
            cout << i << " : " << dist[i] << endl;
        }

        cout << endl;

        cout << "Shortest distance between " << source << " and " << dest << " is : " << dist[dest] << endl;
    }
};

int main(void) {
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.addEdge(5,6);
    g.addEdge(4,5);
    g.addEdge(0,4);
    g.addEdge(3,4);

    g.print();

    g.bfs_shortestPath(1,6);

    return 0;
}
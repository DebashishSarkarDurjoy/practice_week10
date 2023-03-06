#include <iostream>
#include <list>
#include <vector>
#include <set>

using namespace std;

class Graph {
private:
    int V;
    list<pair<int,int>> *l;

public:
    Graph (int v) {
        this->V = v;
        this->l = new list<pair<int,int>> [this->V];
    }

    void addEdge(int i, int j, int w) {
        this->l[i].push_back({w, j});
        this->l[j].push_back({w, i});
    }

    void print() {
        for (int i = 0; i < this->V; i++) {
            cout << i << " : ";
            for (auto p: this->l[i]) {
                cout << "(" << p.first << ", " << p.second << ")    "; 
            }
            cout << endl;
        }
    }

    int dijkshtra(int source, int dest) {
        vector<int> dist (this->V, INT_MAX);
        set<pair<int,int>> s;

        s.insert({0, source});
        dist[source] = 0;
        while ( !s.empty() ) {
            auto it = s.begin();
            int node = it->second;
            int distTillNow = it->first;
            s.erase(it);
            

            for (auto nbrPair: this->l[node]) {
                int nbr = nbrPair.second;
                int currentEdge = nbrPair.first;
                
                if (currentEdge + distTillNow < dist[nbr]) {
                    auto f = s.find({dist[nbr], nbr});
                    if (f != s.end()) {
                        s.erase(f);
                    }
                    dist[nbr] = currentEdge + distTillNow;
                    s.insert( {dist[nbr], nbr} );
                }

            } 
        }

        for (int i = 0; i < this->V; i++) {
            cout << i << " : " << dist[i] << endl;
        }

        return dist[dest];
    }
};

int main(void) {
    Graph g(5);
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(0,2,4);
    g.addEdge(0,3,7);
    g.addEdge(3,2,2);
    g.addEdge(3,4,3);

    g.print();


    cout << g.dijkshtra(0,4) << endl;

}
// August 16, 2019
#include <bits/stdc++.h>

using namespace std;

class Graph {
    int v; //nodos
    list<pair<int, int>> *adj;
public:
    explicit Graph(int v);
    void addEdge(int v1, int v2, int w);
    void topological(int, bool visited[], stack<int> &stack);
    void topologicalSort(int*);
    void print() {
        //for_each(cbegin(*adj), cend(*adj), [](pair<int, int> i){cout << i.second;});
        for (int i = 0; i < v; i++) {
            cout << i + 1 << ": ";
            for (auto j = begin(adj[i]); j != end(adj[i]); j++) {
                cout << j->second << " w: " << j->first << ", ";
            }
            cout << "\n";
        }
    }
};

Graph::Graph(int v) {
    this->v = v;
    adj = new list<pair<int, int>>[v];
}

void Graph::addEdge(int v1, int v2, int w) {

    adj[v1].emplace_back(w, v2);
}

void Graph::topological(int x, bool visited[], stack<int> &stack) {
    visited[x] = true;
    for (auto i = begin(adj[x]); i != end(adj[x]); i++){
        if (!visited[i->second]) {
            topological(i->second, visited, stack);
        }
    }
    //for_each(begin(*adj), end(*adj), [this, visited, &stack](pair<int, int> i){if (!visited[i.second]) topological(i.second, visited, stack);});
    stack.push(x);
}

void Graph::topologicalSort(int *topo) {
    stack<int> stack;
    bool *visited = new bool[v];

    for (int i = 0; i < v; i++) {
        visited[i] = false;
    }

    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            topological(i, visited, stack);
        }
    }
    for (int i = 0; i < stack.size(); i++) {
        topo[i] = stack.top();
        stack.pop();
    }
}

int main() {
    int no, ed, *topo;
    int src, dest, weight;
    cin >> no >> ed;

    topo = new int[no];
    Graph g(no);
    // Ingresa numeros del 1 a n (0 a n-1)
    while (ed--) {
        cin >> src >> dest >> weight;
        g.addEdge(src - 1, dest - 1, weight);
    }

    g.topologicalSort(topo);
    for (int i = 0; i < no; i++) {
        cout << topo[i] << ",";
    }
}

/*
 input:
 5 5
 1 2 15
 2 3 12
 1 4 17
 4 2 11
 5 4 9

 output: 40

 input:
 6 6
 1 2 2
 4 5 2
 2 3 3
 1 3 2
 5 6 2
 1 2 4

 output: 7
 */

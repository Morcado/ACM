// August 16, 2019
#include <bits/stdc++.h>

using namespace std;

class Graph {
    int v; //nodos
    list<int> *adj;
public:
    Graph(int v);
    void addEdge(int v1, int v2);
    void topological(int, bool visited[], stack<int> &stack);
    void topologicalSort();
};

Graph::Graph(int v) {
    this->v = v;
    adj = new list<int>[v];
}

void Graph::addEdge(int v1, int v2) {
    adj[v1].push_back(v2);
}

void Graph::topological(int v, bool visited[], stack<int> &stack) {
    visited[v] = true;
    for_each(begin(*adj), end(*adj), [this, visited, &stack](int i){if (!visited[i]) topological(i, visited, stack);});
    stack.push(v);
}

void Graph::topologicalSort() {
    stack<int> stack;
    bool *visited = new bool[v];

    for (int i = 0; i < v; i++) {
        visited[i] = false;
    }    
    //for_each(begin(visited), end(visited), [](int& i){i = false;});

    //for_each(begin(visited), end(visited), [visited](int i){})
    for (int i = 0; i < v; i++) {
        if (visited[i] == false) {
            topological(i, visited, stack); 
        }
    }
}

int main() {
    int no; 
    int ed;
    int scr, dest, weight;
    cin >> no >> ed;

    Graph g(no);
    while (ed--) {
        int src, dest, weight;
        
    }
    //for_each(begin(edges), end(edges), [](pair<int, pair<int, int>> &i){cout << i.top() << endl; i.pop()});
    //for_each(begin(edges), end(edges), [](pair<int, pair<int, int>> i){cout << i.first << endl;});

    //Dijstra
    vector<int> nodes;

}
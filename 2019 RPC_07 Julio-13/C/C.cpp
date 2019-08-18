// August 16, 2019
#include <bits/stdc++.h>

using namespace std;

class Graph {
	int v; //nodos
	list<int> *adj;
public:
	Graph(int v);
	void addEdge(int v1, int v2);
	void topological(int)
};

Graph::Graph(int v) {
	this->v = v;
	adj = new list<int>[v];
}

void Graph::addEdge(int v1, int v2) {
	adj[v1].push_back(v2);
}

bool topologico() {
	return true;
}

int main() {
	int no;	
	int ed;

	cin >> no >> ed;

	Graph g(no);
	while (ed--) {
		
	}
	//for_each(begin(edges), end(edges), [](pair<int, pair<int, int>> &i){cout << i.top() << endl; i.pop()});
	//for_each(begin(edges), end(edges), [](pair<int, pair<int, int>> i){cout << i.first << endl;});

	//Dijstra
	vector<int> nodes;

}
#include <iostream>
#include <vector>

using namespace std;

class Vertice {
private:
public:
    int name;
    bool visited;
    vector<Vertice> relaciones;
    Vertice(int name);
};

Vertice::Vertice(int name){
    this->name = name;
}

class Grafo {
private:
public:
    vector<Vertice> vertices;
};

int main() {
    Grafo *g = new Grafo();
    int estaciones;
    int n, q;
    int u, v;
    int a, b, c, d;
    cin >> n >> q;

    for (int i = 0; i < n - 1; i++) {
        Vertice* v = new Vertice(i+1);
        g->vertices.push_back(*v);
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        g->vertices[u - 1].relaciones.push_back(g->vertices[v - 1]);
        g->vertices[v - 1].relaciones.push_back(g->vertices[u - 1]);
        cout << g->vertices[u-1].relaciones.front().relaciones.front().name;
    }
    for (int i = 0; i < n -1; i++) {
        cout << g->vertices[i].name << ": ";
        for (int i = 0; i < g->vertices[i].relaciones.size(); i++) {
            cout << g->vertices[i].relaciones[n].name << ", ";
        }
        cout << endl;
    }
    return 0;
}


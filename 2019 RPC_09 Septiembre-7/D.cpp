/* Problema D, RPC9 Septiembre 7 2019
    Pants on fire
    
    El problema trata sobre Trump y NYT, que dicen hechos que son verdaderos
    o falsos sobre las nacionalidades. Los hechos que dice NYT son verdaderos,
    y se tienen que checar lo que dice trump,

    "Fact" => lo que dice es verdad porque se puede sacar una conclusión
    "Alternative fact" => lo que dice inverso es verdad por los hechos
    "Pants on fire" => lo que dice no es verdad ni invertido

    Ejemplo:

    4 5
    Mexicans are worse than Americans       => Hechos reales
    Russians are worse than Mexicans        => Hechos reales
    NorthKoreans are worse than Germans     => Hechos reales
    Canadians are worse than Americans      => Hechos reales
    Russians are worse than Americans       => Hechos que dice trump  y que hay que revisar               
    Germans are worse than NorthKoreans     => Hechos que dice trump  y que hay que revisar     
    NorthKoreans are worse than Mexicans    => Hechos que dice trump  y que hay que revisar        
    NorthKoreans are worse than French      => Hechos que dice trump  y que hay que revisar      
    Mexicans are worse than Canadians       => Hechos que dice trump  y que hay que revisar       

    Se puede construir un grafo dirigido con los hechos reales, una arista es la relación entre las dos nacionalidades
    Si un hecho se encuentra su arista, entonces se imprime "Fact"
    Si un hecho no se encuentra su arista pero los nodos existen

     */

#include <bits/stdc++.h>
using namespace std;

// Estructura del nodo del grafo
class Nodo{
    public:
        string nombre;
        vector<Nodo> relaciones;
        // Constructor recibe el nombre del nodo (nacionalidad)
        Nodo(string nombre){
            this->nombre = nombre;
        }

        // Agrega una relación
        void agregaRelacion(Nodo n){
            relaciones.push_back(n);
        }
};
// Estructura del grafo dirigido
class Grafo{
    public:
        // Nodos del grafo
        vector<Nodo> nodos;
        void insertaNodo(string peor, string mejor){
            if(nodos.size() == 0){
                Nodo n(peor);
                n.agregaRelacion(Nodo(mejor));
                nodos.push_back(n);
            }
            else{
                bool agregar = false;
                Nodo* n = buscaNodo(peor);
                if(n == nullptr){
                    n = new Nodo(peor);
                    agregar = true;
                }
                Nodo* m = buscaNodo(mejor);
                if(m == nullptr){
                    n->agregaRelacion(Nodo(mejor));
                }
                else{
                    n->agregaRelacion(*m);
                }
                if(agregar){
                    nodos.push_back(*n);
                }
            }
        }
        Nodo* buscaNodo(string nombre){
            for(int i = 0; i < (int)nodos.size(); i++){
                if(nodos[i].nombre == nombre){
                    return &nodos[i];
                }
            }
            return nullptr;
        }
};


bool esPeor(vector<Nodo> nodos, string mejor)
    // Se busca cual 
    for(int i = 0; i < (int)nodos.size(); i++){
        if (nodos[i].nombre == mejor) {
            return true;
        }
        else {
            if(nodos[i].relaciones.size() > 0){
                return esPeor(nodos[i].relaciones, mejor);
            }
            return false;
        }
    }
    return false;
}

int esHecho(vector<Nodo> nodos, string peor, string mejor) {
    // Busca entre todos los nodos
    for (int i = 0; i < (int)nodos.size(); i++) {
        if(nodos[i].nombre == peor) {
            if (esPeor(nodos[i].relaciones, mejor)) {
                return 1;
            }
            return -1;
        }
        if (nodos[i].nombre == mejor) {
            if (esPeor(nodos[i].relaciones, peor)) {
                return 0;
            }
            return -1;
        }

    }
    return -1;
}


int main() {
    // Numero de hechos por nyt, por trump y el total
    int  nyt, trump, casos;
    // Se guardan las declaracione
    vector<string> declaraciones;
    Grafo paises;

    cin >> nyt >> trump;
    cin.ignore();

    casos = nyt + trump;
    while (casos--) {
        string line;
        getline(cin, line);
        
        // Las lineas de nyt se convierten en nodos y se insertan en el grafo
        if(nyt-- > 0){
            string  peor, mejor;
            peor = line.substr(0, line.find(' ')); // El nodo inicial es el primer pais, es el peor
            mejor = line.substr(line.find_last_of(' ') + 1); // El nodo final es el segundo pais, es el mejor
            paises.insertaNodo(peor, mejor); // Inserta en el grafo dirigido
        }
        else {
            // Las lineas restantes son de trump y se insertan en las declaraciones
            declaraciones.push_back(line);
        }
    }

    // Se recorren las declaraciones y se obtienen los paises, el peor es el primero y el mejor
    // es el segundo
    for (int i = 0; i < (int)declaraciones.size(); i++) {
        string peor = declaraciones[i].substr(0, declaraciones[i].find(' '));
        string mejor = declaraciones[i].substr(declaraciones[i].find_last_of(' ') + 1);
        // Se busca en el grafo la sentencia para determinar que tipo de hecho es
        switch (esHecho(paises.nodos, peor, mejor)) {
            case 1:
                cout<<"Fact"<<'\n';
                break;
            case 0:
                cout<<"Alternative Fact"<<'\n';
                break;
            case -1:
                cout<<"Pants on Fire"<<'\n';
                break;
        }
    }
}
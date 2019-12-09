#include <bits/stdc++.h>
using namespace std;

class Nodo{
    public:
        string nombre;
        vector<Nodo> relaciones;
        Nodo(string nombre){
            this->nombre = nombre;
        }
        void agregaRelacion(Nodo n){
            relaciones.push_back(n);
        }
};
class Grafo{
    public:
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
bool isPeor(vector<Nodo> nodos, string mejor){
    for(int i = 0; i < (int)nodos.size(); i++){
        if(nodos[i].nombre == mejor){
            return true;
        }
        else
        {
            if(nodos[i].relaciones.size() > 0){
                return isPeor(nodos[i].relaciones, mejor);
            }
            return false;
        }
    }
    return false;
}

int isFact(vector<Nodo> nodos, string peor, string mejor){
   for(int i = 0; i < (int)nodos.size(); i++){
       if(nodos[i].nombre == peor) {
           bool resultado = isPeor(nodos[i].relaciones, mejor);
           if (resultado) {
               return 1;
           }
           return -1;
       }
       if(nodos[i].nombre == mejor){
           bool resultado = isPeor(nodos[i].relaciones, peor);
           if(resultado){
               return 0;
           }
           return -1;
       }

   }
   return -1;
}


int main() {
    int  nyt, trump, casos;
    vector<string> declaraciones;
    Grafo paises;
    cin>>nyt>>trump;
    cin.ignore();
    casos = nyt + trump;
    while(casos--){
        string line;
        getline(cin, line);
        if(nyt-- > 0){
            string  peor, mejor;
            peor = line.substr(0, line.find(' '));
            mejor = line.substr(line.find_last_of(' ') + 1);
            paises.insertaNodo(peor, mejor);
        }
        else{
            declaraciones.push_back(line);
        }
    }
    for(int i = 0; i < (int)declaraciones.size(); i++){
        string peor = declaraciones[i].substr(0, declaraciones[i].find(' '));
        string mejor = declaraciones[i].substr(declaraciones[i].find_last_of(' ') + 1);
        switch (isFact(paises.nodos, peor, mejor)){
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
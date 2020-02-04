#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#include <bits/stdc++.h>
using namespace std;

typedef tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> indexed_set;

int N, M, x, posMayor, plantaInicio;
char direccion;
vector<int> numeros;
indexed_set izquierda, derecha; //conjuntos de izquierda y derecha

void imprimeConjuntos() {
    cout << "izquierda\n"; 
    for (pair<int, int> i : izquierda) {
        auto x = izquierda.find_by_order(i.second);
        cout << "valor: " << i.first << " indice: " << i.second << " ordenado: " << x->first << ", " << x->second << "\n";
    }
    cout << "\n";
    cout << "derecha\n"; 
    for (auto i : derecha) {
        auto x = derecha.find_by_order(i.second - izquierda.size() + 1);
        cout << "valor: " << i.first << " indice: " << i.second << " ordenado: " << x->first << ", " << x->second << "\n";
    }
}

int salta(char direccion, int plantaInicio) {
    if (plantaInicio < posMayor) {
            
    }
    else {
        if (plantaInicio > posMayor) {

        }
        else {
            return numeros[plantaInicio];
        }
    }
    return -1;
}


int main() {

    cin >> N >> M;

    // se obtienen los numeros primero
    for (int i = 0; i < N; i++) {
        cin >> x;
        numeros.push_back(x);
    }

    auto mayorIt = max_element(begin(numeros), end(numeros));
    posMayor = mayorIt - begin(numeros);

    // llena los conjuntos izquierda y redecha
    for (int i = 0; i <= posMayor; i++) {
        izquierda.insert({numeros[i], i});
    }
    for (int i = posMayor; i < N; i++) {
        derecha.insert({numeros[i], i});

    }

    imprimeConjuntos();

    // for (int i = 0; i < M; i++) {
    //     cin >> direccion >> plantaInicio;
    //     cout << salta(direccion, plantaInicio);
    // }
}
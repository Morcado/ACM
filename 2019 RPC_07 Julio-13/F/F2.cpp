// August 16, 2019
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<long long> v1, v2, v3;
    long long tam, kpasos, unos;
    
    cin >> tam >> kpasos;
    cin >> unos;

    // Ingresa los datos
    while (unos--) {
        int num;
        cin >> num;
        v1.push_back(num);
    }

    cin >> unos;
    while (unos--) {
        int num;
        cin >> num;
        v2.push_back(num);
    }

    // Suma los vectores. Si dos numeros son iguales en ambos con signo diferente no se suman
    // Si son con signo igual se mantiene el mismo numero y si no se encuentra en un vector se agrega
    for (auto i = begin(v1), j = begin(v2); i != end(v1) || j != end(v2);) {
        if (i == end(v1)) {
            while (j != end(v2)) {
                v3.push_back(*j);
                j++;
            }
            break;
        }
        else {
            if (j == end(v2)) {
                while (i != end(v1)) {
                    v3.push_back(*i);
                    i++;
                }
                break;
            }
            else {
                if (*i == *j) {
                // Si son iguales v1[i] y v2[i] con igual signo
                    v3.push_back(*i);
                    i++; j++;
                }
                else {
                    // Si solo se encuentra en uno de los dos vectores
                    if (abs(*i) < abs(*j)) {
                        v3.push_back(*i);
                        i++;
                    }
                    else {
                        if (abs(*i) > abs(*j)) {
                            v3.push_back(*j);
                            j++;
                        }
                        else {
                            i++; j++;
                        }
                    }
                }
            }
        }
    }

    cout << v3.size() << " ";
    for_each(begin(v3), end(v3), [](int i){cout << i << " ";});

    v3.clear();
    // Multiplicación de los vectores. Solo cuando ambos elementos se encuentran en los dos vectores
    // se multiplican y se mantiene el signo
    for (auto i = begin(v1), j = begin(v2); i != end(v1) && j != end(v2);) {
        if (*i == *j) {
            // Si son iguales v1[i] y v2[i] con igual signo
            v3.push_back(*i);
            i++; j++;
        }
        else {
            // v[i] = v[j] con signo diferente
            if (abs(*i) == abs(*j)) {
                if (*i < 0) {
                    v3.push_back(*i);
                }
                else {
                    v3.push_back(*j);
                }
                i++; j++;
            }
            else {
                // Son diferentes v[i] y v[j], avanzan iteradores
                if (abs(*i) < abs(*j)) {
                    i++;
                }
                else {
                    j++;
                }
            }

        }
    }

    cout<< "\n" << v3.size() << " ";
    for_each(begin(v3), end(v3), [](int i){cout <<  i << " ";});
    v3.clear();

    /*  Corrimiento 
        Se parte el vector hasta donde llega el valor de k. Se recorre la segunda mitad 
        y se va sumando o restando (kpasos), se van agregando los valores al resultado.
        Después se recorre la primera mitad y se van sumando o restando  (tamaño - kpasos)
        */
    // Busca el valor de k en el vector
    auto a = lower_bound(begin(v1), end(v1), kpasos, [](int a, int b){return abs(a) <= abs(b);});
    
    for_each(a, end(v1), [&kpasos, &v3](int v){
        if (v > 0) {
            v3.push_back(v - kpasos);
        }
        else {
            v3.push_back(v + kpasos);
        }
    });
    for_each(begin(v1), a, [&kpasos, &tam, &v3](int v){
        if (v > 0) {
            v3.push_back(v + (tam - kpasos));
        }
        else {
            v3.push_back(v - (tam - kpasos));
        }
    });

    cout<< "\n" << v3.size() << " ";
    for_each(begin(v3), end(v3), [](int i){cout << i << " ";});
    v3.clear();

    auto b = lower_bound(begin(v2), end(v2), kpasos, [](int a, int b){return abs(a) <= abs(b);});
    for_each(b, end(v2), [&kpasos, &v3](int v){
        if (v > 0) {
            v3.push_back(v - kpasos);
        }
        else {
            v3.push_back(v + kpasos);
        }
    });
    for_each(begin(v2), b, [&kpasos, &tam, &v3](int v){
        if (v > 0) {
            v3.push_back(v + (tam - kpasos));
        }
        else {
            v3.push_back(v - (tam - kpasos));
        }
    });

    cout<< "\n" << v3.size() << " ";
    for_each(begin(v3), end(v3), [](int i){cout << i << " ";});
    cout<< "\n";

    return 0;
}
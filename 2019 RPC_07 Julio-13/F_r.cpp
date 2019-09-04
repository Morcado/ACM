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

    // suma
    for (auto i = v1.begin(), j = v2.begin(); i != v1.end() || j != v2.end();) {
        if (i == v1.end()) {
            while (j != v2.end()) {
                v3.push_back(*j);
                j++;
            }
            break;
        }
        else {
            if (j == v2.end()) {
                while (i != v1.end()) {
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
    for_each(v3.begin(), v3.end(), [](int i){cout << i << " ";});

    v3.clear();
    // Multiplicación
    for (auto i = v1.begin(), j = v2.begin(); i != v1.end() || j != v2.end();) {
        if (i == v1.end() || j == v2.end()) {
            break;
        }
        if (*i == *j) {
            // Si son iguales v1[i] y v2[i] con igual signo
            v3.push_back(*i);
            i++; j++;
        }
        else {
            // son iguales con signo diferente
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
                // Son diferentes 
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
    for_each(v3.begin(), v3.end(), [](int i){cout <<  i << " ";});
    v3.clear();

    // Encuentra la posicion de k en el vector 1 y 2
    auto a = lower_bound(v1.begin(), v1.end(), kpasos, [](int a, int b){return abs(a) <= abs(b);});
    for_each(a, v1.end(), [&kpasos, &v3](int v){
        if (v > 0) {
            v3.push_back(v - kpasos);
        }
        else {
            v3.push_back(v + kpasos);
        }
    });
    for_each(v1.begin(), a, [&kpasos, &tam, &v3](int v){
        if (v > 0) {
            v3.push_back(v + (tam - kpasos));
        }
        else {
            v3.push_back(v - (tam - kpasos));
        }
    });

    cout<< "\n" << v3.size() << " ";
    for_each(v3.begin(), v3.end(), [](int i){cout << i << " ";});
    v3.clear();

    auto b = lower_bound(v2.begin(), v2.end(), kpasos, [](int a, int b){return abs(a) <= abs(b);});
    for_each(b, v2.end(), [&kpasos, &v3](int v){
        if (v > 0) {
            v3.push_back(v - kpasos);
        }
        else {
            v3.push_back(v + kpasos);
        }
    });
    for_each(v2.begin(), b, [&kpasos, &tam, &v3](int v){
        if (v > 0) {
            v3.push_back(v + (tam - kpasos));
        }
        else {
            v3.push_back(v - (tam - kpasos));
        }
    });

    cout<< "\n" << v3.size() << " ";
    for_each(v3.begin(), v3.end(), [](int i){cout << i << " ";});
    cout<< "\n";

    return 0;
}
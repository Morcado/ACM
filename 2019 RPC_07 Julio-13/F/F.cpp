#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

bool ascendente(int i, int j){
    if(abs(i) < abs(j))
        return true;
    return false;
}

int main() {
    vector<int> v1, v2, multiplicacion, corrimientov1, corrimientov2;
    int largo, kpasos, noZero, signo = 1;
    
    cin >> largo >> kpasos;
    cin >> noZero;
    
    int fin = largo - kpasos;
    
    while (noZero--) {
        int num;
        cin >> num;

        signo = num < 0 ? -1 : 1;
        
        if (abs(num) <= kpasos) {
            corrimientov1.push_back(signo * (abs(num) + fin));
        }
        else {
            corrimientov1.push_back(signo * (abs(num) - kpasos));
        }
        
        v1.push_back(num);
    }
    cin >> noZero;
    while (noZero--) {
        int num;
        cin >> num;
        signo = num < 0 ? -1 : 1;

        if(abs(num) <= kpasos){
            corrimientov2.push_back(signo*(abs(num)+fin));
        }
        else{
            corrimientov2.push_back(signo*(abs(num)-kpasos));
        }
        v2.push_back(num);
    }

    vector<int> suma(v1);

    for (int i = 0; i < (int)v2.size(); i++) {
        int num = abs(v2[i]);
        auto negativo = find(begin(suma), end(suma), -num);
        auto positivo = find(begin(suma), end(suma), num);

        if ((negativo != end(suma) && v2[i] > 0) || (positivo != end(suma) && v2[i] < 0)){
            multiplicacion.push_back(-num);
        }
        if ((positivo != end(suma) && v2[i] > 0) || (negativo != end(suma) && v2[i] < 0)){
            multiplicacion.push_back(num);
        }
        // negativo esta y v2 es positivo
        if(negativo != end(suma) && positivo == end(suma) && v2[i] > 0){
            suma.erase(negativo);
        }
        else {
            if(negativo == end(suma) && positivo != end(suma) && v2[i] < 0){
                suma.erase(positivo);
            }
            else {
                if (negativo == end(suma) && positivo == end(suma)) {
                    suma.push_back(v2[i]);
                }
            }
        }
    }

    cout<<suma.size() << " ";
    for(int i = 0; i < suma.size(); i++){
        cout<< suma[i] << " ";
    }
    cout<< "\n" << multiplicacion.size() << " ";
    for(int i = 0; i < multiplicacion.size(); i++){
        cout<< multiplicacion[i] << " ";
    }
    cout<< "\n" << corrimientov1.size() << " ";
    for(int i = 0; i < corrimientov1.size(); i++){
        cout<< corrimientov1[i] << " ";
    }
    cout<< "\n" << corrimientov2.size() << " ";
    for(int i = 0; i < corrimientov2.size(); i++){
        cout<< corrimientov2[i] << " ";
    }
    return 0;
}
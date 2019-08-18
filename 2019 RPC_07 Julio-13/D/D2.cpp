// August 16, 2019
#include <bits/stdc++.h>

using namespace std;

int main() {
    //Tamaño de la secuencia inicial
    int sequenceLength, n;
    // Vector para alojar la secuencia inicial y el primer paso
    vector<int> sequence, res;

    // Ingresa la secuencia
    cin >> sequenceLength;
    for (int i = 0; i < sequenceLength; i++) {
        cin >> n;
        sequence.push_back(n);
    }

    // Hace el primer paso que contiene n + 2 elementos de la secuencia
    /* resta invertida de el i-esimo elemento de la secuencia con el i-ésimo 
     elemento del resultdo, se va calculando con el anterior*/ 

    res.push_back(0);
    for (int i = 0; i < sequenceLength - 1; i++) {
        res.push_back(-(res[i] - sequence[i]));
    }
    int a = -(res[res.size() - 1] - sequence[sequence.size() - 1]);

    res.push_back(a);
    
    // Encuentra el mínimo elemento de las posiciones pares y el mínimo 
    // de las posiciones impares
    int minOdd = res[0], minEven = res[1], r;
    for (int i = 2; i < (int)res.size(); i++) {
        if (i % 2 == 0 && res[i] < minOdd) {
            minOdd = res[i];
        }
        else {
            if (i % 2 != 0 && res[i] < minEven) {
                minEven = res[i];
            }
        }
    }
    // Si cumple con un rango de menor a mayor en la recta
    if (-minOdd <= minEven) {
        r = minEven - (- minOdd) + 1;
        cout << r << "\n";
    }
    else {
        cout << "0\n";
    }

    return 0;
}
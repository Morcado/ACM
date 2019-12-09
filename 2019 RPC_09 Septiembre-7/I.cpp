#include <bits/stdc++.h>

using namespace std;

#define MAX 300001

int main() {
    int duracion, tiempo;
    int sumaActual = 0, sumaMax = 0;
    int posiciones[MAX];
    cin >> duracion >> tiempo;


    for (int i = 0; i < duracion; ++i) {
        cin >> posiciones[i];
    }

    for (int i = tiempo; i < duracion; ++i) {

        sumaActual = posiciones[i];

        for (int j = i + tiempo; j < duracion;) {
            int pas = 0;
            while (posiciones[j] < posiciones[j + 1]) {
                j++; pas++;

                if (pas == tiempo) {
                    j -= pas;
                    break;
                }
            }
            sumaActual += posiciones[j];
            j += tiempo;
            if (j == duracion - 1) {
                sumaActual += posiciones[j];
                break;
            }
//            if (posiciones[j] > posiciones[j + 1]) {
//                sumaActual += posiciones[j];
//                j += tiempo;
//            }
//            else {
//                j++;
//            }
        }

        if (sumaActual > sumaMax) {
            sumaMax = sumaActual;
        }
    }

    cout << sumaMax << "\n";
    return 0;
}
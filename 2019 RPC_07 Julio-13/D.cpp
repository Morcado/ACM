/* Problema D Down the pyramid
    Aplicación 13 Julio 2019

    En el problema se tiene que obtener los números que producirían la capa de arriba de la pirámide
    Se calcula el minimo menor par y el minimo menor impar, y después se hace una serie de calculos

*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    int sequenceLength, n;
    vector<int> sequence, res;

    cin >> sequenceLength; //Largo de la secuencia

    for (int i = 0; i < sequenceLength; i++) {
        cin >> n;
        sequence.push_back(n);
    }

    /* El vector resultante se inicia con 0. Los numeros de este vector se calcula con la diferencia negativa
    de el último numero agregado a esta secuencia menos el número de la posición i de la secuencia original. El
    largo de esta secuencia es n + 2, que sería la cantida de numeros que tendría la 
    secuencia de abajo de la piramide.
    */
    res.push_back(0);
    for (int i = 0; i < sequenceLength - 1; i++) {
        res.push_back(-(res[i] - sequence[i]));
    }
    int a = -(res[res.size() - 1] - sequence[sequence.size() - 1]); // ultimo valor
    res.push_back(a);
    
    /* Se calcula el minimo elemento de posicion impar, tomando como base el primer elemento de res, que es 0
    Se calcula el minimo elemento de posicion par, que como base sería el segundo elemento de res.
    */
    int minOdd = res[0], minEven = res[1], r;

    // Se busca el minimo elemento de posicion par e impar en todo el arreglo de "res", con esto se
    // obtiene minOdd y minEven
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

    /* Si el negativo de minodd < mineven, entonces quiere decir que hay más de una forma posible de formar una
    secuencia de números que sean por debajo de la base de la pirámide. Se calcula el numero posible de formas
    haciendo una resta como la siguiente formula.
    
    De la otra forma, no exite ninguna forma posible de hacer una secuencia.*/
    if (-minOdd <= minEven) {
        r = minEven - (- minOdd) + 1;
        cout << r << "\n";
    }
    else {
        cout << "0\n";
    }

    return 0;
}
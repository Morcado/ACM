/* Problema G, RPC11, 19 octubre 2019
   Greetings!

   El problema trata sobre una entrada que es la palabra "hey", y la salida
   tiene que imprimir el doble de letras "e" que tiene la entrada

   Ejemplo:
   hey => heey
   heeey => heeeeeey
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    // Cadena de entrada
    string cad = "";
    cin >> cad;

    cout << "h"; //siempre tiene una h por defecto
    // Calcula el doble de letras "e" de la cadena
    for (int i = 0; i < (cad.length() - 2)*2; i++) {
        cout << "e";
    }
    cout << "y\n"; // termina con y
    return 0;
}
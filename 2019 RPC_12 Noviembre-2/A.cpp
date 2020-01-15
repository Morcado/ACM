/* Problema A, RPC12, 2 de noviembre 2019
   Beer Barrels

   Se pregunta el numero de ocurrencias del digito C en una lista de
   numeros de K digitos formados por los digitos A y B 
   
   Ejemplo
   Entrada
   1 2 3 2 => Lista de numeros de 3 digitos formados por los numeros 1 y 2
   Cuantas veces aparece el digito 2? = 12 veces. Se representa como numero
   binarios y se calcula el total de digitos dividido entre 2, es la respuesta
   

   111
   112
   121
   122
   211
   212
   221
   222

   */
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Entradas, numeros en los barriles y k
    int a, b, c, k;
    cin >> a >> b >> k >> c;

    // Respuesta, minimo es 1
    long resp = 1;
    long resp2 = 0;
    // Se calcula la potencia 2^k en un ciclo, y se va dividiendo entre 
    // el numero 1000000007 para evitar que se desborde, y por los limites del problema
    for (int i = 0; i < k; i++) {
        resp = (resp * 2) % 1000000007;
    }

    // Se calcula la cantidad de digitos
    for (int i = 0; i < k; i++) {
        resp2 = (resp2+ resp) % 1000000007;
    }

    // Se divide el total entre 2 para el resultado
    cout << resp2 / 2;
    return 0;
}
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int T, N, K;
    cin>>T;
    int total = 0;
    for(int i = 0; i < T; i++){
        cin>>N>>K;
        for(int j = 0; j < N; j++){
            int dato;
            cin>>dato;
            total += dato;
        }
    }
    cout<<ceil(total/(K * 10)) * 10;
    return 0;
}
/*
busqueda binaria para encontrar el menor de los divisores que puedan dividir
se establecio el limite de 1 y el maximo es el cable de mayor longitud
*/
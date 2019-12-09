#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int mafia[100002];

int casos, adivinos;

int mejor(int i) {
    if (mafia[i] == 0  || mafia[i] == -1) {
        return 0;
    }
    return 1 + mejor(mafia[i]);
}

int recortaRama(int pos) {
    int contador = 0, anterior;
    while (pos != 1 && mafia[pos] != -1){
        contador++;
        anterior = pos;
        pos = mafia[pos];
        mafia[anterior] = -1;
    }
    return contador;
}

int main() {
    mafia[0] = 0;
    cin >> casos >> adivinos;
    for(int i = 2; i <= casos; i++){
        cin >> mafia[i];
    }
    int contador = recortaRama(casos);
    int nodos, indice, final = casos - 1;
    for (int j = 0; j < adivinos - 1; ++j) {
        bool hasMejor = false;
        nodos = mejor(final);
        indice = final - 1;
        while(mafia[indice] != 0){
            if(mejor(indice) > nodos){
                hasMejor = true;
                contador += recortaRama(indice);
            }
            indice--;
        }
        if(!hasMejor){
            contador += recortaRama(final);
        }
        final --;
    }
    cout << contador + 1<< "\n";
    return 0;
}
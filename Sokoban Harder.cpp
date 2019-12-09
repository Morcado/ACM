/*
    Harder Sokoban
    Fecha: 28/08/2019

    Ejemplo de input
    5 5
    C...C
    .....
    ####.
    .....
    O...O
    
    output: 16

    Explicacion
    el total de mov. minimos para llevar ambas cajas
    a su destino es 12 + 4 = 16
    
    Otro ejemplo
    7 6
    ######
    #...##
    #CCC##
    #OOO##
    #....#
    #....#
    ######
    
    output: 3

*/
#include <bits/stdc++.h>
#define MAX 10
using namespace std;

int N, M;
char mapa[MAX][MAX];
bool visitado[MAX][MAX][MAX][MAX][MAX][MAX];

int ejex[] = {-1, 0, 1, 0},
    ejey[] = {0, -1, 0, 1};

struct Estado{
    int coord[3][2];
    int d[3];
};

bool llegamosAlObjetivo(Estado A, Estado B){
    int  x = A.coord[0][0],  y = A.coord[0][1];
    int x2 = A.coord[1][0], y2 = A.coord[1][1];
    int x3 = A.coord[2][0], y3 = A.coord[2][1];

    int  X = B.coord[0][0],  Y = B.coord[0][1];
    int X2 = B.coord[1][0], Y2 = B.coord[1][1];
    int X3 = B.coord[2][0], Y3 = B.coord[2][1];

    return (x == X && x2 == X2 && x3 == X3 && y == Y && y2 == Y2 && y3 == Y3);
}

bool esValido(int x, int y){
    return (x > -1 && x < N && y > -1 && y < M && mapa[x][y] != '#');
}

void visitar(Estado aux){
    visitado[aux.coord[0][0]][aux.coord[0][1]][aux.coord[1][0]][aux.coord[1][1]][aux.coord[2][0]][aux.coord[2][1]] = 1;
}

bool estaVisitado(Estado aux){
    return (visitado[aux.coord[0][0]][aux.coord[0][1]][aux.coord[1][0]][aux.coord[1][1]][aux.coord[2][0]][aux.coord[2][1]]);
}

int Busqueda(Estado actual, Estado objetivo, int numCajas){
    queue<Estado>Cola;
    Cola.push(actual);
    visitar(actual);
    while(Cola.size()){
        actual = Cola.front();
        Cola.pop();
        if(llegamosAlObjetivo(actual, objetivo)){
            int total = 0;
            for(int i = 0; i < numCajas; i++)
                total += actual.d[i];
            return total;
        }
        for(int i = 0; i < numCajas; i++){//recorremos todas las cajas
            for(int j = 0; j < 4; j++){//recorremos las casillas adyacentes
                Estado aux = actual;
                aux.d[i]++;
                aux.coord[i][0] += ejex[j];
                aux.coord[i][1] += ejey[j];
                if(esValido(aux.coord[i][0], aux.coord[i][1]))
                    if(!estaVisitado(aux))
                        Cola.push(aux),
                        visitar(aux);
            }
        }
    }
    return -1; //no fue posible, no hay solucion...
}

int main(){

    cin>>N>>M;

    Estado inicial, final;
    // PONEMOS INICIALMENTE CADA CAJA EN UNA PARED (EN EL PROBLEMA SE ESPECIFICA
    // QUE LOS BORDES SON PAREDES), SI EXISTE, SE CAMBIARA LA POSICION,
    // DE LO CONTRARIO, PERMANECERAN AHI...
    for(int i = 0; i < 3; i++)
        inicial.coord[i][0] = N,
        inicial.coord[i][1] = M,
        inicial.d[i] = INFINITY,
        final.coord[i][0] = N,
        final.coord[i][1] = M;

    int numCajas = 0;
    int numObjetivos = 0;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++){
            cin>>mapa[i][j];
            if(mapa[i][j] == 'C')
               inicial.coord[numCajas][0] = i,
               inicial.coord[numCajas][1] = j,
               inicial.d[numCajas++] = 0;
            if(mapa[i][j] == 'O')
               final.coord[numObjetivos][0] = i,
               final.coord[numObjetivos++][1] = j;
        }
    cout<<Busqueda(inicial, final, numCajas)<<endl;
}

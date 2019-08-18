#include <iostream>
#include <string>
#include <algorithm>

#define centro(a, c) a+(c-a)/2

using namespace std;

int N;
int K;

int cables[10005];

bool sePuede(int c){
    int cont = 0;
    for (int j=0; j<N; j++){
        cont += cables[j]/c;
    }
    if (cont >= K){
        return 1;
    }
    return 0;
}
int buscar(int a, int b, int c){
    if(b>=c || b<=a) return b;
    if(sePuede(b)){
        return buscar(b, centro(b, c), c);
    }
    return buscar(a, centro(a, b), b);
}
int main(){

    ios_base::sync_with_stdio();
    cin.tie(0);

    int T;
    int cont;
    int actualDiv;
    int mayDiv = 0;
    int start = 1000000000;
    long long int total =0;

    cin >> T;
    for (int i=0; i<T; i++){
        cin >> N >> K;
        total =0;
        start = 0;
        for (int j=0; j<N; j++){
            cin >> cables[j];
            start = max(cables[j], start);
            total += cables[j];
        }

        if (total < K){
            cout << 0 << '\n';
            continue;
        }

        cout << buscar(1, centro(0, start+2), start+2) << '\n';
    }
    return 0;
}

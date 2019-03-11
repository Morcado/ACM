#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define MAX 400

char mapa[MAX][MAX];
int R = 0, C = 0;
int cont = 0;

pair<int, int> findFinal();

int main() {
    int r, c;
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            char t;
            cin >> t ;
            mapa[i][j] = t;
        }
    }

    pair<int, int> final = findFinal();
	   
    
    //Dijsktra();
    cin >> r >> c;

    int resp = 0;
    cout << resp;
    return 0;
}

/* Busca el final*/
pair<int, int> findFinal() {
	// Columnas
	pair <int, int> p;
	for (int i = 1; i < C - 1; i++) {
		if (mapa[R - 1][i] == 'D' && mapa[R - 2][i] != '#') {
			p.first = R;
			p.second = i;
			return p;
		}
		else {
			if (mapa[0][i] == 'D' && mapa[1][i] != '#') {
				p.first = 0;
				p.second = i;
				return p;
			}
		}
	}
	
	for (int i = 1; i < R - 1; i++) {
		if (mapa[i][C - 1] == 'D' && mapa[i][C - 2] != '#') {
			p.first = i;
			p.second = C;
			return p;
		}
		else {
			if (mapa[i][0] == 'D' && mapa[i][1] != '#') {
				p.first = i;
				p.second = 0;
				return p;
			}
		}
	}

}
/* Implementar el algoritmo de BFS, con prioridad, descartando las D
Ahora solo busca la salida */
#include <bits/stdc++.h>

#define MAX 401
#define x second.first
#define y second.second
#define State pair<int, pair<int, int>>

using namespace std;
//
//struct State {
//	int x;
//	int y;
//	int d;
//
//	bool operator<(const State &o) const {
//		return d > o.d;
//	}
//
//	State(int x, int y, int d) : x(x), y(y), d(d) {}
//};

int R, C;
char mapa[MAX][MAX];
bool visited[MAX][MAX] = {false};

int BFS(int, int);

int main() {
	cin.tie();
	ios_base::sync_with_stdio(false);
	
	int r, c;
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> mapa[i][j];
		}
	}
	
	cin >> r >> c;
	
	cout << BFS(r, c) << endl;
	return 0;
}

int BFS(int r, int c) {
	set<State> q;

	//State s(r - 1, c - 1, 1);
	q.insert({1, {r - 1, c - 1}});
	
	int dy[4] = {0, 0, 1, -1};
	int dx[4] = {1, -1, 0, 0};
	
	while (!q.empty()) {

		pair<int, pair<int, int>> crnt = *q.begin();
		q.erase(crnt);
		
		if (mapa[crnt.x][crnt.y] == 'D' && (crnt.x == R - 1 || crnt.y == C - 1 || crnt.x == 0 || crnt.y == 0)) {
			return crnt.first;
		}
		
		visited[crnt.x][crnt.y] = true;
		
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + crnt.x;
			int ny = dy[i] + crnt.y;
			
			if (nx >= 0 && nx < R && ny >= 0 && ny < C && mapa[nx][ny] != '#' && !visited[nx][ny]) {
				
				if (mapa[nx][ny] == 'D') {
					q.insert({crnt.first, {nx, ny}});
				}
				else {
					q.insert({crnt.first + 1, {nx, ny}});
				}
			}
		}
	}
	
	return -1;
}
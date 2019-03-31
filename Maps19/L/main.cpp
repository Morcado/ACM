#include <bits/stdc++.h>

using namespace std;
#define MAX 101

char mapa[MAX][MAX];
bool visited[MAX][MAX] = {false};
int N;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};


int BFS(pair<int, int> a) {
	
	set<pair<int, pair<int, int>>> q;
	q.insert({0, a});
	
	while (!q.empty()) {
		pair<int, pair<int, int>> curr = *q.begin();
		q.erase(curr);
		
		if (mapa[curr.second.first][curr.second.second] == 'H') {
			return curr.first;
		}
		
		visited[curr.second.first][curr.second.second] = true;
		
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + curr.second.first;
			int ny = dy[i] + curr.second.second;
			
			if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny] && mapa[nx][ny] != 'S') {
				q.insert({curr.first + 1, {nx, ny}});
			}
		}
	}
}


int main() {
	queue<pair<int, int>> spyes;
	int mayor = 0, tr = 0;
	
	cin.tie();
	ios_base::sync_with_stdio(false);
	
	pair<int, int> a;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mapa[i][j];
			if (mapa[i][j] == 'S') {
				spyes.push({i, j});
			}
		}
	}
	
	while (!spyes.empty()) {
		tr = BFS(spyes.front());
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visited[i][j] = false;
			}
		}
		
		spyes.pop();
		if (tr >= mayor) {
			mayor = tr;
		}
	}
	
	cout << mayor << endl;
	
	return 0;
}
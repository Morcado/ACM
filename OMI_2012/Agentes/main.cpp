#include <bits/stdc++.h>

using namespace std;

#define MAX 2001

int area[MAX][MAX];

int main() {
    int N, M;
    queue<pair<int, int>> guards;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char obj;
            cin >> obj;
            if (obj == '#') {
                area[i][j] = -1;
                guards.push({i, j});
            }
            if (obj == 'G') {
                area[i][j] = 0;
                guards.push({i, j});
            }
        }
    }

    int steps = 1;

    while (1) {

        pair<int, int> actual = guards.front();
        int x = actual.first, y = actual.second;
        bool change = false;
        guards.pop();
        //cout << x << " " << y << "\n";
        if (x - 1 > 0 && area[x - 1][y] == 0) {
            area[x - 1][y] = steps;
            guards.push({x - 1, y});
            change = true;
        }
        if (y - 1 > 0 && area[x][y - 1] == 0) {
            area[x][y - 1] = steps;
            guards.push({x, y - 1});
            change = true;
        }
        if (x + 1 < N && area[x + 1][y] == 0) {
            area[x + 1][y] = steps;
            guards.push({x + 1, y});
            change = true;
        }
        if (y + 1 < M && area[x][y + 1] == 0) {
            area[x][y + 1] = steps;
            guards.push({x, y + 1});
            change = true;
        }
        if (change) {
            steps++;
        }
        else {
            break;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << area[i][j] << "  ";
        }
        cout << "\n";
    }

    cout << steps << "\n";
    return 0;
}
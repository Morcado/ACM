#include <bits/stdc++.h>
using namespace std;


int main() {
    int N, M, T, t, r;
    cin >> N >> M >> T >> t >> r;

    if (t > T) {
        cout << "-1\n";
        return 0;
    }
    int cansancioAct = 0, i;

    for (i = 0; i < N; i++) {

        if (cansancioAct + t <= T) {
            cansancioAct += t;
            M--;
        } else {
            cansancioAct -= r;
            if (cansancioAct < 0) {
                cansancioAct = 0;
            }
        }
        if (M == 0) {
            break;
        }
    }
    if (M == 0) {
        cout << i + 1 << "\n";
    }
    else {
        cout << "-1\n";
    }
    return 0;
}
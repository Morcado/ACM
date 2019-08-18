#include <bits/stdc++.h>

using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int initCounter; // valor del limite inicial del contador
    int tests; // numero de casos de prueba
    int visits; // numero de visitas

    cin >> tests;
    while (tests--) {
        int k = 0;
        int sofk = 0;
        int v;
        cin >> initCounter >> visits;

        do {
            k++;
            for (int i = 0; i < k; i++) {
                sofk += i * (i + 1) / 2;
            }
            sofk += k + initCounter;

        } while (sofk <= visits);

        // v = initCounter + 1 - k
    }

    return 0;
}
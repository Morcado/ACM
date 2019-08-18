#include <bits/stdc++.h>

using namespace std;

int main() {
    int cont[5] = {1, 1, 1, 1, 1};
    string a[5];

    cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i != j && a[j].front() == a[i].front()) {
                cont[i]++;
            }
        }
    }

    int mayor = cont[0];
    for (int i = 1; i < 5; i++) {
        if (cont[i] > mayor) {
            mayor = cont[i];
        }
    }

    cout << mayor << endl;
    return 0;
}
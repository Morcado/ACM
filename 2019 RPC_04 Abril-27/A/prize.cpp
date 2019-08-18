#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, X, prod, resp = 0, oldN;
    int cantUnos = 0;

    cin >> n >> X;
    oldN = n;
    if (n > 1) {
        while (n--) {
            cin >> prod;
            if (prod == 1) {
                cantUnos++;
            }
            if (prod * 2 <= X) {
                resp++;
            }
        }
    }
    else {
        cin >> prod;
        resp = 1;
    }

    if (cantUnos >= oldN/2) {
        resp = cantUnos * 2;
    }
    cout << resp << endl;
    return 0;
}
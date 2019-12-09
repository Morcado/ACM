#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    unsigned long cien = a  * b;
    for (int i = 1; i < 10; i++) {
        cout << (unsigned long)ceil((i * 10 * cien) / 100.0);
        if (i < 9) {
            cout << " ";
        }
    }
    cout << "\n";
    return 0;
}
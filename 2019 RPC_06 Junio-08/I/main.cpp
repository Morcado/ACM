#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned long dividendo = 0;
    while (cin >> dividendo) {
        unsigned long divisor = 1;
        unsigned long potenciaDivisor;

        int digitosDivisor = 1;
        if (dividendo % 2 != 0 && dividendo % 5 != 0) {
            do {
                divisor += pow(10, potenciaDivisor++);
                digitosDivisor++;
            } while (divisor % dividendo != 0);
            cout << digitosDivisor << "\n";
        }
        else {
            cout << "-1\n";
        }

    }
    return 0;
}
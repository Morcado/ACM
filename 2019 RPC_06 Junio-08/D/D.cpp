#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned long x, y, n, total, aRestar;


    while (cin >> x >> y) {
        if( x == 0 && y == 0){
            break;
        }
        n = (x + y) - 1;
        total = (n * (n + 1)) / 2;
        aRestar =  0;
        if (n % 2 == 0) {
            aRestar = n -  x;
        }
        else {
            aRestar = n -  y;
        }
        cout << total - aRestar << "\n";
    }
    return 0;
}
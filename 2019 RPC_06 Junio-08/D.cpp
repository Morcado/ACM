#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned long x, y;
    while (cin >> x >> y) {
        if( x == 0 && y == 0)
            break;
        unsigned long n = (x + y) - 1;
        unsigned long total = (n * (n + 1)) / 2;
        unsigned long aRestar =  0;
        if(n % 2 == 0)
            aRestar = n -  x;
        else
            aRestar = n -  y;
        cout << total - aRestar << "\n";
    }
    return 0;
}
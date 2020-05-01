#include <bits/stdc++.h>
using namespace std;

int main() {
    double a, b;
    cin >> a >> b;
    double total = (a * 100);
    double paso = 100.0/b;
    for (double porc = 1.0; porc < 10.0; porc += 1.0) {
        cout << ceil(total * (porc/10) / paso);
        if(porc < 9)
            cout << " ";
    }
    cout << "\n";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    unsigned long cien = a  * b;
    for(int i = 1; i < 10; i++)
    {
        cout << (unsigned long)ceil((i * 10 * cien) / 100.0);
        if(i < 9){
            cout << " ";
        }
    }
    /*double total = (a * 100);
    double paso = 100.0/b;
    for (double porc = 1.0; porc < 10.0; porc += 1.0) {
        cout << ceil(total * (porc/10) / paso);
        if(porc < 9)
            cout << " ";
    }*/
    cout << "\n";
    return 0;
}
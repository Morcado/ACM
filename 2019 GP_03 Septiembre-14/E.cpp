#include <bits/stdc++.h>
using namespace std;

int main() {
    int cantidad;
    int mayor;
    bool roto = false;
    cin >> cantidad;
    cin >> mayor;
    for (int i = 1; i < cantidad; ++i) {
        int num;
        cin >> num;
        if(num > mayor){
            roto = true;
        }
    }
    if(!roto){
        cout << "S" << "\n";
    }
    else{
        cout << "N" << "\n";
    }
    return 0;
}
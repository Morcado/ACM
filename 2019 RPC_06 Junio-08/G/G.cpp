#include <bits/stdc++.h>

using namespace std;

vector<int> factors(int n);

int main() {
    int n;
    vector<int> f = factors(20);
    for (auto a: f) {
        cout << a << " ";
    }
    //cout <<  << endl;
//    while (cin >> n) {
//
//    }
    return 0;
}

vector<int> factors(int n) {
    vector<int> f;
    for (int x = 2; x*x <= n; x++) {
        while (n%x == 0){
            f.push_back(x);
            n /= x;
        }
    }
    if (n > 1) f.push_back(n);
    return f;
}
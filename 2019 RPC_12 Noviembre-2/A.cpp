#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, k;
    cin >> a >> b >> k >> c;
    long resp = 1;
    for (int i = 0; i < k; i++) {
        resp = (resp * 2) % 1000000007;
    }
    for (int i = 0; i < k; i++) {
        resp = resp + resp;
    }
    resp = (resp * k / 2) % 1000000007;
    cout << resp;
    return 0;
}
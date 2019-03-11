#include <bits/stdc++.h>

using namespace std;
using std::setprecision;

int main() {
    double C;
    int L;

    cin >> C >> L;

    double sum = 0;
    for (int i = 0; i < L; i++) {
        double w, l;
        cin >> w >> l;

        sum += w*l*C;
    }

    cout << setprecision(7) << fixed << sum;
    return 0;
}
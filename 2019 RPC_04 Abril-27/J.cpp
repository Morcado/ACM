#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

int main() {
    double s1, s2, s3, s4;

    cin >> s1 >> s2 >> s3 >> s4;

    double sp = (s1 + s2 + s3 + s4)/2.0;
    double resp = sqrt((sp-s1)*(sp-s2)*(sp-s3)*(sp-s4));
    cout << fixed << setprecision(6) << resp << endl;
    return 0;
}
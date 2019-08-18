#include <bits/stdc++.h>

using namespace std;

int main() {


    int tests;
    unsigned long A, B, X, Y, Z;
    cin >> tests;

    while (tests--) {
        cin >> A >> B >> X >> Y >> Z;
        unsigned long area, area1, area2, area3, area4, area5, area6;
        unsigned long altos[6], anchos[6];


        altos[0] = (X + Y);
        anchos[0] = (X + Y + 3*Z);

        altos[1] = (Z + Y);
        anchos[1] = (Z + Y + 3*X);

        altos[2] = (X + Z);
        anchos[2] = (X + Z + 3*Y);

        altos[3] = (X + 2*Y);
        anchos[3] = (Y*2 + 2*Z);

        altos[4] = (Z + 2*Y);
        anchos[4] = (Y*2 + 2*X);

        altos[5] = (X + 2*Z);
        anchos[5] = (2*Z + 2*X);

        for (int i = 0; i < 3; i++) {
            if ((A >= altos[0 + i] && B >= anchos[0 + i]) || (B >= altos[0 + i] && A >= anchos[0 + i])) {
                cout << "POSSIBLE\n";
                break;
            } else {
                if ((A >= altos[3 + i] && B >= anchos[3 + i]) || (B >= altos[3 + i] && A >= anchos[3 + i])) {
                    cout << "POSSIBLE\n";
                    break;
                } else {
                    cout << "IMPOSSIBLE\n";
                    break;
                }
            }
        }
    }
    return 0;
}
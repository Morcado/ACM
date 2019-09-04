#include <bits/stdc++.h>

using namespace std;

unsigned long A, B;

bool CheckType2(int x, int y, int z) {
    if (2*x + 2*y <= A && 2*y + x <= B) {
        return true;
    }
    else {
        if (2*x + 2*y <= B && 2*y + x <= A) {
            return true;
        }
    }
    return false;
}

bool CheckType1(int x, int y, int z) {
    if (z + y <= A && 3*x + y + z <= B) {
        return true;
    }
    else {
        if (z + y <= B && 3*x + y + z <= A) {
            return true;
        }
    }
    return false;
}


int main() {
    int tests;
    unsigned long X, Y, Z, t;
    cin >> tests;

    while (tests--) {
        deque<int> values;
        cin >> A >> B >> X >> Y >> Z;
        values.push_front(X);
        values.push_front(Y);
        values.push_front(Z);

        bool validSize = false;

        for (int i = 0; i < 3; i++) {
            if (CheckType1(values[0], values[1], values[2])) {
                validSize = true;
                break;
            }
            else {
                if (CheckType2(values[0], values[1], values[2])) {
                    validSize = true;
                    break;
                }
            }

            t = values.back();
            values.pop_back();
            values.push_front(t);

        }

        if (validSize) {
            cout << "POSSIBLE\n";
        }
        else {
            cout << "IMPOSSIBLE\n";
        }

//
//        altos[0] = (X + Y);
//        anchos[0] = (X + Y + 3*Z);
//
//        altos[1] = (Z + Y);
//        anchos[1] = (Z + Y + 3*X);
//
//        altos[2] = (X + Z);
//        anchos[2] = (X + Z + 3*Y);
//
//        altos[3] = (X + 2*Y);
//        anchos[3] = (Y*2 + 2*Z);
//
//        altos[4] = (Z + 2*Y);
//        anchos[4] = (Y*2 + 2*X);
//
//        altos[5] = (X + 2*Z);
//        anchos[5] = (2*Z + 2*Y);
//
//        for (int i = 0; i < 3; i++) {
//            if ((A >= altos[0 + i] && B >= anchos[0 + i]) || (B >= altos[0 + i] && A >= anchos[0 + i])) {
//                cout << "POSSIBLE\n";
//                break;
//            }
//            else {
//                if ((A >= altos[3 + i] && B >= anchos[3 + i]) || (B >= altos[3 + i] && A >= anchos[3 + i])) {
//                    cout << "POSSIBLE\n";
//                    break;
//                } else {
//                    cout << "IMPOSSIBLE\n";
//                    break;
//                }
//            }
//        }
    }
    return 0;
}
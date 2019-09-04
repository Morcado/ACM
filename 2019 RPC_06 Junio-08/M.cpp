#include <bits/stdc++.h>

using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tests;
    int tamx, tamy;
    int meteors;
    cin >> tests;

    while (tests--) {
        cin >> tamx >> tamy;
        cin >> meteors;

        int timeLine[1001] = {0};

        while (meteors--) {
            int xi, yi, xf, yf, ti, tf;
            cin >> xi >> yi >> ti >> xf >> yf >> tf;

            for (int i = ti; i < tf + 1; i++) {
                timeLine[i]++;
            }
        }

        int mayor = timeLine[0];
        for (int i = 1; i < 1001; i++) {
            if (timeLine[i] > mayor) {
                mayor = timeLine[i];
            }
        }

        cout << mayor << "\n";
    }



    return 0;
}
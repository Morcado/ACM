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

        auto max = max_element(begin(timeLine), end(timeLine));
        cout << *max << "\n";
    }



    return 0;
}
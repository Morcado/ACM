#include <bits/stdc++.h>
using namespace std;


int main() {
    int casos;
    cin >> casos;
    while(casos --)
    {
        int N;
        int i = 0;
        cin >> N;
        long long r = 10;
        for (i = 0; i < N - 1 && i + 6 < N-1; i = i+6) {
            r *= 531441;
            r = r%(1000000000 + 7);
        }
        for(int j  = i; j < N-1; j++)
        {
            r *= 9;
            r = r%(1000000000 + 7);
        }
        cout << r << "\n";
    }
    return 0;
}
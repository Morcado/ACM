#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int casos;
    cin >> casos;
    while(casos --)
    {
        // int N, r = 10;
        // cin >> N;
        // N--;
        // while (N--) {
        //     r = (r*9)%1000000007;
        // }
        cout << r;
        int N;
        int i = 0;
        cin >> N;
        long long r = 10;


        for (i = 0; i < N - 1 && i + 6 < N - 1; i = i+6) {
            r *= (531441);
            r %= 1000000007;
        }
        for(int j  = i; j < N-1; j++){
            r *= 9;
            r %= 1000000007;
        }
        cout << r << "\n";
    }
    return 0;
}
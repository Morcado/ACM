#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;


int coins[3] = {1, 3, 4};

int solve(int x) {
    if (x < 0){
        return -1;
    }
    if (x == 0) {
        return 0;
    }
    int best = -1;
    for (auto c : coins) {
        best = min(best, solve(x-c)+1);
    }
    return best;
}

int main() {
    cout << solve(19);
    return 0;
}
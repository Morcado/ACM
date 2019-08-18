#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, n, N2

    cin >> N;
    N2 = N;
    int arr[N];
    int sumas[N];

    while (N--) {
        cin >> n;
        arr[n]++;
    }



    for (int i = 0; i < N2; ++i) {
        sumas[i] = arr[i] * (i + 1);
    }

    for (int j = 0; j < N2; ++j) {

        cout << sumas[j] << " ";
    }

    return 0;
}
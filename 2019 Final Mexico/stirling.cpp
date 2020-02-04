#include <iostream>

using namespace std;

#define MAXN 15

int main() {
    int i, j, ans, F = 2, B = 3, N = 4;
    int strl[MAXN][MAXN] = {0};
    int chse[MAXN][MAXN] = {0};

    cout << "Calculo de stirling\n";
    strl[0][0] = 1;
    for (i = 1; i <= N; i++) {
        for (j = 1; j <= i; j++) {

            cout << "strl[" << i << "][" << j << "] = ";
            cout << "strl[" << i - 1 << "][" << j - 1 << "] + ";
            cout << "(" << i - 1 << ") * strl[" << i - 1 << "][" << j << "] = "; 

            cout << strl[i - 1][j - 1] << " + " << (i - 1)  << " * " << strl[i - 1][j] << "\n";
            strl[i][j] = strl[i - 1][j - 1] + (i - 1) * strl[i - 1][j];
        }
        cout << "\n";
    }

    cout << "Tabla de stirling\n";
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cout << strl[i][j] << "\t";
        }
        cout << "\n";
    }

    cout << "\nCalculo de choose\n";
    for (i = 0; i < MAXN; i++) {
        chse[i][0] = chse[i][i] = 1;
        cout << "chse[" << i << "][" << 0 << "] = chse[" << i << "][" << i << "] = 1\n";
        for (j = 1; j < i; j++) {
            chse[i][j] = chse[i - 1][j - 1] + chse[i - 1][j];

            cout << "\tchse[" << i << "][" << j << "] = ";
            cout << "chse[" << i - 1 << "][" << j - 1 << "] + chse[" << i - 1 << "][" << j << "]";

            cout << " = " << chse[i - 1][j - 1] << " + " << chse[i - 1][j] << "\n";
        }
    }

    cout << "\nTabla de choose\n";
    for (i = 0; i < MAXN; i++) {
        for (j = 0; j < MAXN; j++) {
            cout << chse[i][j] << "\t";
        }
        cout << "\n";
    }

    cout << "\nCalculo del resultado\n";
    ans = 0;
    for (i = 0; i < N; i++) {
        int oper = chse[N - 1][i] * strl[i][F - 1] * strl[N - i - 1][B - 1];

        cout << "chse[" << N - 1 << "][" << i << "] * ";
        cout << "strl[" << i << "][" << F - 1 <<"] * ";
        cout << "strl[" << N - i - 1 << "][" << B - 1 << "] = ";

        cout << chse[N - 1][i] << " * " << strl[i][F - 1] << " * " << strl[N - i - 1][B - 1] << " = " << oper << "\n";
        cout << "ans += " << oper << "\n";
        ans += oper;
    }
    cout << "ans = " << ans;
}
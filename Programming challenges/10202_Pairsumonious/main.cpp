#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> checkNumbers (vector<int> B, int n, int intent) {
    vector<int> A;
    A.push_back(intent);
    vector<int>::iterator it;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i - 2; j++) {
            it = find(B.begin(), B.end(), A[j] + A[i - 1]);
            if (it != B.end()) {
                B.erase(it);
            }
            else {
                return A;
            }

        }
        A.push_back(B.front() - A.front());
    }
    return A;
}

int main(){
    int n;
    vector<int> B, A, ax;
    vector<int>::iterator it;
    // Read numbers
    while (scanf("%d", &n) == 1) {
        int aux;
        // Formula
        for (int i = 0; i < n * (n - 1) / 2; i++) {
            scanf("%d", &aux);
            B.push_back(aux);
        }
        cout << "Ordenando" << endl;
        sort(B.begin(), B.end());
        // Ordenar

        // Encontrar A[0];
        aux = 0;
        for (int i = 1; i < B[0]/2 - 1; i++) {
            cout << "Checando..." << endl;
            A = checkNumbers(B, n, i);
            if (A.size() == (unsigned)n) {
                for (it = A.begin(); it != A.end(); ++it) {
                    cout << *it << " ";
                }

                cout << endl;
                A.clear();
                break;
            }
            else {
                cout << "Impossible";
            }
            aux++;
        }
        cout << "Checado" << endl;
    }
    return 0;
}



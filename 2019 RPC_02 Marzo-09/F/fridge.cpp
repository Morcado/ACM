#include <bits/stdc++.h>
#include <string>
using namespace std;

int main() {
    string numeros, res;
    getline(cin, numeros);
    istringstream iss(numeros);

    int menor, mayor, indiceMenor;
    int digitos[10] = {0};
    char c;
    while (iss >> c) {
        int digito = c - 48;
        digitos[digito]++;
    }

    for (int j = 1; j < 10; ++j) {
        if (digitos[j] == 0){
            res = j + 48;
            break;
        }
    }
    mayor = menor = digitos[9], indiceMenor = 9;

    int i, j;

    if (res.empty()) {
        for (i = 9; i >= 1; i--) {
            if (digitos[i] <= menor) {
                menor = digitos[i];
                indiceMenor = i;
            }
            if (digitos[i] >= mayor) {
                mayor = digitos[i];
            }
        }
        //0112233445566778899
        if (mayor == menor && digitos[0] == 0) {
        	res = "10";
        }
        else {
			if (digitos[0] == menor) {
				for (j = 0; j < digitos[indiceMenor] + 1; j++) {
					res += to_string(indiceMenor);
				}
			}
			else {
				if (digitos[0] < menor) {
					res += to_string(indiceMenor);
					for (int j = 0; j < digitos[0] + 1; j++) {
						res += "0";
					}
				}
				else {
					for (j = 0; j < digitos[indiceMenor] + 1; j++) {
						res += to_string(indiceMenor);
					}
				}
			}
			
		}
	}
	for (char re : res) {
        cout << re;
    }
    cout << endl;
    return 0;
}
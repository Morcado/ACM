#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int T;
	int N;
	cin >> T;
	int cont2 = 1;
	while (T--) {
		cin >> N;
		int cont = 1;
		bool correct = true;
		bool found = false;
		N -= 1;
		// cout << "caso " << T; 

		while (!found) {
			string scont = to_string(cont);
			string sN = to_string(N);
			// cout << N << " " << scont << " ";

			for (int i = 0; i < sN.length(); i++) {
				if (sN[i] == '4') {
					correct = false;
					break;
				}
			}
			if (correct) {
				for (int i = 0; i < scont.length(); i++) {
					if (scont[i] == '4') {
					correct = false;
					break;
					}
				}
			}

			if (correct) {
				found = true;
				cout << "Case #" << cont2 << ": " << N << " " << scont<< endl;
				cont2++;
			}
			else {
				correct = true;
			}
			cont++;
			N -= 1;
		}

	}
	return 0;
}
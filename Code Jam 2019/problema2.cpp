#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int T;
	int N;
	int cont2 = 1;
	string a, b;
	cin >> T;

	while (T--) {
		cin >> N;
		cin.ignore();
		cin >> a;

		cout << "Case #" << cont2++ << ": ";
		for (int i = 0; i < 2*N - 2; i++) {
			if (a[i] == 'S') {
				cout << 'E';
			}
			else {
				cout << 'S';
			}
		}
		cout << endl;

	}
	return 0;
}
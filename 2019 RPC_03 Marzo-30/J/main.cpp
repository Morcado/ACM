#include <bits/stdc++.h>

using namespace std;

int main() {
	double n, s, tk, mayor = 1;
	
	cin >> n >> s;
	for (int i = 0; i < n; ++i) {
		cin >> tk;
		if (tk > mayor) {
			mayor = tk;
		}
	}
	
	double res = ceil(mayor*s/1000.0);
	cout << (int)res << endl;
	return 0;
}
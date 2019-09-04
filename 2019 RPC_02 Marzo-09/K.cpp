#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;


double fact(int i){
	if (i == 0) {
		return 1;
	}
	else {
		return i * fact(i - 1);
	}
}

int main() {
	int n, sign = 1;
	double res = 0;
	cin >> n;
	if (n < 20) {
		for (int i = 0; i < n; i++) {
			res += 1 / fact(i + 1) * sign;
			sign = -sign;
		}
	}
	else {
		res = 1 - 1/M_E;
	}
	cout << fixed << setprecision(8) << res << endl;
	return 0;
}
//31 = 0.63212056
//32 = 0.63212056
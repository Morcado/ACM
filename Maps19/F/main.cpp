#include <bits/stdc++.h>

#define _USE_MATH_DEFINES

using namespace std;


int main() {
	int T;
	int n, r;
	cin >> T;
	while (T--) {
		double resp = 0;
		int tms = 4;
		cin >> r >> n;
		double rad = r;
		
		for (int i = 0; i < n - 1; i++) {
			rad = rad/(double)2;
			resp += M_PI*pow(rad, 2) * (double)tms;
			tms *= 3;
			
		}
		
		resp += M_PI*pow(r, 2);
		cout << setprecision(8) << fixed << resp;
	}
	//125663.7061436
	//125663.7061436
	//125663.70614359
	return 0;
}
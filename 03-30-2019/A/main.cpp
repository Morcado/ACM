#include <bits/stdc++.h>
using namespace std;

int main() {
	int k;
	cin >> k;
	int contbien = 0;
	vector<char> a, b;
	cin.ignore();
	string resp1, resp2;
	
	cin >> resp1 >> resp2;
	
	if (k < resp1.length() && k != 0) {
		
		for (int i = 0; i < resp1.length(); i++) {
			a.push_back(resp1[i]);
			b.push_back(resp2[i]);
		}
		
		int variable = resp1.length();
		
		
		for (int i = 0; i < variable && contbien < resp1.length() - k; i++) {
			if (a[i] != b[i]) {
				a.erase(a.begin() + i);
				b.erase(b.begin() + i);
				i--;
				contbien++;
				variable--;
			}
			
		}
		
		int contbien2 = contbien;
		
		for (int i = 0; i < a.size() && contbien < contbien2 + k; i++) {
			if (a[i] == b[i]) {
				contbien++;
			}
		}
	}
	else
	{
		if (k == 0){
			for (int i = 0; i < resp1.length(); ++i) {
				if (resp1[i] != resp2[i]) {
					contbien++;
				}
			}
		}
		else {
			
			for (int i = 0; i < resp1.length(); ++i) {
				if (resp1[i] == resp2[i]) {
					contbien++;
				}
			}
		}
	}
	
	cout << contbien << endl;
	return 0;
}
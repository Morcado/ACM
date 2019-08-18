#include <bits/stdc++.h>

using namespace std;

bool criba[1000001];
vector<unsigned  int> cribaEntera;
int x;

int primComplemento(int n) {
	for (int i = 0; i < cribaEntera.size(); i++)  {
		if (cribaEntera[i] == n) {
			return i;
		}
		if (cribaEntera[i] > n) {
			return -1;
		}
	}
	return -1;
}

int main() {
	cin>>x;
	for (int i = 2; i <= x; i++) {
		for (int j = 2; i * j <= x; j++) {
			criba[i*j] = true;
		}
	}
	for (int i = 2; i < x; i++) {
		if (!criba[i]) {
			cribaEntera.push_back(i);
		}
	}
	int contador = 0;
	int x2 = cribaEntera.size() - 1, x1 = 0;
	
	while (x >= 4) {
		if (cribaEntera[x2] + cribaEntera[x1] == x) {
			contador++;
			x = cribaEntera[x2] - cribaEntera[x1];
		}
		else {
			if (cribaEntera[x2] + cribaEntera[x1] > x) {
				x2--;
				x1 = 0;
			}
			else {
				x1++;
			}
		}
	}
	cout<<contador<<endl;
	return 0;
}


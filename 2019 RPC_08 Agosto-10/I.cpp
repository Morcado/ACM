#include <bits/stdc++.h>

using namespace std;

int main() {
	int letters[28] = {0};
	string word;
	cin >> word;
	for (int i = 0; i < (int)word.length(); i++) {
		letters[word[i] - 97]++;
	}
	bool odd = false;
	bool even = false;

	for (int i = 0; i < 26; i++) {
		if (letters[i] != 0 && letters[i] % 2 == 0) {
			even = true;
			break;
		}
	}

	for (int i = 0; i < 26; i++) {
		if (letters[i] != 0 && letters[i] % 2 != 0) {
			odd = true;
			break;
		}
	}

	if (even && odd) {
		cout << "2\n";
	}
	else {
		if (even) {
			cout << "0\n";
		}
		else {
			cout << "1\n";
		}
	}

	// auto odd =  find_if(begin(letters), end(letters), [](int j){return j % 2 != 0;});
	// auto even = find_if_not(begin(letters), end(letters), [](int j){return j % 2 != 0;});

	// if (even != end(letters) && odd != end(letters)) {
	// 	cout << "2\n";
	// }
	// else {
	// 	if (even != end(letters)){
	// 		cout << "0\n";
			
	// 	}
	// 	else {
	// 		if (odd != end(letters)) {
	// 			cout << "1\n";
	// 		}
	// 	}
	// }
}	
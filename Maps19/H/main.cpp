#include <bits/stdc++.h>
using namespace std;

int main() {
	string word, alphabet;
	cin >> word >> alphabet;
	int loses = 0;
	for (int i = 0; i < 26; i++) {
		string before = word;
		word.erase(remove(word.begin(), word.end(), alphabet[i]), word.end());
		
		if (word.length() == before.length()) {
			loses++;
		}
		
		if (word.empty()) {
			if (loses < 10) {
				
				cout << "WIN" << endl;
			}
			else {
				cout << "LOSE" << endl;
			}
			break;
		}
		
	}
	
	return 0;
}
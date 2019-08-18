#include <bits/stdc++.h>
#include <sstream>
using namespace std;

int main() {
	int n; // number of words
	bool sense = true, first = false;
	int count = 1, wordCount = 0, n2;
	string spoken;
	cin >> n;
	n2 = n;
	while (n--) {
		int number;
		cin >> spoken;
		stringstream s(spoken);
		if (spoken == "mumble") {
			wordCount++;
		}
		else {
			s >> number;

			if (number != count) {
				sense = false;
				break;
			}
		}

		count++;

 	}

 	if (sense) {
 		cout << "makes sense\n";
 	}
 	else {
 		if (wordCount == n2) {
 			cout << "makes sense\n";
 		}
 		else {
 			cout << "something is fishy\n";
 		}

 	}
}
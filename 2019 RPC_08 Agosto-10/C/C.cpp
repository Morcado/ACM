#include <bits/stdc++.h>

using namespace std;

int main() {
	int dirties;
	int cleanCount;
	vector<int> dirtyDays;
	cin >> dirties;

	while (dirties--) {
		int day; 
		cin >> day;
		dirtyDays.push_back(day);
	}

	for (int i = 0; i < (int)dirtyDays.size() - 1; i++) {
		if (dirtyDays[i + 1] - dirtyDays[i] > 20) {

		}
	}
}
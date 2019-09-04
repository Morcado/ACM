#include <bits/stdc++.h>

using namespace std;

int main() {
	int width, height, gap;
	cin >> width >> height >> gap;
   
	if (gap*2 > width || gap*2 > height) {
		cout << "0\n";
	} 
	else {
		int area = (width-gap*2)*(height-gap*2);
		cout << area << "\n";
	}
}	
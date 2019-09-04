#include <iostream>
#include <math.h>
using namespace std;
#define _USE_MATH_DEFINES

int main() {
	unsigned int area, radio, precio1, precio2;
	cin >> area >> precio1;
	cin >> radio >> precio2;
	
	float areaCompleta = radio*radio*M_PI;
	if (areaCompleta / (double)precio2 < (double)area / (double)precio1) {
	    cout << "Slice of pizza\n";
	}
	else {
	    cout << "Whole pizza\n";
	}
	return 0;
}

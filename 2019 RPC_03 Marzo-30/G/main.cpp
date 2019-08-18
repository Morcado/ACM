#include <bits/stdc++.h>

using namespace std;
using std::setprecision;

int main() {
	double menor = 123456789, mAux;
	double x, y;
	int x1, y1, x2, y2;
	cin >> x >> y >> x1 >> y1 >> x2 >> y2;
	
	for(int i = x1; i <= x2; i++)
	{
		for(int j = y1; j <= y2; j++)
		{
			mAux = sqrt(pow(x - i, 2) + pow(y - j, 2));
			if(mAux < menor)
				menor = mAux;
		}
	}
	
	cout << setprecision(3) << fixed << menor << endl;
	return 0;
}
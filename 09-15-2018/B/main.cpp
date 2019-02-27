#include <iostream>

using namespace std;

int main() {
    int n,  x1, y1, x2, y2;
    cin >> n;
    cin >> x1 >> y1;
    cin >> x2 >> y1;
    if ((x1 < n/2 && x2 > n/2) || (x1 > n/2 && x2 < n/2)) {
        cout << "S";
        return 0;
    }
    if ((y1 < n/2 && y2 > n/2) || (y1 > n/2 && y2 < n/2)) {
        cout << "S";
        return 0;
    }
    else {
        cout << "N";
        return 0;
    }

    return 0;
}

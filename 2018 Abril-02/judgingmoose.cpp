#include <iostream>

using namespace std;

int main(){
    int a, b, r;
    cin >> a >> b;

    if(a == 0 && b == 0){
        cout << "Not a moose" << endl;
    }
    else{
        if(a == b){
            cout << "Even " << a*2 << endl;
        }
        else{
            cout << "Odd " << (a > b ? a*2 : b*2) << endl;
        }
    }
    /* code */
    return 0;
}
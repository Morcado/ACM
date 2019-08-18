#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int convierte(string repunit){
    int res = 0;
    for(int i = repunit.length() - 1; i >= 0; i--){
        res += pow(10, i);
    }
    return res;
}
int main(){
    int n, i, a;
    cin >> n;
    string repunit = "11";
    i = 2;
    while(true){
        int conv = convierte(repunit);
        if(conv%n == 0){
            cout << i;
            cin >> a;
            break;
        }
        else{
            repunit += "1";
            cout << conv << endl;
            i++;
        }
    }
    return 0;
}

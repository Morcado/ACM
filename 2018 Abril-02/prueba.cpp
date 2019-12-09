#include <iostream>
// #include <sstream>
#include <string>
using namespace std;

void resp();

int main(){
    // Convierte string a entero con sstream
    // string a = "1234";
    // stringstream val(a);

    // float x = 0;
    // val >> x;
    // cout << x*2;

    /*Convierte string a entero con stoi*/
    //string a = "1122121";
    //string b = "3322223";

    //cout << stoi(a) + stoi(b);

    /*convierte entero a sting */
    int al;
    string a = to_string(222);
    string res;
    a += "www";
    cout << a;
    resp();
    return 0;
}


void resp() {
    cout << "hola mundo";
}

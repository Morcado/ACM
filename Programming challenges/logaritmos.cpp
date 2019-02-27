#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
    double log210;
    double log2P;
    double log2P1;
    long P;
    long T;
    long N;


    log210 = log2(10);

    cin >> P;
    log2P = log2(P);
    log2P1 = log2(P+1);

    T = floor(log10(P) + 1);

    for(;ceil(log2P + (T * log210)) != floor(log2P1 + (T * log210)); T++)
    {
//        cout << T << endl;
    }
    cout << "me sali del primer for" << endl;
    N = ceil(log2P + T * log210);

    if(to_string((int)pow(2,N)).length() < to_string((int)P).length() * 2 + 1)
    {
        T++;
        for(;ceil(log2P + (T * log210)) != floor(log2P1 + (T * log210)); T++);
        {
 //           cout << T << endl;

        }
        N = ceil(log2P + T * log210);
    }

    cout << N;
    return 0;
}

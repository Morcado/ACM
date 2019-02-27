#include <iostream>
#include <math.h>
#include<iomanip>
using namespace std;

int main()
{
    int gatos;
    cin>>gatos;
    for(int i = 0; i < gatos; i++){
        long long gato;
        cin>>gato;
        cout.setf(ios::fixed);
        cout<<setprecision(0)<<pow(gato, gato+1) - (gato-1)<<endl;
    }
    return 0;
}

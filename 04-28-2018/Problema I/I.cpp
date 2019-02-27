#include<iostream>
#include<string>
#include <math.h>
using namespace std;
int main()
{
    int it;
    cin>>it;
    int* monedas;
    monedas = new int[it];
    for(int i = 0; i< it; i++)
    {
        cin>>monedas[i];
    }
    for(int i = 0; i< it; i++)
    {
        double operacion = (1 + sqrt(1+8*monedas[i])) / 2.0;
        if(operacion - floor(operacion) > 0)
            cout<<-1<<endl;
        else
            cout<<(int) operacion - 1<<endl;
        /*if(suma <= monedas[i])
            cout<<(nivel-1)<<endl;
        else
            cout<<-1<<endl;*/
    }
    return 0;
}

#include<iostream>
#include<math.h>
using namespace std;

int sobrante = 1;

int primerFactor(){

}

int main()
{
    float* numeros;
    int* potencias;
    int k;
    int temp;
    long double total = 1;


    cin>>k;

    numeros = new float[k];
    potencias = new int[k];

    for(int i = 0 ; i < k ;i++)
    {
        cin >> numeros[i];
        cin >> potencias[i];
        int pTmp = potencias[i];
        while (pTmp >= 2){
            pTmp -= 2;
            sobrante *= numeros[i];
        }
        total *= pow(numeros[i],potencias[i]);
    }
    int c1 = pow(sobrante, 2);
    int c22 = total-sobrante;
    float c2 = sqrt(c22);
    if(c2 - floor(c2) > 0){
        cout << "No.";
    }
    else {
        cout << "Yes.";
    }
    //cout<<total;
    return 1;
}

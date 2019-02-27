#include <iostream>
#include <string>
#include <math.h>
using namespace std;
long long int factorial(int n){
        if(n == 0)
            return 1;
        return n*factorial(n-1);
}
int main(){
    int numero;
    cin>>numero;
    int captura[numero];
    for(int i = 0; i < numero; i++){
        int entero;
        cin>>entero;
        captura[i] = entero;
    }
    for(int i = 0; i < numero; i++){
        string cad = to_string(captura[i]);
        int n = cad.length();
        string digitos = "";
        for(int j = 0; j < cad.length(); j++){
            if(digitos.find_first_of(cad[j]))
                digitos+=cad[j];
        }
        int r = digitos.length();
        long long int permutacion = factorial(n)/(factorial(n-r)*factorial(n));
        double factor = permutacion*1.0/cad.length();
        int primerSuma = 0;
        for(int j = 0; j < cad.length(); j++)
            primerSuma += cad[j] - 48;
        int sumaDigitos = primerSuma * factor;
        int sumaTotal = 0;
        string temporal = to_string(sumaDigitos);
        for(int j = 0; j < cad.length(); j++){
            sumaTotal += stoi(temporal);
            temporal += "0";
        }
        cout<<permutacion<<" "<<sumaTotal<<endl;
    }
    return 0;
}

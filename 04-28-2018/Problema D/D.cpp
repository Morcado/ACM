#include<iostream>
#include<math.h>
#include <string>
#include <queue>
using namespace std;

string obtenBinario(char c){
    string cad = "";
    switch(c){
        case '0':
        cad = "0000";
        break;
        case '1':
        cad = "0001";
        break;
        case '2':
        cad = "0010";
        break;
        case '3':
        cad = "0011";
        break;
        case '4':
        cad = "0100";
        break;
        case '5':
        cad = "0101";
        break;
        case '6':
        cad = "0110";
        break;
        case '7':
        cad = "0111";
        break;
        case '8':
        cad = "1000";
        break;
        case '9':
        cad = "1001";
        break;
        case 'A':
        cad = "1010";
        break;
        case 'B':
        cad = "1011";
        break;
        case 'C':
        cad = "1100";
        break;
        case 'D':
        cad = "1101";
        break;
        case 'E':
        cad = "1110";
        break;
        case 'F':
        cad = "1111";
        break;
    }
    return cad;
}
int main(){
    queue<string> cola;
    string hex;
    while(cin>>hex){
        cola.push(hex);
    }
    while(!cola.empty()){
        long long int numero = 0;
        string numHex = cola.front(), binario = "";
        cola.pop();
        for(int i = 0; i < numHex.length(); i++){
            binario += obtenBinario(numHex[i]);
        }
        int index = 0;
        for(int j = binario.length()-1; j >= 0; j--){
            if(binario[j] == '1')
                numero += pow(2, index);
            index++;
        }
        // string diecisiete = "17", divisor = "";
        // divisor += obtenBinario(diecisiete[1]) += obtenBinario(diecisiete[0]);
        // int numero2 = 0;
        // for(int j = divisor.length()-1; j >= 0; j--){
        //     if(divisor[j] == '1')
        //         numero2 += pow(2, index);
        //     index++;
        // }
        if(numero%17 == 0)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;

}


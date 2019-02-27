#include <iostream>
#include <queue>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int generaEntero(string cad){
    int num = 0;
    for(int i = 0; i < cad.size(); i++){
        //cout<<cad[i]-48;
        num += cad[i]-48;
    }
    cout<<num;
}
int main(){
    queue<string> a;
    int n;
    string cad;
    /*do{
        cin>>cad;
        if(n != 0)
            a.push(cad);
        else
            break;
    }while(true);*/
    cout<<generaEntero("123");
}


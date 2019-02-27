#include <iostream>
#include<string>
#include <queue>
using namespace std;
void leeCadenas(string cadenas[], int tam){
    string temp;
    for(int i = 0; i < tam; i++){
        getline(cin, temp);
        cadenas[i] = temp;
    }
}
string codifica(string cad, int avance){
    for(int i = 0; i < cad.size(); i++)
        if(cad[i]>=65 && cad[i]<=90){
            if(cad[i] + avance > 90)
                cad[i] = 64 + (avance - (90 - cad[i]));
            else
                cad[i] += avance;
        }
    return cad;
}
int main()
{
    int casos, n, k;
    queue<string> cadenas;
    queue<queue<string>> mensaje;
    cin>>casos;
    for(int i = 0; i < casos; i++){
        cin>>n>>k;
        string cadens;
        for(int j = 0; j < n ; j++){
            fflush(stdin);
            getline(cin, cadens);
            if(k <= 26)
                cadenas.push(codifica(cadens, k));
            else{
                cadenas.push(codifica(cadens, k%26));
            }
        }
        mensaje.push(cadenas);
        while(!cadenas.empty())
            cadenas.pop();
    }
    while(!mensaje.empty()){
        while(!mensaje.front().empty()){
            cout<<mensaje.front().front();
            mensaje.front().pop();
            cout<<"\n";
        }
        mensaje.pop();
    }
    return 0;
}

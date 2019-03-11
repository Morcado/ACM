#include <bits/stdc++.h>

using namespace std;
bool comparaPalabraConFrase(string palabra, string frase);
void verificaFrase(string palabra, vector<string> palabrasQueRiman, string frase);
void verificaFrases(string palabra, vector<string> palabrasQueRiman, vector<string> frases);
vector<string> obtenPalabras(string linea){
    vector<string> palabras;
    while(linea.find(' ') != string::npos){
        string palabra = linea.substr(0, linea.find(' '));
        linea = linea.substr(linea.find(' ') + 1);
        palabras.push_back(palabra);
    }
    palabras.push_back(linea);
    return palabras;
}
void verificaFrases(string palabra, vector<string> palabrasQueRiman, vector<string> frases){
    for(int i = 0; i < frases.size(); i++){
        verificaFrase(palabra, palabrasQueRiman, frases[i]);
    }
}
void verificaFrase(string palabra, vector<string> palabrasQueRiman, string frase){
    if(comparaPalabraConFrase(palabra, frase)){
        cout<<"YES"<<endl;
        return;
    }
    else{
        for(int i = 0; i < palabrasQueRiman.size(); i++){
            if(comparaPalabraConFrase(palabrasQueRiman[i], frase)){
                cout<<"YES"<<endl;
                return;
            }
        }
        cout<<"NO"<<endl;
    }

}
bool comparaPalabraConFrase(string palabra, string frase){
    unsigned long indice = frase.rfind(palabra);
    if(indice == string::npos){
        return false;
    }
    else{
        if(indice == frase.length()- palabra.length()){
            return true;
        }
    }
    return false;
}
int main() {
    string palabra;
    getline(cin, palabra);
    int numPalabras, numFrases;
    cin>>numPalabras;
    cin.ignore();
    vector<string> palabrasQueRiman, frases;
    for(int i = 0; i < numPalabras; i++){
        string s;

        getline(cin, s);
        vector<string> p = obtenPalabras(s);
        for(int j = 0; j < p.size(); j++){
            palabrasQueRiman.push_back(p[j]);
        }

    }
    cin>>numFrases;
    for(int i = 0; i < numFrases; i++){
        string s;
        cin.ignore();
        getline(cin, s);
        frases.push_back(s);
    }
    verificaFrases(palabra, palabrasQueRiman, frases);
    return 0;
}
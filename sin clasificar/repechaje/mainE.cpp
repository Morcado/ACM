#include <bits/stdc++.h>
using namespace std;

int n;
//set<string> prejifos;
//set<string> palabras;
bool trie[100][36] = {false};

//bool buscaPrefijos(string palabra) {
//
//    for(set<string>::iterator i = palabras.begin(); i != palabras.end(); ++i) {
//        if(palabra.length() == i -> length() || palabra.length() < i -> length()){
//            continue;
//        }
//        if(palabra.find_first_of(*i) == 0){
//            return false;
//        }
//    }
//    return true;
//}

/*
6
 ae
a
ar
aea
aee
art

 *
 * */
int main() {
    vector<string> palabras;
    int contador = 0;
    cin >> n;
    cin.ignore();
    while (n--) {
        string palabra;
        cin >> palabra;
        palabras.push_back(palabra);
    }
    sort(begin(palabras), end(palabras), [](string n, string m){return n.length() > m.length();});
    for (string palabra : palabras) {
        bool funciona = true;
        for (int i = 0; i < palabra.length() - 1; i++) {
            if(trie[i][palabra[i]-97]) {
                funciona &= true;
            }
            else {
                funciona &= false
            }
            trie[i][palabra[i] - 97] = true;
        }
//        if (!trie[palabra.length() - 1][palabra[palabra.length() - 1] - 97]) {
//            contador++;
//            trie[palabra.length() - 1][palabra[palabra.length() - 1] - 97] = true;
//        }
    }
//    for (int i = 0; i < palabras.size(); i++) {
//        for (int j = 0; j < palabras[i].length() - 1; j++) {
//
//            trie[j][palabras[i][j] - 97] = true;
//        }
//        if (!trie[palabras[i].length() - 1][palabras[palabras[i].length() - 1] - 97]) {
//            contador++;
//            trie[palabra.length() - 1][palabra[palabra.length() - 1] - 97] = true;
//        }
//    }

    cout<<contador << "\n";
    return 0;
}
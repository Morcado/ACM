#include <bits/stdc++.h>

using namespace std;

bool checkRhyme(const string &firstWord, const string &secondWord, vector<string> words[], const int &E);

int main() {
	string sWord, eWord, phrase;
	
	int E, P;
	cin >> sWord;	// Palabra S a comparar
	cin >> E;	// Numero de lineas con palabras
	
	vector<string> words[E]; // palabras de referencia
	vector<string> phrases; // frases a verificar
	cin.ignore();
	
	for (int i = 0; i < E; i++) {
		getline(cin, eWord);
		istringstream stream(eWord);
		
		string c;
		// Guarda cada palabra en un vector
		while (stream >> c){
			words[i].push_back(c);
		}
	}
	cin >> P;	// Numero de oraciones
	cin.ignore();
	
	for (int j = 0; j < P; j++) {
		getline(cin, phrase);
		istringstream stream(phrase);
		string c, last;
		while  (stream >> c) {		// Guarda la ultima palabra en un vector
			last = c;
		}
		phrases.push_back(last);
	}
	
	for (const auto &ph : phrases) {
		bool belong = checkRhyme(sWord, ph, words, E);
		if (belong) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}

bool checkRhyme(const string &firstWord, const string &secondWord, vector<string> words[], const int &E){
	// Checa las dos palabras en el i conjunto de palabras que riman
	unsigned long indice;
	// Recorre cada conjunto de palabras que riman
	for (int i = 0; i < E; i++) {
		bool rhym1 = false, rhym2 = false;
		// Recorre cada palabra del conjunto
		for (const auto &w : words[i]) {
			int k, l;
			
			for (k = static_cast<int>(firstWord.length() - 1), l = static_cast<int>(w.length() - 1); l >= 0 && firstWord[k] == w[l] && k >= 0; k--, l--);
			if (l == -1) {
				rhym1 = true;
			}
			for (k = static_cast<int>(secondWord.length() - 1), l = static_cast<int>(w.length() - 1); secondWord[k] == w[l] && l >= 0 && k >= 0; k--, l--);
			if (l == -1) {
				rhym2 = true;
			}
		}
		if (rhym1 && rhym2) {
			return true;
		}
	}
	
	return false;
}
#include <iostream>
#include <set>
#include <iterator>
#include <vector>

using namespace std;

void CreateStates(const set<int> &states){

}

int main() {
	int t, n, m, s, k;
	set<char> gram;
	vector<int> accepted;
	vector<set<int>> states;
	
	cin >> t;
	while (t--) {
		cin >> n >> m >> s >> k;
		
		// Obtener s caracteres el alfabeto
		for (int i = 0; i < s; i++) {
			char letter;
			cin >> letter;
			gram.insert(letter);
		}
		
		// Estados de aceptación
		for (int i = 0; i < k; i++) {
			int accept;
			cin >> accept;
		}
		
		// Transiciones
		for (int i = 0; i < m; i++) {
			int x, y;
			char c;
			cin >> x >> y >> c;
			// Si no esta
			if (gram.find(c) == gram.end()) {
				continue;
			}
			
		}
		
		int q;
		cin >> q;
		
		CreateStates(states);
		//Move();
		
		// Oraciones
		
		for (int i = 0; i < q; i++) {
			string word;
			cin >> word;
			
			// Probar
			
		}
		
	}
	
	
	return 0;
}
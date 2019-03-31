#include <bits/stdc++.h>

using namespace std;


vector<int> panStack;

//indice, valor
pair<int, int> GetLargest(int start){
	pair<int, int> mayor;
	mayor.first = start;
	mayor.second = panStack[start];
	
	
	for (int i = start; i < panStack.size(); i++) {
		if (panStack[i] > mayor.second) {
			mayor.first = i;
			mayor.second = panStack[i];
		}
		
	}
	return mayor;
}


int main() {
	string pancakes;
	
	while (getline(cin, pancakes)) {
		istringstream stream(pancakes);
		int c;
		
		while (stream >> c){
			panStack.push_back(c);
		}
		
		vector<int> vec(panStack);
		sort(vec.begin(), vec.end());
		reverse(vec.begin(), vec.end());
//		int mayor = panStack[0];
//		int indiceMayor = 0;
//
//
//		for (int i = 0; i < panStack.size(); i++) {
//			if (panStack[i] > mayor) {
//				mayor = panStack[i];
//				indiceMayor = i;
//			}
//
//		}
		
		int cont = 0, i = panStack.size();
		while (!equal(panStack.begin(), panStack.end(), vec.begin()) && i-- != 0) {
			
			pair<int, int> start = GetLargest(cont);
			
			// Pasarlo hasta arriba
			reverse(panStack.begin() + start.first, panStack.end());
			
			
//			if (equal(panStack.begin(), panStack.end(), vec.begin())) {
//				cout << panStack.size() - (start.first + 1) << " ";
//				break;
//			}
//
//
			// Pasarlo hasta abajo
			reverse(panStack.begin() + cont, panStack.end());
			cont++;
			cout << (start.first + 1) << " ";
		}
		//reverse(panStack.begin(), panStack.end());
		cout << 0 << endl;
		
		int a;
		
	}
	
	return 0;
}

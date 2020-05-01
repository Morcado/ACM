#include <bits/stdc++.h>
using namespace std;

int n, j, suma = 0, sumaJiren = 0, sumaTotal;
vector<int> Jiren, Ricardo, Sarai, mejores, temp;

int getMejor(int i){
    int mejor = Jiren[i];
    if(Ricardo[i] > mejor){
        mejor = Ricardo[i];
    }
    if(Sarai[i] > mejor){
        mejor = Sarai[i];
    }
    if(mejor == Jiren[i]){
        j--;
    }
    return mejor;
}

void imprime(int suma, int sumaTotal){
    if(sumaTotal >= suma){
        cout << sumaTotal << '\n';
    }
    else{
        cout << "Don't do it buddy" << '\n';
    }
}

int main() {
    cin>>n >> j;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < n; j++){
            int num;
            switch(i){
                case 0:
                    cin >> num;
                    suma += num;
                    break;
                case 1:
                    cin >> num;
                    sumaJiren += num;
                    Jiren.push_back(num);
                    break;
                case 2:
                    cin >> num;
                    Ricardo.push_back(num);
                    break;
                case 3:
                    cin >> num;
                    Sarai.push_back(num);
                    break;
            }
        }
    }
    if(j == n){
        imprime(suma, sumaJiren);
    }else{
        for(int i = 0; i < n; i++){
            int num = getMejor(i);
            mejores.push_back(num);
            temp.push_back(num);
            sumaTotal += num;
        }
        sort(temp.begin(), temp.end());
        for(int i = 0; i < n; i++){
            if(j == 0){
                break;
            }
            vector<int>::iterator it = find(mejores.begin(), mejores.end(), temp[i]);
            int index = distance(mejores.begin(), it);
            if(Jiren[index] == temp[i]){
                continue;
            }
            sumaTotal -= mejores[index];
            sumaTotal += Jiren[index];
            j--;
        }
        imprime(suma, sumaTotal);
    }
    return 0;
}

/*
4 1
1 2 3 4
5 1 1 1
1 1 1 1
1 2 2 2

4 3
1 2 3 4
5 1 1 1
1 4 2 1
1 3 3 1

1 1
10
9
8
7
 */
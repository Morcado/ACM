#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

bool mayor (pair<int, int> p1, pair<int, int> p2) {
    if (p1.first > p2.first) {
        return true;
    }
    if (p1.first == p2.first) {
        return p1.second > p2.second;
    }
    return false;


}
int main() {
    int pares, pares2;
    int heroeInd = 0, villIndice = 0;
    vector<pair<int, int>> combates;

    cin >> pares;
    pares2 = pares;
    for (int i = 0; i < pares; i++) {
        pair<int, int> batalla;
        int h;
        cin >> h;
        batalla.first = h;
        combates.push_back(batalla);
    }
    for (int i = 0; i < pares; i++) {
        int h;
        cin >> h;
        combates[i].second = h;
    }
    int dias = 0;
    sort(begin(combates), end(combates), mayor);
    int heroeMamadisimo = combates[0].first;
    while(!combates.empty()){
        for (int i = 0; i < combates.size(); i++) {
            if(combates[i].first >= combates[i].second || heroeMamadisimo >= combates[i].second){
                combates.erase(combates.begin() + i);
                break;
            }
            else{
                dias += combates[i].second - heroeMamadisimo;
                heroeMamadisimo += dias;
            }
            for(int j = i; j < combates.size(); j++){
                combates[j].first += dias;
            }
        }
    }
    cout<<dias<<"\n";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<pair<int, int>> puntos; // Se guardan los puntos, convertidos en positivo
    vector<pair<int, pair<float, float>>> angulos_validos;
    int n; // Numero de puntos
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        if (x > 0 && y > 0) {
            puntos.push_back({x, y});
        }
        else if (x < 0 && y < 0) {
                puntos.push_back({-x, -y});
            
            else {
                if (x > 0 && y < 0) {
                    puntos.push_back({-y, x});
                }
                else {
                    puntos.push_back({y, -x});
                }
            }
        }

    }
    
    for (int i = 0; i < n; i++) {
        cout << puntos[i].first << " " << puntos[i].second << "\n";
    }
    return 0;
}
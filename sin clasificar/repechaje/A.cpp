#include <bits/stdc++.h>
using namespace std;

int ncarr, querys, s;
vector<int> carros = {0};

int busca(int q) {


    int moviemientos = 0;
    int pos = 0;
    while(carros[pos] < q && pos < carros.size() - 1){
        pos += s;
        moviemientos++;
    }
    if (carros[pos] == q) {
        return moviemientos;
    }
    pos-=s;
    moviemientos++;
    while (carros[pos] < q && pos < carros.size() - 1) {
        pos++;
        moviemientos++;
    }
    if (carros[pos] == q) {
        return moviemientos;
    }
            return -1;



}

int main() {
    cin >> ncarr >> querys;
    s = (int)sqrt(ncarr);
    for (int i = 0; i < ncarr; ++i) {
        int c;
        cin >> c;
        carros.push_back(c);
    }
    for (int i = 0; i < querys; ++i) {
        int q;
        cin >> q;
        cout << busca(q) << "\n";
    }
    return 0;
}

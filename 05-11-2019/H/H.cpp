#include <bits/stdc++.h>

using namespace std;

int main() {
    int casos;
    int max = 0;
    int n;
    vector<int> v;
    cin >> casos;
    while(casos--)
    {
        cin >> n;
        v.push_back(n);
        max += n;
    }
    sort(v.begin(), v.end());

    if(v[0] != 1)
    {
        cout << "1\n";
        return 0;
    } else{
        max = v[0];
        for (int j = 1; j < v.size(); ++j) {

            if(j+1 < v.size() && v[j] <= max +1)
            {
                max += v[j];
            } else
            {
                cout << max+1 << "\n";
                return 0;
            }

        }
    }
    return 0;
}

/*int buscado = j;
if(numeros[j] == 0)
{
if(j != 1)
{
for(int k = v.size() - 1; k >= 0; k--)
{
if(v[k] <= buscado)
{
buscado -= v[k];
if(buscado == 0) {
numeros[j] += 1;
break;
}
}
}
if(buscado > 0) {
cout << buscado << "\n";
return 0;
}
}
else {
cout << j << "\n";
return 0;
}
}*/
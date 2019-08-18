#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int casos;
    cin >> casos;
    int casos2 = casos;
    int numeros[casos];
    int resultado[1000000];
    int i = 0;

    while(casos2--){
        int num;
        cin >> num;
        numeros[i++] = num;
        resultado[num - 1] = (num / 5) ;
        if(num % 5 != 0){
            resultado[num - 1]++;
        }
    }

    int ayuda;
    cin >> ayuda;
    i = 0;
    
    while(ayuda --){
        int num;
        cin >> num;
        cout << resultado[numeros[num - 1] - 1] << "\n";
    }
    return 0;
}
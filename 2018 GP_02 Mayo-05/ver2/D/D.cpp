#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

string numero;

bool divide(string divisor){
    string numNow = numero;
    numNow = '0' + numNow;

    cout << numNow << " " << divisor << endl;
    if (numNow.size() < divisor.size())
        return false;

    int tam = numNow.size();
    int porSumar = 0;

    int fin = numNow.size()-divisor.size();
    for (int i=0; i < fin; i++)
        divisor = "0" + divisor;

    int porRestar = divisor.size() - 1;

    for (int i=tam-1; i>=0; i--){
        // Si el numero ya es cero
        cout << "# " << numNow << endl;
        bool ceros = true;
        for (int j=0; j<numNow.size(); j++){
            if (numNow[j] != '0') ceros = false;
        }
        if (ceros) return true;

        int a = numNow[i] - '0';
        int b = divisor[porRestar] - '0';
        int c = a-(b+porSumar);
        cout << "$ " << a << " " << b << " ";


        if (b > a) c+=10, porSumar = 1;
        else porSumar = 0;
    cout << c << endl;
    system("pause>>null");
        c += '0';
        numNow[i] = c;
        porRestar--;
    }
    return false;
}

int main(){
    int T;
    //long long int N;
    string numCad;

    cin >> T;

    for (int i=0; i<T; i++){
        cin >> numCad;
        bool found = false;
        numero.clear();
        for(int j = 1; j < 20; j++)
        {
            numero.push_back('1');
            if(divide(numCad))
            {
                cout << j + 1 << "\n";
                found = true;
                break;
            }
        }
        if(found == false)
            cout << -1 << "\n";
    }
    return 0;
}

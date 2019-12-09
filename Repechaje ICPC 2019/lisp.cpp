#include <bits/stdc++.h>
using namespace std;

string LispToInfix(string linea) {
    stack<string> operadores, operandos;
    char anterior = ' ', actual = ' ';

    for (int i = 0; i < linea.length(); i++) {
        // Si encuentra un signo
        if (linea[i] == '+' || linea[i] == '*') {
            anterior = operadores.top();
            actual = linea[i];
            string an(linea[i]);
            operadores.push(an);
        }
        else {
            // Si va de salida, entonces se sacan todos hasta que haya otro signo
            if (linea[i] == ')') {
                string parte = "";
                
                char tope = operadores.top();

                while(tope != "(") {
                    tope = operadores.top();
                    parte += tope;
                    parte += to_string(actual);
                    operadores.pop();
                }
                parte = parte.substr(0, parte.length() - 1);
                reverse(begin(parte), end(parte));

                if (operadores.size() >= 2) {
                    actual = anterior;
                    string t = operadores.top();
                    operadores.pop();
                    anterior = operadores.top();
                    operadores.push(t);
                }
                if (anterior == "*" && actual == "+") {
                    parte = "(" + parte + ")";
                }
                // actual = anterior;

                // operadores.pop();
                // anterior = operadores.top();
                // operandos.push(parte);
            }
            else {
                string an(linea[i]);
                operandos.push(to_string(an));
            }
        }
    }
    return operandos.top();
}

int main(){
    int casos; // numero de casos de prueba
    cin >> casos;
    cin.ignore();
    while (casos--) {
        string linea;
        cin >> linea;
        cout << LispToInfix(linea) << "\n";
    }
    cout << "final";
    return 0;
}
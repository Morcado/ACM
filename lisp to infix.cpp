#include <bits/stdc++.h>
using namespace std;


string LispToInfix(string linea) {
    stack<string> operadores;
    stack<string> operandos;
    string anterior = " ", actual = " ";

    for (int i = 0; i < linea.length(); i++) {
        // Si encuentra un signo
        if (linea[i] == '+' || linea[i] == '*') {
            if (!operadores.empty()) {
                anterior = operadores.top();
            }
            string ahe(1, linea[i]);
            actual = ahe;
            operadores.push(ahe);

        }
        else {
            // Si va de salida, entonces se sacan todos hasta que haya otro signo
            if (linea[i] == ')') {
                string parte;

                string tope = operandos.top();
                operandos.pop();
                while(tope != "(" && !operandos.empty()) {
                    parte += tope;
                    parte += actual;
                    tope = operandos.top();
                    operandos.pop();
                }
                parte = parte.substr(0, parte.length() - 1);
                //reverse(begin(parte), end(parte));

//                if (operadores.size() >= 2) {
//                    //string t = operadores.top();
//                    actual = anterior;
//                    operadores.pop();
//                    anterior = operadores.top();
//                    //operadores.push(t);
//                }

                if (anterior == "*" && actual == "+") {
                    parte = ")" + parte + "(";
                }
                operadores.pop();
                actual = anterior;
                anterior = operadores.top();

                operandos.push(parte);
            }
            else {
                if (linea[i] != ' ') {
                    string a(1, linea[i]);
                    operandos.push(a);
                }
            }

        }
    }
    string resp = operandos.top();
    reverse(begin(resp), end(resp));
    return resp;
}

int main(){
    int casos; // numero de casos de prueba
    string linea;
    cin >> casos;
    cin.ignore();
    while (casos--) {
        getline(cin, linea);
        //reverse(begin(linea), end(linea));
        cout << LispToInfix(linea) << "\n";
    }
    cout << "final";
    return 0;
}
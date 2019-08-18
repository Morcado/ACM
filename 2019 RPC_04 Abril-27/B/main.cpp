#include <bits/stdc++.h>

using namespace std;

bool year[365];

//enum months {
//    jan = 31, feb = 28, mar = 31, apr = 30,
//    may = 31, jun = 30, jul = 31, aug = 31,
//    sep = 30, oct = 31, nov = 30, dec = 31
//};

enum months {
    jan = 0, feb = 31, mar = 59, apr = 90,
    may = 120, jun = 151, jul = 181, aug = 212,
    sep = 243, octt = 273, nov = 304, decc = 334
};

int main() {
    int n; // colegas de booby
    cin >> n;
    cin.tie();
    cin.ignore();

    string name, date;
    while (n--) {
        cin >> name >> date;
        int day = stoi(date.substr(3, 2)) - 1;
        if (date.substr(0, 2) == "01") {
            year[jan + day] = true;
        }
        if (date.substr(0, 2) == "02") {
            year[feb + day] = true;
        }
        if (date.substr(0, 2) == "03") {
            year[mar + day] = true;
        }
        if (date.substr(0, 2) == "04") {
            year[apr + day] = true;
        }
        if (date.substr(0, 2) == "05") {
            year[may + day] = true;
        }
        if (date.substr(0, 2) == "06") {
            year[jun + day] = true;
        }
        if (date.substr(0, 2) == "07") {
            year[jul + day] = true;
        }
        if (date.substr(0, 2) == "08") {
            year[aug + day] = true;
        }
        if (date.substr(0, 2) == "09") {
            year[sep + day] = true;
        }
        if (date.substr(0, 2) == "10") {
            year[octt + day] = true;
        }
        if (date.substr(0, 2) == "11") {
            year[nov + day] = true;
        }
        if (date.substr(0, 2) == "12") {
            year[decc + day] = true;
        }
    }

    int lapsoMayor = 0;
    int posicionLapso = 0;
    int posAux = 0;
    bool inicio = true;
    for (int i = 0; i < 365; ++i) {
        if (year[i]) {
            if (inicio) {
                inicio = false;
                if (i - posicionLapso > lapsoMayor) {
                    lapsoMayor = i - posicionLapso;
                }
            }
            continue;
        }
        else {
            if (!inicio) {
                inicio = true;
                posicionLapso = i;
            }
        }

    }
    return 0;
}
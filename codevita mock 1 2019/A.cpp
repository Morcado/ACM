#include <bits/stdc++.h>
using namespace std;

struct Letters {
    char letter;
    int pos;
};

int main() {
    Letters letters[26];
    char l = 'a';

    int tests;
    int contador[26] = {0};
    string orden, lexico;
    string res = "";
    int pos = 0;
    //cin >> tests;
    cin.ignore();

    cin >> orden >> lexico;

    for (int i = 0; i < orden.length(); i++) {
        letters[i].letter = orden[i];
        letters[i].pos = i;
    }
    sort(begin(letters), end(letters), [](Letters a, Letters b){return a.pos > b.pos;});
    for (int i = 0; i < 26; i++) {
        cout << letters[i].pos << " " << letters[i].letter << "\n";
    }

    //cout << res << "\n";
    return 0;
}
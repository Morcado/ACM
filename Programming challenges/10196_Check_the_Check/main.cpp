#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class K {
private:
    int x;
    int y;
public:
    K() : x(0), y(0) { }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    void setXY(int i, int j) {
        x = i;
        y = j;
    }
};

void checkCheck(K Kg[], char board[8][8], bool& wIsCheck, bool& bIsCheck);
bool bishop(K k, char b, char q, char board[8][8]);
bool tower(K k, char r, char q, char board[8][8]);
bool knight(K k, char n, char board[8][8]);
bool pawn(K k, char p, char board[8][8]);

int main(){
    char board[8][8];
    string line;
    K Kg[2];
    vector<string> vec;
    int i = 0, j = 0, pcont = 0, g = 1;
    // mientras no sea un tablero vacio
    while (getline(cin, line)) {
        istringstream iss(line);
        unsigned char piece;
        while (iss >> piece) {
            if (piece != '.') {
                pcont++;
            }
            board[i][j] = piece;
            if (piece == 'k') {
                Kg[0].setXY(i, j);
            }
            if (piece == 'K') {
                Kg[1].setXY(i, j);
            }
            i++;
        }
        //cout << i << j << pcont << endl;
        if (i == 8) {
            j++;
        }
        // pcont > 0, there are pieces
        if (pcont == 0 && i == 8 && j == 8) {

            break;
        }
        else {

            if (j < 8) {
                i = 0;
            }
            if (i == 8 && j == 8) {
                //cout << Kg[0].getX() << " " << Kg[0].getY();
                bool wIsCheck = false, bIsCheck = false;
                checkCheck(Kg, board, wIsCheck, bIsCheck);
                if (wIsCheck) {
                    //vec.push_back("Game #" + to_string(g) + ": white king is in check.");
                }else {
                    if (bIsCheck) {
                        //vec.push_back("Game #" + to_string(g) + ": black king is in check.");
                    }
                    else {
                        //vec.push_back("Game #" + to_string(g) + ": no king is in check.");
                    }
                }
                pcont = i = j = 0;
                g++;
            }
            // Full board
            //

        }
    }
    for (auto& v : vec) {
        cout << v << endl;
    }
    return 0;
}

void checkCheck(K Kg[], char board[8][8], bool& wIsCheck, bool& bIsCheck) {
    wIsCheck = tower(Kg[1], 'r', 'q', board);
    if (wIsCheck) {
        return;
    }
    bIsCheck = tower(Kg[0], 'R', 'Q', board);
    if (bIsCheck) {
        return;
    }
    wIsCheck = bishop(Kg[1], 'b', 'q', board);
    if (wIsCheck) {
        return;
    }
    bIsCheck = bishop(Kg[0], 'B', 'Q', board);
    if (bIsCheck) {
        return;
    }
    wIsCheck = knight(Kg[1], 'n', board);
    if (wIsCheck) {
        return;
    }
    bIsCheck = knight(Kg[0], 'N', board);
    if (bIsCheck) {
        return;
    }
    wIsCheck = pawn(Kg[1], 'p', board);
    if (wIsCheck) {
        return;
    }
    bIsCheck = pawn(Kg[0], 'P', board);
    if (bIsCheck) {
        return;
    }
}

bool tower(K k, char r, char q, char board[8][8]) {
    // Horizontal
    for (int i = k.getX(); i < 8; i++) {
        if (board[i][k.getY()] == r || board[i][k.getY()] == q) {
            return true;
        }
        if (board[i][k.getY()] == 'k' || board[i][k.getY()] == 'K') {
            continue;
        }
        if (board[i][k.getY()] != '.') {
            break;
        }
    }
    for (int i = k.getX(); i >= 0; i--) {
        if (board[i][k.getY()] == r || board[i][k.getY()] == q) {
            return true;
        }
        if (board[i][k.getY()] == 'k' || board[i][k.getY()] == 'K') {
            continue;
        }
        if (board[i][k.getY()] != '.') {
            break;
        }
    }
    for (int i = k.getY(); i < 8; i++) {
        if (board[k.getX()][i] == r || board[k.getX()][i] == q) {
            return true;
        }
        if (board[k.getX()][i] == 'k' || board[k.getX()][i] == 'K') {
            continue;
        }
        if (board[k.getX()][i] != '.') {
            break;
        }
    }
    for (int i = k.getY(); i >= 0; i--) {
        if (board[k.getX()][i] == r || board[k.getX()][i] == q) {
            return true;
        }
        if (board[k.getX()][i] == 'k' || board[k.getX()][i] == 'K') {
            continue;
        }
        if (board[k.getX()][i] != '.') {
            break;
        }
    }
    return false;
}

bool bishop(K k, char b, char q, char board[8][8]) {
    for (int i = k.getX(), j = k.getY(); i < 8 && j < 8; i++, j++) {
        if (board[i][j] == b || board[i][j] == q) {
            return true;
        }
        if (board[i][j] == 'k' || board[i][j] == 'K') {
            continue;
        }
        if (board[i][j] != '.') {
            break;
        }
    }
    for (int i = k.getX(), j = k.getY(); i < 8 && j >= 0; i++, j--) {
        if (board[i][j] == b || board[i][j] == q) {
            return true;
        }
        if (board[i][j] == 'k' || board[i][j] == 'K') {
            continue;
        }
        if (board[i][j] != '.') {
            break;
        }
    }
    for (int i = k.getX(), j = k.getY(); i >= 0 && j < 8; i--, j++) {
        if (board[i][j] == b || board[i][j] == q) {
            return true;
        }
        if (board[i][j] == 'k' || board[i][j] == 'K') {
            continue;
        }
        if (board[i][j] != '.') {
            break;
        }
    }
    for (int i = k.getX(), j = k.getY(); i >= 0 && j >= 0 ; i--, j--) {
        if (board[i][j] == b || board[i][j] == q) {
            return true;
        }
        if (board[i][j] == 'k' || board[i][j] == 'K') {
            continue;
        }
        if (board[i][j] != '.') {
            break;
        }
    }
    return false;
}

bool knight(K k, char n, char board[8][8]) {
    int i = k.getX(), j = k.getY();
    if (i - 2 > 0 && j - 1 > 0 && board[i - 2][j - 1] == n) {
        return true;
    }
    if (i - 1 > 0 && j - 2 > 0 && board[i - 1][j - 2] == n) {
        return true;
    }
    if (i + 1 < 8 && j - 2 > 0 && board[i + 1][j - 2] == n) {
        return true;
    }
    if (i + 2 < 8 && j - 1 > 0 && board[i + 2][j - 1] == n) {
        return true;
    }
    if (i + 2 < 8 && j + 1 < 8 && board[i + 2][j + 1] == n) {
        return true;
    }
    if (i + 1 < 8 && j + 2 < 8 && board[i + 1][j + 2] == n) {
        return true;
    }
    if (i - 1 > 0 && j + 2 < 8 && board[i - 1][j + 2] == n) {
        return true;
    }
    if (board[i - 2][j + 1] && board[i - 2][j + 1] == n) {
        return true;
    }
    return false;;
}

bool pawn(K k, char p, char board[8][8]) {
    int i = k.getX(), j = k.getY();
    if (p == 'p') {
        if (board[i + 1][j - 1] == p && i + 1 < 8 && j - 1 >= 0) {
            return true;
        }
        if (i - 1 >= 0 && j - 1 >=0 && board[i - 1][j - 1] == p) {
            return true;
        }
        return false;
    }
    if (i + 1 < 8 && j + 1 < 8 && board[i + 1][j + 1] == p) {
        return true;
    }
    if (i - 1 >= 0 && j + 1 < 8 && board[i - 1][j + 1] == p) {
        return true;
    }
    return false;
}

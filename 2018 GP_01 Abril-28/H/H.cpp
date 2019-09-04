#include <bits/stdc++.h>
using namespace std;

#define TAM 10

struct Box {
    int x, y, d;
};

struct State {
    Box box[3];
};

char area[TAM][TAM];
bool v[TAM][TAM][TAM][TAM][TAM][TAM] = {false};
int width, height; // N, M

bool operator==(const State& a, const State& b) {
    int x1a = a.box[0].x, y1a = a.box[0].y;
    int x2a = a.box[1].x, y2a = a.box[1].y;
    int x3a = a.box[2].x, y3a = a.box[2].y;

    int x1b = b.box[0].x, y1b = b.box[0].y;
    int x2b = b.box[1].x, y2b = b.box[1].y;
    int x3b = b.box[2].x, y3b = b.box[2].y;

    return x1a == x1b && x2a == x2b && x3a == x3b &&
           y1a == y1b && y2a == y2b && y3a == y3b;
}

bool is_valid(int x, int y) {
    return x >= 0 && x < width && y >= 0 && x < height && area[x][y] != '#';
}

void visit(State state) {
    v[state.box[0].x][state.box[0].y][state.box[1].x][state.box[1].y][state.box[2].x][state.box[2].y] = true;
}

bool is_visited(State state) {
    return v[state.box[0].x][state.box[0].y][state.box[1].x][state.box[1].y][state.box[2].x][state.box[2].y];
}

int search_storages(State initial, State final) {
    queue<State> rest;
    rest.push(initial);
    visit(initial);

    int k = 1;

    const int dx[4] = {1,  0, -1,  0};
    const int dy[4] = {0,  1,  0, -1};


    while (!rest.empty()) {
        State a = rest.front();
        rest.pop();

        if (a == final) {
            int r = 0;
            for (int i = 0; i < 3; i++) {
                r += a.box[i].d;
            }
            return r;
        }

        // cada Box
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 4; ++j) {
                State t = a;
                t.box[i].d++;
                t.box[i].x += dx[j];
                t.box[i].y += dy[j];
                if (is_valid(t.box[i].x, t.box[i].y) && !is_visited(t)) {
                    rest.push(t);
                    visit(t);
                }

            }
        }
    }
    return -1;
}

int main() {

    cin >> width >> height;
    int ipos = 0, epos = 0, res = -1;
    State initial{};
    State final{};

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {

            cin >> area[i][j];

            if (area[i][j] == 'C') {
                initial.box[ipos].x = i;
                initial.box[ipos].y = j;
                initial.box[ipos++].d = 0;
            }
            if (area[i][j] == 'O') {
                final.box[epos].x = i;
                final.box[epos].y = j;
                final.box[epos++].d = 0;
            }
        }
    }

    res = search_storages(initial, final);
    cout << res << "\n";

}

/*
 7 6
 ######
 #.B#G#
 #.B#G#
 #.B#G#
 #..#.#
 ##...#
 ######

 no funciona
*/
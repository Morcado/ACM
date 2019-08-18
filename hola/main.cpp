#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> numbers = { 1, 2, -3, -6, 1, 5, 2, 8, -8 , 33, 41, 3, 0, -1 };
    sort(begin(numbers), end(numbers), [](int a, int b){return a > b;});

    random_device randomDevice;

    mt19937 generator(randomDevice());

    shuffle(begin(numbers), end(numbers), generator);


    return 0;
}
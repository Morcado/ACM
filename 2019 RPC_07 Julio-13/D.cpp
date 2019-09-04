#include <bits/stdc++.h>

using namespace std;

int main() {
    int sequenceLength, n;
    vector<int> sequence, res;

    cin >> sequenceLength;

    for (int i = 0; i < sequenceLength; i++) {
        cin >> n;
        sequence.push_back(n);
    }
    res.push_back(0);
    for (int i = 0; i < sequenceLength - 1; i++) {
        res.push_back(-(res[i] - sequence[i]));
    }
    int a = -(res[res.size() - 1] - sequence[sequence.size() - 1]);
    //cout << "val a: " << a << "\n";
    res.push_back(a);
    // res.push_back(-(*(end(res) - 1) - *(end(sequence) - 1)));
    //for_each(begin(sequence), end(sequence), [&res, &sequence](int i){res.push_back(-(res[i] - sequence[i])); cout << "a: " << i;});
    // cout << "\n";
    //for_each(begin(res), end(res), [](int i){cout << i << " ";});
    //int i = min_element(res.begin(), res.end(), [](int i, int j){return i % 0 == 0});
    int minOdd = res[0], minEven = res[1], r;

    for (int i = 2; i < (int)res.size(); i++) {
        if (i % 2 == 0 && res[i] < minOdd) {
            minOdd = res[i];
        }
        else {
            if (i % 2 != 0 && res[i] < minEven) {
                minEven = res[i];
            }
        }
    }
    //cout << "minodd: " << -minOdd   << ", mineven" << minEven << "\n";

    if (-minOdd <= minEven) {
        r = minEven - (- minOdd) + 1;
        cout << r << "\n";
    }
    else {
        cout << "0\n";
    }

    return 0;
}
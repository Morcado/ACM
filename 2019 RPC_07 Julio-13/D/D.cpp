#include <bits/stdc++.h>

using namespace std;

int main() {
    int sequenceLength, n;
    int leastTimes = 1, leAux;
    vector<int> sequence, res;

    cin >> sequenceLength;

    for (int i = 0; i < sequenceLength; i++) {
        cin >> n;
        sequence.push_back(n);
    }

    int nl = 0;
    for (int i = 1; i < sequenceLength - 1; i++) {
        if (sequence[i - 1] < sequence[i] && sequence[i + 1] < sequence[i]) {
            int sum = sequence[i - 1] + sequence[i + 1];

            if (sequence[i] <= sum) {
                nl = min(min(sequence[i - 1], sequence[i]), sequence[i + 1]);
                //nl = sum - sequence[i] + 1;
                //nl = sum - max(max(sequence[i - 1], sequence[i]), sequence[i + 1]);
                if (nl < leastTimes) {
                    leastTimes = nl;
                }
                res.push_back(nl);
            }
            else {
                res.push_back(0);
                leastTimes = 0;
                break;
            }
        }
        else {
            if (sequence[i - 1] > sequence[i] && sequence[i + 1] > sequence[i]) {
                int sum = sequence[i - 1] + sequence[i + 1];

                if (sequence[i] <= sum) {
                    //nl = sum - sequence[i] + 1;
                    nl = min(min(sequence[i - 1], sequence[i]), sequence[i + 1]);
                    //nl = sum - max(max(sequence[i - 1], sequence[i]), sequence[i + 1]);
                    if (nl < leastTimes) {
                        leastTimes = nl;
                    }
                    res.push_back(nl);
                }
                else {
                    res.push_back(0);
                    leastTimes = 0;
                    break;
                }
            }
            else {
                int difference = abs(sequence[i - 1] - sequence[i + 1]);

                if (difference <= sequence[i]) {
                    nl = *min_element(begin(sequence) + i, end(sequence) + i + 2) + 1;

                    if (nl < leastTimes) {
                        leastTimes = nl;
                    }
                    leastTimes = min(*min_element(begin(sequence) + i, end(sequence) + i + 2), leastTimes);
                    res.push_back(nl);
                }
                else {
                    res.push_back(0);
                    leastTimes = 0;
                    break;
                }
            }
        }
    }
    for_each(begin(res), end(res), [](int i){cout << i << ", ";});
    return 0;
    //cout << *min_element(begin(res), end(res)) << "\n";
}
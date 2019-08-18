#include <bits/stdc++.h>

using namespace std;

vector<int> BucketSort(vector<int> list) {
    int k = 10;
    int min = *min_element(begin(list), end(list));
    int max = *max_element(begin(list), end(list));

    vector<int> nueva;
    vector<vector<int>> bucket;
    bucket.resize(list.size());

    for (int i = 0; i < list.size(); i++) {
        int bi = int(double(list[i] - min) * list.size() / double(max - min + 1));
        //int bi = list[i] % 10;

        bucket[bi].push_back(list[i]);
    }

    for (int i = 0; i < bucket.size(); i++) {
        sort(begin(bucket[i]), end(bucket[i]));
    }

    for (int i = 0; i < bucket.size(); i++) {
        for (int j = 0; j < bucket[i].size(); j++) {
            nueva.push_back(bucket[i][j]);
        }
    }
    return nueva;
}

int main() {
    int numeros;
    int k;
    int n;
    vector<int> list, ordenada;
    cin >> numeros;


    while(numeros--) {
        cin >> n;
        list.push_back(n);
    }

    ordenada = BucketSort(list);

    //sort(list.begin(), list.end());

    //for_each(begin(ordenada), end(ordenada), [](int& i){ cout << i << "\n"; });

    if(ordenada[0] != 1) {
        cout << "1\n";
    }
    else {
        k = list[0];
        for (int i = 1; i < list.size(); i++) {
            if (list[i] > k + 1) {
                cout << k + 1 << "\n";
                break;
            }
            else {
                k += list[i];
            }
        }
    }
    return 0;
}
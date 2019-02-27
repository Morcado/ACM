#include <iostream>
#include <string>

using namespace std;

int main(){
    int n, k;
    string ch;
    cin >> n;
    cin >> k;


    int sumas[20] = {0};

    for(int i = 0; i < n; i++){
        cin >> ch;

        for(int j = 0; j < k; j++){
            if(ch[j] == '1'){
                sumas[j]++;
            }
        }
    }


    for(int i = 0; i < k; i++){
        if(sumas[i] > n/2){
            cout << "0";
        }
        else{
            cout << "1";
        }
    }
    return 0;
}

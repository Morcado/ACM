#include <iostream>

using namespace std;

int main(){
    int t, n, tcur;
    float prom, dp, dn, cur;
    cin >> t;
    for (int i = 0; i < t; i++) {
        prom = dp = dn = 0;
        cin >> n;
        float arr[1000] = {0};
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
            prom+=arr[j];
        }
        prom = prom/(float)n;

        for (int j = 0; j < n; j++) {
            cur = arr[j] - prom;
            tcur = cur*10000;
            cur = tcur/10000.0;
            if(cur < 0){
                dn += -cur;
            }
            else{
                dp += cur;
            }
        }
        printf("%.2f", ((dn>dp) ? (dp) : (dn)));
    }
    return 0;
}

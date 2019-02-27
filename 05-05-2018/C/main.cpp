#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int T, N, K;
    cin>>T;
    int total = 0;
    for(int i = 0; i < T; i++){
        cin>>N>>K;
        for(int j = 0; j < N; j++){
            int dato;
            cin>>dato;
            total += dato;
        }
    }
    cout<<ceil(total/(K * 10)) * 10;
    return 0;
}

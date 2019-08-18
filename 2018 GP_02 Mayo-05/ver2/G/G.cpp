#include <iostream>
#include <string>
#include <algorithm>

#define MAX 100005

using namespace std;

string cadenas[MAX];

int main(){

    ios_base::sync_with_stdio();
    cin.tie(0);

    int T;
    int N;
    int k;
    int h;
    cin>>T;

    for(int t=0; t<T; t++){
        cin>>N;
        for(int i=0; i<N; i++){
            cin>>cadenas[i];
            sort(&cadenas[i][0], &cadenas[i][cadenas[i].size()]);
        }

        sort(&cadenas[0], &cadenas[N-1]+1);
        h=0;
        for(int i=0; i<N-1; i++){
            k=0;
            for(; cadenas[i]==cadenas[i+1] && i<N-1; i++, k++);
            k++;
            h+=k*(k-1);
        }
        h+=N;
        cout<<h<<"\n";
    }
    return 0;
}
/*
2
3
abc
bca
cab
5
abc
ab
a
b
b

1
7
abc
abc
abc
abc
abc
b
c
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
/*
CASO 1:
30 13
6 6 -9 -13 18 22 26
8 -1 3 7 11 13 19 20 -27
 
CASO 2:
20 4
9 -2 -4 -8 -11 -12 15 18 19 20
7 4 5 -10 11 15 18 -20
 
CASO 3:
10 5
4 -1 2 3 -4
4 1 -2 3 -4
*/
 
bool compara (long long i,long long j) {
    return abs(i)<abs(j);
}
 
int main() {
    long long n, k, m1, m2, tint, t1, t2, signo;
    vector<long long> v1, v2, tvec;
   
    cin>>n>>k;
    cin>>m1;
    for(long long i=0; i<m1; i++) {
        cin>>tint;
        v1.push_back(tint);
    }
    cin>>m2;
    for(long long i=0; i<m2; i++) {
        cin>>tint;
        v2.push_back(tint);
    }
 
    /////////////////////////////////
    ///////           SUMA
    /////////////////////////////////
    for(long long i=0, j=0; i<m1||j<m2; ) {
        if(i==m1) {
            while(j<m2)
                tvec.push_back(v2[j++]);
        } else if(j==m2) {
            while(i<m1)
                tvec.push_back(v1[i++]);
        } else {
            t1 = abs(v1[i]);
            t2 = abs(v2[j]);
           
            signo = v1[i]<0?-1:1;
   
            if(t1 == t2) {
                if(v1[i] == v2[j])
                    tvec.push_back( signo* t1 );
 
                i++, j++;
            } else if(t1 < t2)
                tvec.push_back(v1[i++]);
            else tvec.push_back(v2[j++]);
        }
    }
   
    cout<<tvec.size();
    for(long long i=0;i<tvec.size();i++)
        cout<<" "<<tvec[i];
   
    /////////////////////////////////
    ///////           MULTIPLICACION
    /////////////////////////////////
    cout<<"\n";
    tvec.clear();
   
    for(long long i=0, j=0; i<m1||j<m2; ) {
        if(i==m1 || j==m2) break;
        else {
            t1 = abs(v1[i]);
            t2 = abs(v2[j]);
            int signo1 = v1[i]<0?-1:1;
            int signo2 = v2[j]<0?-1:1;
   
            if(t1 == t2) {
                // if(v1[i] == v2[j] && v2[j]>1)
                   // tvec.push_back(t1);
                // else
                tvec.push_back( signo1*signo2* t1 );
 
                i++, j++;
            } else if(t1 < t2)
                i++;
            else j++;
        }
    }
   
    cout<<tvec.size();
    for(long long i=0;i<tvec.size();i++)
        cout<<" "<<tvec[i];
       
    /////////////////////////////////
    ///////           SHIFT 1
    /////////////////////////////////
    cout<<"\n";
    tvec.clear();
   
    for(long long i=0; i<m1; i++) {
        t1 = abs(v1[i]);
        signo = v1[i]<0?-1:1;
 
        if(t1-k<=0)
            tvec.push_back( signo* (n+(t1-k)));
        else tvec.push_back( signo* (t1-k) );
    }
    sort(tvec.begin(), tvec.end(), compara);
   
    cout<<tvec.size();
    for(long long i=0;i<tvec.size();i++)
        cout<<" "<<tvec[i];
   
   
    /////////////////////////////////
    ///////           SHIFT 2
    /////////////////////////////////
    cout<<"\n";
    tvec.clear();
   
    for(long long j=0; j<m2; j++) {
        t2 = abs(v2[j]);
        signo = v2[j]<0?-1:1;
 
        if(t2-k<=0)
            tvec.push_back( signo* (n+(t2-k)));
        else tvec.push_back( signo* (t2-k) );
    }
    sort(tvec.begin(), tvec.end(), compara);
   
    cout<<tvec.size();
    for(long long i=0;i<tvec.size();i++)
        cout<<" "<<tvec[i];
   
    cout<<"\n";
   
    return 0;
}
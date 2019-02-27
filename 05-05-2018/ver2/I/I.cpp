#include <iostream>

#define MAX 11

using namespace std;

bool permite[MAX][MAX];
int permitido[MAX];
int necesarios[MAX];
bool visitado[MAX];
int recorrido[MAX];
int n;

void busqueda(int v, int i=0){
    if(visitado[v])return;
    recorrido[i]=v;
    if(i==n-1){
        for(int j=0; j<n-1; j++)
            cout<<recorrido[j]<<" ";
        cout<<recorrido[n-1];
        cout<<"\n";
        return;
    }
    visitado[v]=true;

    int ward[MAX];
    for(int j=0; j<n; j++)
        ward[j]=permitido[j];

    for(int j=0; j<n; j++){
        if(permite[v][j])
            permitido[j]++;
    }
    for(int j=0; j<n; j++){
        if(permitido[j]==necesarios[j])
            busqueda(j, i+1);
    }

    for(int j=0; j<n; j++)
        permitido[j]=ward[j];
    visitado[v]=false;
}
int main(){
    ios_base::sync_with_stdio();
    cin.tie(0);
    int T, m, v;
    cin>>T;
    for(int t=0; t<T; t++){
        for(int i=0; i<MAX; i++){
            permitido[i]=0;
            necesarios[i]=0;
            visitado[i]=0;
            recorrido[i]=0;
            for(int j=0; j<MAX; j++)permite[i][j]=0;
        }
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>m;
            for(int j=0; j<m; j++){
                cin>>v;
                permite[v][i]=true;
            }
            necesarios[i]=m;

        }

        for(int i=0; i<n; i++)
           if(permitido[i]==necesarios[i])busqueda(i);
    }
}

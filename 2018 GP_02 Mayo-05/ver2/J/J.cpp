#include <iostream>

using namespace std;

int main(){
    int cases;
    cin>>cases;
    for(int i = 0; i < cases; i++)
    {
        int a, b;

        cin>>a>>b;

        int d= b-a+1;

        if(a%2){
            int z;
            z= d/2;
            cout<<z<<" "<<d-z<<"\n";
        }
        else
        {
            int z;
            z= d/2;
            cout<<d-z<<" "<<z<<"\n";
        }


    }
    return 0;
}

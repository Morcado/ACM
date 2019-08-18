#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(){
    queue<string> resp;
    string cad;
    int T, X, Y;
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> X >> Y;
        if((Y%2 != 0 && X%2 == 0) || (Y%2 == 0 && X%2 != 0)){

            cad = to_string((Y-X)/2+1) + " " + to_string((Y-X)/2+1);


            resp.push(cad);
        }
        else{
            if(Y%2 == 0 && X%2 == 0){
                cad = to_string((Y-X)/2+1) + " " + to_string((Y-X)/2);
                resp.push(cad);
            }
            else{
                cad = to_string((Y-X)/2) + " " + to_string((Y-X)/2+1);
                resp.push(cad);
            }
        }
    }
    while(!resp.empty()){
        cout<<resp.front()<<"\n";
        resp.pop();
    }
    return 0;
}

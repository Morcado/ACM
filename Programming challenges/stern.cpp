#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

int main(){
    int E[2];
    double Y = 1.5;

    while(scanf("%d %d", &E[0], &E[1]) != EOF){
        string R = "";
        if((E[0] == 1 && E[1] == 1)){
            break;
        }

        if(E[0] == 1){
            for(int i = 1; i < E[1]; i++)
            R += "L";
        }
        else{
            if(E[1] == 1){
                for(int i = 1; i < E[0]; i++){
                    R += "R";
                }
            }
            else{
                if(E[0] == E[1] - 1) {
                    R += "L";
                    for (int i = 2; i < E[1]; i++) {
                        R += "R";
                    }
                }
                else {
                    if(E[1] == E[0] - 1) {
                        R += "R";
                        for (int i = 2; i < E[0]; i++) {
                            R += "L";
                        }
                    }
                    else {
                        int I[2] = {0,1}, C[2] = {1,1}, D[2] = {1,0};
                        while(Y != 0){
                            Y = E[0]*C[1] - E[1]*C[0];
                            if (Y == 0){
                                break;
                            }
                            if(Y < 0){
                                R += "L";
                                D[0] = C[0];
                                D[1] = C[1];
                                C[0] = D[0] + I[0];
                                C[1] = D[1] + I[1];
                            }
                            else{
                                R += "R";
                                I[0] = C[0];
                                I[1] = C[1];
                                C[0] = D[0] + I[0];
                                C[1] = D[1] + I[1];
                            }
                        }
                    }
                }
            }
        }
        Y = -1.5;
        cout << R << endl;
    }
    return 0;
}

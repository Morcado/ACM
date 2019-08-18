#include <bits/stdc++.h>

using namespace std;
int main() {
   int r, c;
   cin>>r;
   cin>>c;
   int pastel[r][c];
   int ancho, largo;
   ancho = largo = 0;
   for(int i = 0; i < r; i++) {
       for (int j = 0; j < c; j++) {
           int num;
           cin >> num;
           cout << pastel[i][j] << " ";
       }
       cout << "\n";
   }
   int j = 0;
   int x1, y1, x2, y2;
   for(int i = 0; i < r; i++) {
       for (int j = 0; j < c; j++) {
           if(pastel[i][j] == 0){
               if(ancho == 0){
                   x1 = i;
                   y1 = j;
               }
               ancho++;
               x2 = j;
           }
           else{

           }
       }
   }
}
#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio();
    cin.tie(0);
    int cases;
    cin>>cases;
    string s;

    for(int i = 0; i < cases; i++)
    {

        int lines, recorrido;
        cin >> lines >> recorrido;
        getline(cin, s);
        for (int j = 0; j < lines; j++)
        {
            getline(cin, s);
            for(int k = 0; k < s.size(); k++){
                if(s[k]>='A' && s[k]<='Z'){
                    int x= s[k]-'A';
                    x+= recorrido;
                    x%= 'Z'-'A'+1;
                    s[k]=x+'A';
                }
            }
            cout<<s<<"\n";

        }


    }
    return 0;
}
/*
2
1 1
UN TEXTO, y algo MAS
1 120
AlexAndeR
*/

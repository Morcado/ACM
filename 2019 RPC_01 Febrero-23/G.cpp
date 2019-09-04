#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

int main()
{
    int cant, cant2;
    string nombre, nombre2;



    while (cin >> nombre)
    {
        cin >> cant;
        cin >> nombre2 >> cant2;

        nombre = nombre[0];
        nombre2 = nombre2[0];

        if (nombre == nombre2){
            if (cant > cant2)
            {
                cout << "Tobby" << endl;
            }
            else
            {
                if (cant2 > cant)
                {
                    cout << "Naebbirac" << endl;

                }
                else
                {
                    cout << "Draw" << endl;

                }
            }
        }
        else
            {
                if(nombre == "D")
                {

                    if(nombre2 == "C")
                    {
                        if(cant2 >= cant*2) {
                            cout << "Naebbirac" << endl;
                        }
                        else {
                            cout << "Tobby" << endl;
                        }
                    }
                    else {
                        if(cant >= cant2*2) {
                            cout << "Tobby" << endl;
                        }
                        else {
                            cout << "Naebbirac" << endl;
                        }
                    }
                }
                else{

                if(nombre == "C")
                {
                    if(nombre2 == "D")
                    {
                        if(cant >= cant2*2) {
                            cout << "Tobby" << endl;
                        }
                        else {
                            cout << "Naebbirac" << endl;
                        }
                    }
                    else {
                        if(cant2 >= cant*2) {
                            cout << "Naebbirac" << endl;
                        }
                        else {
                            cout << "Tobby" << endl;

                        }
                    }
                }
                else
                {

                    if(nombre2 == "D")
                    {
                        if(cant2 >= cant*2) {
                            cout << "Naebbirac" << endl;
                        }
                        else {
                            cout << "Tobby" << endl;
                        }
                    }
                    else {
                        if(cant >= cant2*2) {
                            cout << "Tobby" << endl;
                        }
                        else {
                            cout << "Naebbirac" << endl;

                        }
                    }
                }
            }
        }
    }

    return 0;
}

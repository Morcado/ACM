/*
	Problema H Pizza Deal
	Aplicación 13 Julio 2019
	
	Se dan una pizza y dos precios, una rebanada con area A y precio P1, o una pizza completa con
	Radio R y precio P2

	Imprimir "Whole Pizza" si conviene comprar la pizza completa o "Slice of pizza" si conviene
	comprar por rebanadas

	Ejemplo:
		8 4
		7 9					=>				Whole Pizza	

		9 2
		4 7					=>				Whole Pizza	

*/

#include <iostream>
#include <math.h>
using namespace std;
#define _USE_MATH_DEFINES

int main() {
	// Se piden el area de la pizza, el radio y los precios 
	unsigned int area, radio, precio1, precio2;
	cin >> area >> precio1;
	cin >> radio >> precio2;
	
	float areaCompleta = radio*radio*M_PI; // Area de la pizza completa
	// Se saca la relación cantidad/precio de la rebanada y la pizza completa y se elige
	// la que tenga mayor relación
	if (areaCompleta / (double)precio2 < (double)area / (double)precio1) {
	    cout << "Slice of pizza\n";
	}
	else {
	    cout << "Whole pizza\n";
	}
	return 0;
}

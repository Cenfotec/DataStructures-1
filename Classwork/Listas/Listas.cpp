// Listas.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Nodo.h"
#include "Lista.h"

using namespace std;

int main()
{
	Lista milista;
	int pNumOne = 5;
	int pNumTwo = 10;
	int pNumThree = 15;
	milista.agregarInicio(pNumOne);
	milista.agregarInicio(pNumTwo);
	milista.agregarInicio(pNumThree);

	milista.agregarOrdenado(18);
	milista.agregarOrdenado(7);
	milista.agregarOrdenado(13);
	milista.agregarOrdenado(5);
	
	//milista.eliminar(13);
	milista.eliminarPos(2);

	milista.mostrar();

	Lista Linv;
	Linv.agregarInicio(1);
	Linv.agregarInicio(2);
	Linv.agregarInicio(3);
	Linv.mostrarInverso(Linv.getCabeza());
	cout << "Longitud: " << milista.getLongitud() << endl;
	//Nodo *n = milista.buscar(10);
	//cout << n->getVal() << endl;
}

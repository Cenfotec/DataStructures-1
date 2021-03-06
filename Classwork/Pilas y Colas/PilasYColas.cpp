// PilasYColas.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Pila.h"
#include "Cola.h"
#include "Nodo.h"

using namespace std;

int main()
{

	/*Pila pila;
	pila.push(6);
	pila.push(14);

	cout << "(Pila) Tope: " << pila.topePila() << endl;
	cout << "(Pila) Longitud: " << pila.getLongitud() << endl;

	pila.pop();

	cout << "(Pila) Tope: " << pila.topePila() << endl;
	cout << "(Pila) Longitud: " << pila.getLongitud() << endl;

	pila.~Pila();

	cout << "(Pila) Tope: " << pila.topePila() << endl;
	cout << "(Pila) Longitud: " << pila.getLongitud() << endl;

	Cola colaPass;
	colaPass.insertarElem(pila.pop());
	colaPass.insertarElem(pila.pop());

	cout << "(Cola) Primero: " << colaPass.getInfoPrimero() << endl;
	cout << "(Cola) Longitud: " << colaPass.getLongitud() << endl;*/

	Cola cola;
	cola.insertarElem(6);
	cola.insertarElem(14);

	cout << "Primero: " << cola.getInfoPrimero() << endl;
	cout << "Longitud: " << cola.getLongitud() << endl;

	/*cola.atenderElem();

	cout << "Primero: " << cola.getInfoPrimero() << endl;
	cout << "Longitud: " << cola.getLongitud() << endl;

	cola.~Cola();

	cout << "Primero: " << cola.getInfoPrimero() << endl;
	cout << "Longitud: " << cola.getLongitud() << endl;*/

	Pila pila;
	pila.push(cola.atenderElem());
	pila.push(cola.atenderElem());

	cout << "(Pila) Tope: " << pila.topePila() << endl;
	cout << "(Pila) Longitud: " << pila.getLongitud() << endl;

	return 0;
}


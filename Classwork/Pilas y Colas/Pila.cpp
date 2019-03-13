#include "stdafx.h"
#include <iostream>
#include "Pila.h"
#include "Nodo.h"

Pila::Pila()
{
	tope = nullptr;
	longitud = 0;
}


Pila::~Pila()
{
	while (tope != nullptr)
	{
		this->pop();
	}
}

int Pila::getLongitud()
{
	return longitud;
}

int Pila::push(int n)
{
	Nodo *nuevo = new Nodo();
	nuevo->setVal(n);
	if (tope == nullptr) {
		tope = nuevo;

	}
	else {
		nuevo->setSiguiente(tope);
		tope = nuevo;
	}
	longitud++;
	return n;
}

int Pila::pop()
{
	Nodo* aux = tope;
	tope = tope->getSiguiente();
	int valDelete = aux->getVal();
	delete aux;
	longitud--;
	return valDelete;
}

bool Pila::isVacia()
{
	if (tope == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Pila::topePila()
{
	if (!isVacia())
	{
		return this->tope->getVal();
	}
	else
	{
		return NULL;
	}

}

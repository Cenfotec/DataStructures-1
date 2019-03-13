#include "stdafx.h"
#include "Cola.h"
#include "Nodo.h"


Cola::Cola()
{
	inicio = nullptr;
	fin = nullptr;
	longitud = 0;
}


Cola::~Cola()
{
	Nodo* aux = inicio;
	while (aux != nullptr)
	{
		Nodo* toDelete = aux;
		aux = aux->getSiguiente();
		longitud--;
		delete toDelete;;
	}
}

int Cola::getLongitud()
{
	return longitud;
}

bool Cola::isVacia()
{
	if (inicio == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Cola::insertarElem(int n)
{
	Nodo* nuevo = new Nodo();
	nuevo->setVal(n);

	if (inicio != nullptr) {
		fin->setSiguiente(nuevo);
		fin = nuevo;
	}
	else
	{
		inicio = nuevo;
		fin = nuevo;
	}
	longitud++;
	return n;
}

int Cola::atenderElem()
{
	if (!isVacia())
	{
		Nodo* aux = inicio;
		inicio = inicio->getSiguiente();
		int toDelete = aux->getVal();
		delete aux;
		longitud--;
		return toDelete;
	}
	else
	{
		return NULL;
	}
}

int Cola::getInfoPrimero() {
	if (!isVacia())
	{
		return this->inicio->getVal();
	}
	else
	{
		return NULL;
	}
}
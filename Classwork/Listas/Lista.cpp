#include "stdafx.h"
#include <iostream>
#include "Lista.h"
#include "Nodo.h"

using namespace std;

Lista::Lista()
{
	cab = NULL;
	longitud = 0;
}


Lista::~Lista()
{
	// Si la lista no es vacía, se recorre cada Nodo con un delete.
}

void Lista::agregarInicio(int n) {

	Nodo *nuevo = new Nodo();
	nuevo->setVal(n);
	if (getCabeza() == nullptr) {
		setCabeza(nuevo);

	}
	else {
		nuevo->setSiguiente(cab);
		cab = nuevo;
	}
	longitud++;
};

Nodo* Lista::getCabeza() {
	return cab;
};

void Lista::setCabeza(Nodo *cab) {
	this->cab = cab;
};

int Lista::getLongitud() {
	return longitud;
}

void Lista::mostrar() {
	Nodo *aux = getCabeza();
	while (aux != nullptr) {
		cout << aux->getVal() << endl;
		aux = aux->getSiguiente();
	}
};

bool Lista::listaVacia() {
	if (cab == nullptr) {
		return true;
	}
	return false;
}

Nodo* Lista::buscar(int n) {
	Nodo *aux = getCabeza();
	while (aux != nullptr) {
		if (aux->getVal() == n) {
			return aux;
		}
		aux = aux->getSiguiente();
	}
	return nullptr;
};

bool Lista::eliminar(int n) {
	if (!listaVacia()) {
		if (cab->getVal() == n) {
			Nodo* aux = cab;
			cab = cab->getSiguiente();
			delete aux;
			--longitud;
			return true;
		}
		else 
		{
			Nodo* ant = getCabeza();
			Nodo* act = getCabeza()->getSiguiente();
			while (act != nullptr) {
				if (act->getVal() == n) {
					ant->setSiguiente(act->getSiguiente());
					delete act;
					--longitud;
					return true;
				}
				ant = ant->getSiguiente();
				act = act->getSiguiente();
			}
					
		}
	}
	return false;
};

void Lista::agregarOrdenado(int n) {
	Nodo* nuevo = new Nodo();
	nuevo->setVal(n);
	if (getCabeza() == nullptr) {
		setCabeza(nuevo);
		longitud++;
	}
	else {
		if (n < getCabeza()->getVal()) {
			agregarInicio(n);
		}
		else 
		{
			Nodo *ant = getCabeza();
			Nodo *act = getCabeza()->getSiguiente();

			while (act != nullptr && act->getVal() < n) {
				ant = ant->getSiguiente();
				act = act->getSiguiente();
			}
			nuevo->setSiguiente(ant->getSiguiente());
			ant->setSiguiente(nuevo);
			longitud++;
		}
	}
}
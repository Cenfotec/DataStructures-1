#include "stdafx.h"
#include "Nodo.h"


Nodo::Nodo()
{
	this->val = 0;
	this->sig = nullptr;
}

void Nodo::setVal(int n) {
	val = n;
};

int Nodo::getVal() {
	return val;
};

void::Nodo::setSiguiente(Nodo* sig) {
	this->sig = sig;
};

Nodo* Nodo::getSiguiente() {
	return sig;
};
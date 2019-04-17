#include "pch.h"
#include "Pila.h"
#include <string>

Pila::Pila()
{
	this->tope = nullptr;
	this->longitud = 0;
}

Pila::~Pila()
{
}

bool Pila::push(int pValor)
{
	Asiento *aux = new Asiento(pValor);
	aux->setSig(this->tope);
	this->tope = aux;
	this->longitud++;
	return true;
}

int Pila::pop()
{
	int result = this->top();
	Asiento *aux = this->tope;
	this->tope = this->tope->getSig();
	delete aux;
	this->longitud--;
	return result;
}

int Pila::top()
{
	if (!isEmpty())
		return this->tope->getNumero();
	return NULL;
}

int Pila::getLongitud()
{
	return this->longitud;
}

bool Pila::isEmpty()
{
	if (this->tope == nullptr)
		return true;
	return false;
}

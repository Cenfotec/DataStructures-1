#pragma once
#include "Nodo.h"

class Pila
{

private:
	Nodo * tope;
	int longitud;

public:
	Pila();
	~Pila();
	int getLongitud();
	int push(int n);
	int pop();
	int topePila();
	bool isVacia();
};


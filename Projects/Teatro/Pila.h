#pragma once
#include "Asiento.h"
class Pila
{
private:
	Asiento * tope;
	int longitud;
public:
	Pila();
	~Pila();
	bool push(int);
	int pop();
	int top();
	int getLongitud();
	bool isEmpty();
	void liberarAsientos();
	void imprimir();
	bool reservar(int);
	bool comprar(int);
};


#pragma once
#include "Nodo.h"
class Lista
{
private:
	Nodo * cab;

public:
	Lista();
	~Lista();
	void agregarInicio(int);
	Nodo* getCabeza();
	void setCabeza(Nodo *_cab);
	void mostrar();
	bool listaVacia();
	Nodo* buscar(int);
	void agregarOrdenado(int);
};

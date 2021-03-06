#pragma once
#include "Nodo.h"
class Lista
{
private:
	Nodo * cab;
	int longitud;

public:
	Lista();
	~Lista();
	void agregarInicio(int);
	Nodo* getCabeza();
	void setCabeza(Nodo *cab);
	int getLongitud();
	void mostrar();
	bool listaVacia();
	Nodo* buscar(int);
	void agregarOrdenado(int);
	bool eliminar(int);
	bool eliminarPos(int);
	void mostrarInverso(Nodo* nodo);
};

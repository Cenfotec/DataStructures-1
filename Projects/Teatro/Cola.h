#pragma once
#include "NodoCola.h"
class Cola
{
private:
	NodoCola *frente;
	NodoCola *fin;
	int longitud;
public:
	Cola();
	bool isEmpty();
	bool insertar(int);
	int atender();
	bool eliminarPos(int);
	bool buscar(int);
	int getLongitud();
	~Cola();
};


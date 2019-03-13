#pragma once
#include "Nodo.h"

class Cola
{

private:
	Nodo * inicio;
	Nodo* fin;
	int longitud;

public:
	Cola();
	~Cola();
	int getLongitud();
	int insertarElem(int n);
	int atenderElem();
	int getInfoPrimero();
	bool isVacia();
};


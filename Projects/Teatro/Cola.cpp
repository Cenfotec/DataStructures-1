#include "pch.h"
#include "Cola.h"
#include <string>


Cola::Cola()
{
	this->frente = nullptr;
	this->fin = nullptr;
	this->longitud = 0;
}

bool Cola::isEmpty()
{
	if (this->frente == nullptr)
		return true;
	return false;
}

bool Cola::insertar(int pValor)
{
	NodoCola *aux = new NodoCola(pValor);

	if (isEmpty()) {
		this->frente = aux;
		this->fin = aux;
		this->longitud++;
		return true;
	}
	else
	{
		this->fin->setSig(aux);
		this->fin = aux;
		this->longitud++;
		return true;
	}
	return false;
}

int Cola::atender()
{
	if (!isEmpty()) {
		int result = this->frente->getIdComprador();

		NodoCola *aux = this->frente;
		this->frente = this->frente->getSig();
		delete aux;
		longitud--;
		return result;
	}
	return NULL;

}

bool Cola::eliminarPos(int pos)
{
	int contador = 2;
	if (!isEmpty()) {
		if (pos == 1) {
			NodoCola *aux = this->frente;
			this->frente = this->frente->getSig();
			delete aux;
			longitud--;
			return true;
		}
		else
		{
			NodoCola *ant = this->frente;
			NodoCola *act = this->frente->getSig();
			for (contador; contador < pos; contador++) {
				ant = ant->getSig();
				act = act->getSig();
			}
			ant->setSig(act->getSig());
			delete act;
			this->longitud--;
			return true;
		}
	}
	return false;
}

bool Cola::buscar(int pId)
{
	NodoCola *aux = frente;

	while (aux != NULL) {
		if (aux->getIdComprador() == pId) {
			return true;
		}
		aux = aux->getSig();
	}
	return false;
}

int Cola::getLongitud()
{
	return this->longitud;
}


Cola::~Cola()
{
	while (!isEmpty()) {
		eliminarPos(1);
	}
}

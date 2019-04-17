#include "pch.h"
#include "Lista.h"
#include <iostream>
using namespace std;


Lista::Lista()
{
	this->cabeza = nullptr;
	this->longitud = 0;
}

Lista::Lista(int pLongitud)
{
	this->cabeza = nullptr;
	this->longitud = 0;

	if (pLongitud >= 1) {
		for (int i = 0; i < pLongitud; i++) {
			this->agregarOrdenado(i+1);
		}
	}
}

Lista::~Lista()
{
}

void Lista::setLongitud(int pLongitud)
{
	this->longitud = pLongitud;
}

int Lista::getLongitud()
{
	return this->longitud;
}

int Lista::liberarAsientos() {
	int asientosLiberados = 0;

	Asiento *act = cabeza;
	while (act != nullptr) {
		if(act->liberar())
			asientosLiberados++;
		act = act->getSig();
	}

	return asientosLiberados;
}

void Lista::imprimir() {
	mostrarRecursivo(this->cabeza);
	cout << endl;
}

bool Lista::reservarPos(int pos, int id)
{
	if (pos <= this->longitud) {
		int contador = 2;
		if (!esVacia()) {
			if (pos == 1) {
				return cabeza->reservar(id);
			}
			else
			{
				Asiento *ant = this->cabeza;
				Asiento *act = this->cabeza->getSig();
				for (contador; contador < pos; contador++) {
					ant = ant->getSig();
					act = act->getSig();
				}
				return act->reservar(id);
			}
		}
	}
	else
		return false;
}

int Lista::reservar(int id)
{
	Asiento *act = cabeza;
	
	while (act != nullptr) {
		if (act->getEstado()) {
			act->reservar(id);
			return act->getNumero();
		}
		act = act->getSig();
	}

	return NULL;
}

bool Lista::comprar(int pos, int id)
{
	if (pos <= this->longitud) {
		int contador = 2;
		if (!esVacia()) {
			if (pos == 1) {
				if (cabeza->validarComprador(id)) {
					cabeza->comprar(id);
					return true;
				}
			}
			else
			{
				Asiento *ant = this->cabeza;
				Asiento *act = this->cabeza->getSig();
				for (contador; contador < pos; contador++) {
					ant = ant->getSig();
					act = act->getSig();
				}
				if (act->validarComprador(id)) {
					act->comprar(id);
					return true;
				}
			}
		}
	}
	else
	{
		return false;
	}
}

int Lista::mostrarRecursivo(Asiento *asiento)
{
	if (asiento == nullptr)
		return 0;
	else {
		cout << "Numero: " << asiento->getNumero();
		if (asiento->getEstado())
			cout << ", Disponible" << endl;
		else
			if(asiento->getOcupado())
				cout << ", Comprado" << endl;
			else
				cout << ", Reservado" << endl;
		return mostrarRecursivo(asiento->getSig());
	}
}

void Lista::agregar(int pValor)
{
	Asiento *nuevo = new Asiento(pValor);
	if (this->cabeza == nullptr) {
		this->cabeza = nuevo;
	}
	else {
		nuevo->setSig(cabeza);
		this->cabeza = nuevo;
	}

	this->longitud++;
}

void Lista::agregarOrdenado(int pValor)
{
	if (esVacia())
		agregar(pValor);
	else {
		if (this->cabeza->getNumero() > pValor) {
			agregar(pValor);
		}
		else {
			Asiento *nuevo = new Asiento(pValor);
			Asiento *ant = this->cabeza;
			Asiento *act = this->cabeza->getSig();

			while (act != nullptr && act->getNumero() < pValor) {
				ant = ant->getSig();
				act = act->getSig();
			}

			nuevo->setSig(ant->getSig());
			ant->setSig(nuevo);

			this->longitud++;
		}
	}
}

bool Lista::esVacia()
{
	if (this->cabeza == NULL)
		return true;
	return false;
}

int Lista::buscar(int pValor)
{
	Asiento *aux = cabeza;
	int pos = 1;

	while (aux != NULL) {
		if (aux->getNumero() == pValor) {
			return pos;
		}
		aux = aux->getSig();
		pos++;
	}
	return 0;
}

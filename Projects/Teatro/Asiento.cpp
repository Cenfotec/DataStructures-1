#include "pch.h"
#include "Asiento.h"
#include <string>

Asiento::Asiento()
{
}

Asiento::Asiento(int pNumero)
{
	this->numero = pNumero;
	this->estado = true;
	this->ocupado = false;
	this->idComprador = NULL;
}


Asiento::~Asiento()
{
}

bool Asiento::validarComprador(int pIdComprador)
{
	if (this->idComprador == pIdComprador)
		return true;
	return false;
}

void Asiento::setNumero(int pNumero)
{
	this->numero = pNumero;
}

int Asiento::getNumero()
{
	return this->numero;
}

void Asiento::setEstado(bool pEstado)
{
	this->estado = pEstado;
}

bool Asiento::getEstado()
{
	return this->estado;
}

bool Asiento::getOcupado()
{
	return this->ocupado;
}

bool Asiento::reservar(int pIdComprador)
{
	if (estado) {
		this->estado = false;
		this->idComprador = pIdComprador;
		return true;
	}
	return false;
}

bool Asiento::liberar()
{
	if (!this->ocupado && this->estado == false) {
		this->estado = true;
		this->idComprador = NULL;
		return true;
	}
	return false;
}

void Asiento::comprar(int pIdComprador)
{
	if(this->idComprador == pIdComprador)
		this->ocupado = true;
}

void Asiento::setSig(Asiento * pSig)
{
	this->sig = pSig;
}

Asiento * Asiento::getSig()
{
	return this->sig;
}

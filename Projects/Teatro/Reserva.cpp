#include "pch.h"
#include "Reserva.h"


Reserva::Reserva()
{
}

Reserva::Reserva(int pAsiento, string pNombre, int pId)
{
	this->id = pId;
	this->nombre = pNombre;
	this->asiento = pAsiento;
}


Reserva::~Reserva()
{
}

void Reserva::setId(int pId)
{
	this->id = pId;
}

int Reserva::getId()
{
	return this->id;
}

void Reserva::setNombre(string pNombre)
{
	this->nombre = pNombre;
}

string Reserva::getNombre()
{
	return this->nombre;
}

string Reserva::toString()
{
	string salida;
	salida = "Asiento: " + asiento + '\n';
	salida += "Nombre: " + nombre + '\n';
	salida += "Identifiacion: " + id + '\n';

	return salida;
}

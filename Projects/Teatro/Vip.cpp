#include "pch.h"
#include "Vip.h"


Vip::Vip(int pCapacidad, double pCosto)
{
	asientos = new Lista(pCapacidad);
	capacidad = pCapacidad;
	disponibles = pCapacidad;
	costo = pCosto;
	comprados = 0;
}


Vip::~Vip()
{
}

int Vip::getCapacidad()
{
	return capacidad;
}

int Vip::getDisponibles()
{
	return capacidad - disponibles;
}

int Vip::getComprados()
{
	return comprados;
}

double Vip::getCosto()
{
	return costo;
}

void Vip::liberarAsientos()
{
	disponibles = disponibles + asientos->liberarAsientos();
}

void Vip::reservarAsiento(int asiento, int id)
{
	if (asientos->reservarPos(asiento, id)) {
		cout << "Se ha reservado con exito el asiento " << asiento << endl;
		this->disponibles--;
	}
	else
		cout << "El asiento seleccionado no se encuentra disponible, intentelo de nuevo" << endl;
}

void Vip::comprarAsiento(int asiento, int id)
{
	if (asientos->comprar(asiento, id)){
		cout << "Se ha comprado con exito el asiento " << asiento << endl;
		comprados++;
	}
	else
		cout << "Error al comprar el asiento, intentelo de nuevo" << endl;
}

void Vip::mostrar()
{
	asientos->imprimir();
}

void Vip::info()
{
	int asientosOcupados = capacidad - disponibles;
	cout << "Asientos ocupados: " << asientosOcupados << endl;
	cout << "Asientos disponibles: " << disponibles << endl;
	cout << "Recaudacion: " << comprados * costo << endl;
}

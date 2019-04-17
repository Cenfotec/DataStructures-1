#include "pch.h"
#include "Preferencial.h"


Preferencial::Preferencial(int pCapacidad, double pCosto)
{
	asientos = new Pila();
	reservas = new int[pCapacidad];
	capacidad = pCapacidad;
	disponibles = pCapacidad;
	costo = pCosto;
	comprados = 0;

	for (int i = 0; i < capacidad; i++) {
		reservas[i] = 0;
	}
}


Preferencial::~Preferencial()
{
}

int Preferencial::getCapacidad()
{
	return capacidad;
}

int Preferencial::getDisponibles()
{
	return capacidad - disponibles;
}

int Preferencial::getComprados()
{
	return comprados;
}

double Preferencial::getCosto()
{
	return costo;
}

void Preferencial::liberarAsientos()
{
	for (int i = 0; i < capacidad; i++) {
		if (reservas[i] != 0) {
			reservas[i] = 0;
			disponibles++;
		}
	}
}

void Preferencial::reservarAsiento(int pIdComprador)
{
	if (disponibles != 0) {
		for (int i = 0; i < this->capacidad; i++) {
			if (reservas[i] == 0) {
				reservas[i] = pIdComprador;
				this->disponibles--;
				cout << "La reserva se ha realizado con exito" << endl;
				break;
			}
		}
	}
}

void Preferencial::comprarAsientoReservado(int pIdComprador)
{
	for (int i = 0; i < this->capacidad; i++) {
		if (reservas[i] == pIdComprador) {
			asientos->push(comprados + 1);
			cout << "Se ha comprado con exito el asiento " << comprados + 1 << endl;
			comprados++;
			reservas[i] = 0;
			break;
		}
	}
}

void Preferencial::comprarAsiento()
{
	if (disponibles != 0) {
		asientos->push(comprados + 1);
		cout << "Se ha comprado con exito el asiento " << comprados + 1 << endl;
		comprados++;
		disponibles--;
	}
}

void Preferencial::mostrar()
{
}

void Preferencial::info()
{
	int asientosOcupados = capacidad - disponibles;
	cout << "Asientos ocupados: " << asientosOcupados << endl;
	cout << "Asientos disponibles: " << disponibles << endl;
	cout << "Recaudacion: " << comprados * costo << endl;
}

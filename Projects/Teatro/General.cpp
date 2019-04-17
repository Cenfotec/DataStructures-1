#include "pch.h"
#include "General.h"


General::General(int pCapacidad, double pCosto)
{
	asientos = new Lista(pCapacidad);
	capacidad = pCapacidad;
	disponibles = pCapacidad;
	costo = pCosto;
	comprados = 0;
}


General::~General()
{
}

int General::getCapacidad()
{
	return capacidad;
}

int General::getDisponibles()
{
	return capacidad - disponibles;
}

int General::getComprados()
{
	return comprados;
}

double General::getCosto()
{
	return costo;
}

void General::liberarAsientos()
{
	disponibles = disponibles + asientos->liberarAsientos();
}

void General::reservarAsiento(int id)
{
	int asiento = asientos->reservar(id);
	if (asiento != 0) {
		cout << "Se ha reservado con exito el asiento " << asiento << endl;
		this->disponibles--;
	}
	else
	{
		cout << "Error al realizar la reserva, intentelo de nuevo" << endl;
	}
}

void General::comprarAsiento(int asiento, int id)
{
	if (asientos->comprar(asiento, id)) {
		cout << "Se ha comprado con exito el asiento " << asiento << endl;
		comprados++;
	}
	else
	{
		cout << "Error al comprar el asiento, intentelo de nuevo" << endl;
	}
		

}

void General::mostrar()
{
	asientos->imprimir();
}

void General::info()
{
	int asientosOcupados = capacidad - disponibles;
	cout << "Asientos ocupados: " << asientosOcupados << endl;
	cout << "Asientos disponibles: " << disponibles << endl;
	cout << "Recaudacion: " << comprados * costo << endl;
}

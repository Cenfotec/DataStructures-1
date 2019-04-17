#pragma once
#include "Lista.h"
#include <iostream>
#include <string>
using namespace std;
class Vip
{
private:
	Lista * asientos;
	int capacidad;
	int disponibles;
	int comprados;
	double costo;
public:
	Vip(int, double);
	~Vip();
	void liberarAsientos();
	void reservarAsiento(int, int);
	void comprarAsiento(int, int);
	void mostrar();
	void info();
	int getCapacidad();
	int getDisponibles();
	int getComprados();
	double getCosto();
};


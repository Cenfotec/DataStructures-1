#pragma once
#include <string>
using namespace std;
class Reserva
{
private:
	int id;
	string nombre;
	int asiento;
public:
	Reserva();
	Reserva(int, string, int);
	~Reserva();
	void setId(int);
	int getId();
	void setNombre(string);
	string getNombre();
	string toString();
};


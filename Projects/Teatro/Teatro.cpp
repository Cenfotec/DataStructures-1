// Teatro.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include "Vip.h"
#include "General.h"
#include "Preferencial.h"
#include "Cola.h"
using namespace std;


Vip * vip;
General * general;
Preferencial * preferencial;
Cola * colaEspera;
bool func_iniciada;

// Iniciar funcion
void iniciarFuncion()
{
	if (!func_iniciada)
	{
		func_iniciada = true;
		int vipPlata = vip->getComprados() * vip->getCosto();
		int preferencialPlata = preferencial->getComprados() * preferencial->getCosto();
		int generalPlata = general->getComprados() * general->getCosto();
		int totalPlata = vipPlata + preferencialPlata + generalPlata;
		cout << "Funcion 'Toy Story 4' ha iniciado!" << endl;
		cout << "VIP: " <<  vipPlata << " colones" << endl;
		cout << "Preferencial: " <<  preferencialPlata << " colones" << endl;
		cout << "General: " << generalPlata << " colones" << endl;
		cout << "Total: " << totalPlata << " colones" << endl;
	}
	else
	{
		cout << "Ya la funcion de 'Toy Story 4' ya empezo!" << endl;
	}
	
}

// Liberar Asientos
void liberarAsientos()
{
	if (!func_iniciada)
	{
		vip->liberarAsientos();
		preferencial->liberarAsientos();
		general->liberarAsientos();
		cout << "Se han liberado todos los asientos!" << endl;
	}
	else
	{
		cout << "Ya la funcion de 'Toy Story 4' ya empezo!" << endl;
	}

}

// Comprar Asiento
void comprarAsiento()
{
	if (!func_iniciada)
	{
		string tipo;
		cout << "Tipo de asiento (vip, preferencial, general): ";
		cin >> tipo;
		cout << "Tipo: " << tipo << endl;

		// VIP
		if (tipo.compare("vip") == 0)
		{
			cout << "Digite su cedula: " << endl;
			int ced;
			cin >> ced;
			cout << "Digite un asiento: " << endl;
			int asiento;
			cin >> asiento;
			vip->comprarAsiento(asiento, ced);
		}

		// Preferencial
		else if (tipo.compare("preferencial") == 0)
		{
			cout << "Desea comprar un asiento reservado? (s/n)" << endl;
			string opt;
			cin >> opt;
			bool comprarAsientoReservado = (opt.compare("s") == 0) ? true : false;
			if (comprarAsientoReservado)
			{
				cout << "Digite su cedula: " << endl;
				int ced;
				cin >> ced;
				preferencial->comprarAsientoReservado(ced);
			}
			else
			{
				cout << "Ya no quedan espacios disponibles. Desea ser anadido a la lista de espera? (s/n)" << endl;
				string opt;
				cin >> opt;
				bool addCola = (opt.compare("s") == 0) ? true : false;
				if (addCola) {
					cout << "Digite su cedula: " << endl;
					int ced;
					cin >> ced;
					if (!colaEspera->buscar(ced)) {
						colaEspera->insertar(ced);
						cout << "Se anadio a la cola! (" << ced << ")" << endl;
					}
					else
					{
						cout << "Usted ya se encuentra en la cola!" << endl;
					}
				}
			}
		}

		// General
		else if (tipo.compare("general") == 0)
		{
			cout << "Digite su cedula: " << endl;
			int ced;
			cin >> ced;
			cout << "Digite un asiento: " << endl;
			int asiento;
			cin >> asiento;
			general->comprarAsiento(asiento, ced);
		}
	}
	else
	{
		cout << "Ya la funcion de 'Toy Story 4' ya empezo!" << endl;
	}
}

// Reservar Asiento
void reservarAsiento()
{
	if (!func_iniciada)
	{
		string tipo;
		cout << "Tipo de asiento (vip, preferencial, general): ";
		cin >> tipo;
		cout << "Tipo: " << tipo << endl;

		// VIP
		if (tipo.compare("vip") == 0)
		{
			if (vip->getDisponibles() == vip->getCapacidad())
			{
				cout << "Ya no quedan espacios disponibles. Desea ser anadido a la lista de espera? (s/n)" << endl;
				string opt;
				cin >> opt;
				bool addCola = (opt.compare("s") == 0) ? true : false;
				if (addCola)
				{
					cout << "Digite su cedula: " << endl;
					int ced;
					cin >> ced;
					// Verificar si ya esta en la cola
					if (!colaEspera->buscar(ced)) {
						colaEspera->insertar(ced);
						cout << "Se anadio a la cola! (" << ced << ")" << endl;
					}
					else
					{
						cout << "Usted ya se encuentra en la cola!" << endl;
					}
				}
			}
			else
			{
				cout << "Digite su cedula: " << endl;
				int ced;
				cin >> ced;
				cout << "Digite un asiento: " << endl;
				int asiento;
				cin >> asiento;
				vip->reservarAsiento(asiento, ced);
			}
			
		}

		// Preferencial
		else if (tipo.compare("preferencial") == 0)
		{
			if (preferencial->getDisponibles() == preferencial->getCapacidad())
			{
				cout << "Ya no quedan espacios disponibles. Desea ser anadido a la lista de espera? (s/n)" << endl;
				string opt;
				cin >> opt;
				bool addCola = (opt.compare("s") == 0) ? true : false;
				if (addCola)
				{
					cout << "Digite su cedula: " << endl;
					int ced;
					cin >> ced;
					if (!colaEspera->buscar(ced)) {
						colaEspera->insertar(ced);
						cout << "Se anadio a la cola! (" << ced << ")" << endl;
					}				
					else
					{
						cout << "Usted ya se encuentra en la cola!" << endl;
					}
				}
			}
			else
			{
				cout << "Digite su cedula: " << endl;
				int ced;
				cin >> ced;
				preferencial->reservarAsiento(ced);
			}		
		}

		// General
		else if (tipo.compare("general") == 0)
		{
			if (general->getDisponibles() == general->getCapacidad())
			{
				cout << "Ya no quedan espacios disponibles. Desea ser anadido a la lista de espera? (s/n)" << endl;
				string opt;
				cin >> opt;
				bool addCola = (opt.compare("s") == 0) ? true : false;
				if (addCola)
				{
					cout << "Digite su cedula: " << endl;
					int ced;
					cin >> ced;
					if (!colaEspera->buscar(ced)) 
					{
						colaEspera->insertar(ced);
						cout << "Se anadio a la cola! (" << ced << ")" << endl;
					} 
					else
					{
						cout << "Usted ya se encuentra en la cola!" << endl;
					}					
				}
			}
			else
			{
				cout << "Digite su cedula: " << endl;
				int ced;
				cin >> ced;
				general->reservarAsiento(ced);
			}
		}
	}
	else
	{
		cout << "Ya la funcion de 'Toy Story 4' ya empezo!" << endl;
	}
}

void detenerAplicacion()
{
	cout << "[!] Deteniendo la aplicacion..." << endl;
	exit(0);
}

bool seleccionarOpcion(string opt)
{
	bool menu = true;

	if (opt.compare("1") == 0)
	{
		// Lista de funciones
		cout << "\n-----[ FUNCION ]-----" << endl;
		cout << "Nombre: Toy Story 4" << endl;
		cout << "VIP: " << vip->getDisponibles() << "/" << vip->getCapacidad() << endl;
		cout << "Preferencial: " << preferencial->getDisponibles() << "/" << preferencial->getCapacidad() << endl;
		cout << "General: " << general->getDisponibles() << "/" << general->getCapacidad() << endl;
	}

	if (opt.compare("2") == 0)
	{
		// Reservar
		reservarAsiento();
	}

	if (opt.compare("3") == 0)
	{
		// Comprar
		comprarAsiento();
	}

	if (opt.compare("4") == 0)
	{
		// Liberar
		liberarAsientos();
	}

	if (opt.compare("5") == 0)
	{
		// Iniciar funcion
		iniciarFuncion();

	}

	if (opt.compare("6") == 0)
	{
		detenerAplicacion();
	}

	return menu;
}


void mostrarMenu()
{
	cout << "\n----------------------------------------" << endl;
	cout << "1. Lista de funciones" << endl;
	cout << "2. Realizar reservacion" << endl;
	cout << "3. Pagar reservacion realizada" << endl;
	cout << "4. Liberar reservaciones" << endl;
	cout << "5. Iniciar funcion" << endl;
	cout << "6. Detener la aplicacion" << endl;
}

string leerOpcion()
{
	cout << "----------------------------------------" << endl;
	cout << "Seleccione una opcion: " << endl;
	string opcion;
	cin >> opcion;
	return opcion;

}

void menuPrincipal()
{
	string opcion = "";
	bool menu;
	do
	{
		mostrarMenu();
		opcion = leerOpcion();
		menu = seleccionarOpcion(opcion);
	} while (menu);
}

int main()
{
	// Datos
	vip = new Vip(10, 7000);
	general = new General(50, 4000);
	preferencial = new Preferencial(50, 5500);
	colaEspera = new Cola();
	func_iniciada = false;

	/* Reserva VIP */
	/*for (int i = 1; i <= 10; i++)
	{
		vip->reservarAsiento(i, (i + 1000));
	}*/

	/* Reserva Preferencial */
	/*for (int i = 1; i <= 50; i++)
	{
		preferencial->reservarAsiento((i + 1000));
	}*/

	/* Reserva General */
	/*for (int i = 1; i <= 50; i++)
	{
		general->reservarAsiento((i + 1000));
	}*/

	// Inicio
	menuPrincipal();



	return 0;
}
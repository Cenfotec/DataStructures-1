#pragma once
class Asiento
{
private:
	int numero;
	bool estado;
	int idComprador;
	bool ocupado;
	Asiento * sig;
public:
	Asiento();
	Asiento(int);
	~Asiento();
	bool validarComprador(int);
	void setNumero(int);
	int getNumero();
	void setEstado(bool pEstado);
	bool getEstado();
	bool getOcupado();
	bool reservar(int);
	bool liberar();
	void comprar(int);
	void setSig(Asiento *);
	Asiento * getSig();
};


#pragma once
class Nodo
{
private:
	int val;
	Nodo * sig;

public:
	Nodo();
	void setVal(int n);
	int getVal();
	void setSiguiente(Nodo*);
	Nodo* getSiguiente();
};
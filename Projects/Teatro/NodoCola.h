#pragma once
class NodoCola
{
private:
	int idComprador;
	NodoCola *sig;
public:
	NodoCola();
	NodoCola(int);
	int getIdComprador();
	void setIdComprador(int);
	NodoCola * getSig();
	void setSig(NodoCola *);
	~NodoCola();
};


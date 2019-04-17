#include "pch.h"
#include "NodoCola.h"


NodoCola::NodoCola()
{
	this->idComprador = 0;
	this->sig = nullptr;
}

NodoCola::NodoCola(int pIdComprador)
{
	this->idComprador = pIdComprador;
	this->sig = nullptr;
}

int NodoCola::getIdComprador()
{
	return this->idComprador;
}

void NodoCola::setIdComprador(int pValor)
{
	this->idComprador = pValor;
}

NodoCola * NodoCola::getSig()
{
	return this->sig;
}

void NodoCola::setSig(NodoCola * pSig)
{
	this->sig = pSig;
}


NodoCola::~NodoCola()
{
}

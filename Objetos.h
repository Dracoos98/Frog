#pragma once
#include "Piedra.h"
#include "Madera.h"
class Objetos
{
private:
	Figura** ArrObjetos;
	int* N;
public:
	Objetos();
	~Objetos();
	void InicializarArreglo();
	void MostrarYMoverArreglo(int WindowWidth);
	int GetN();
	Figura* RetornarFigura(int indice);
};

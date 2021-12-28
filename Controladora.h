#pragma once
#include "Objetos.h"
#include "Sapo.h"
using namespace System::Drawing;
class Controladora
{
private:
	Sapo* Sapito;
	Objetos* ArrObjetos;
	int DireccionAutomaticaSapo;
	bool Gano, Perdio;
public:
	Controladora();
	~Controladora();
	void InicializarArreglo();
	void Desplazar_Sapito(int WindowWidth, int WindowHeight, char tecla);
	void Mover(int WindowWidth);
	void Colision(int WindowWidth);
	bool ReturnGano();
	bool ReturnPerdio();
};

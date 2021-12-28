#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;
using namespace System;
class Figura
{
protected:
	int x, y, w, h, dx, dy, Tipo;
public:
	Figura();
	~Figura();
	void CambiarX(int cambio);
	void CambiarY(int cambio);
	int RetornarDX();
	int retornar_x();
	int retornar_y();
	int retornar_w();
	int retornar_h();
	void Borrar();
	int RetornarTipo();
};

#pragma once
#include "Figura.h"
class Madera : public Figura
{
private:
	bool TocaBorde;
public:
	Madera();
	~Madera();
	void Imprimir();
	void Mover(int WindowWidth);
	bool RetornarTocaBorde();
	int RetornarDX();
};

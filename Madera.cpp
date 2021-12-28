#include "Madera.h"

Madera::Madera()
{
	x = rand() % 80 + 5;
	y = rand() % 40 + 2;
	w = 9;
	h = 1;
	int randomico = rand() % 2;
	if (randomico == 0) dx = -1;
	if (randomico == 1) dx = 1;
	dy = 0;
	Tipo = 2;
	TocaBorde = false;
}

Madera::~Madera()
{
}

void Madera::Imprimir()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	Console::SetCursorPosition(x, y); cout << "=========";
}

void Madera::Mover(int WindowWidth)
{
	Borrar();
	if (dx + x < 1 || dx + x + w >= WindowWidth) {
		TocaBorde = true;
		dx = dx * -1;
	}
	else TocaBorde = false;
	x = dx + x;
	Imprimir();
}

bool Madera::RetornarTocaBorde()
{
	return TocaBorde;
}

int Madera::RetornarDX()
{
	return dx;
}

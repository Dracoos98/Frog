#include "Piedra.h"

Piedra::Piedra()
{
	Tipo = 1;
	x = rand() % 80 + 10;
	y = rand() % 30 + 5;
	w = 7;
	h = 1;
	dx = 0;
	dy = 0;
}

Piedra::~Piedra()
{
}

void Piedra::Imprimir()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	Console::SetCursorPosition(x, y); cout << "บบบบบบบ";
}
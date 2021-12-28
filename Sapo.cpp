#include "Sapo.h"

Sapo::Sapo()
{
	IsOnTop = false;
	ChocoBorde = false;
	isRightDirection = false;
	x = 20;
	y = 42;
	w = 10;
	h = 4;
	dx = 0;
	dy = 0;
}

Sapo::~Sapo()
{
}

void Sapo::Imprimir()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	Console::SetCursorPosition(x, y);   cout << "  @..@";
	Console::SetCursorPosition(x, y + 1); cout << " (----)";
	Console::SetCursorPosition(x, y + 2); cout << "< I  I >";
	Console::SetCursorPosition(x, y + 3); cout << "  *  *";
}

void Sapo::MoverHorizontal(int WindowWidth, int Input)
{
	Borrar();
	if (x + w + Input < 3 || x + Input + w > WindowWidth) {
		dx = 0;
		Input = 0;
	}
	dx = Input;
	x = x + dx;
	if (x == 0 || x + w == WindowWidth) ChocoBorde = true;
	else ChocoBorde = false;
	Imprimir();
}

void Sapo::MoverVertical(int WindowHeight, int Input)
{
	Borrar();
	if (y + Input < 1 || y + Input + h > WindowHeight) Input = 0;
	dy = Input;
	y = y + dy;
	Imprimir();
}

void Sapo::MoverAutomatico(bool IsRight, int WindowWidth)
{
	if (IsRight) MoverHorizontal(WindowWidth, 1);
	else MoverHorizontal(WindowWidth, -1);
}

void Sapo::CambiarIsOnTop(bool Cambio) {
	IsOnTop = Cambio;
}

void Sapo::CambiarIsRight(bool Cambio) {
	isRightDirection = Cambio;
}

bool Sapo::ReturnIsRight()
{
	return isRightDirection;
}

bool Sapo::ReturnChocoBorde()
{
	return ChocoBorde;
}

bool Sapo::ReturnIsOnTop()
{
	return IsOnTop;
}
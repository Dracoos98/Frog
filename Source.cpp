#include "Controladora.h"
#include <conio.h>
using namespace System;
using namespace std;
#include <conio.h>


int main() {
	const int Wventana = 100;
	const int Hventana = 50;
	Controladora* obj = new Controladora();
	Console::SetWindowSize(Wventana, Hventana);
	Console::CursorVisible = false;

	obj->InicializarArreglo();

	while (!obj->ReturnGano() && !obj->ReturnPerdio())
	{
		if (kbhit())
		{
			char t = getch();
			obj->Desplazar_Sapito(Wventana, Hventana, toupper(t));
			flushall();
		}
		obj->Mover(Wventana);
		_sleep(30);
	}

	Console::Clear();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	Console::SetCursorPosition(10, 30); cout << "El juego se ha terminado";
	Console::SetCursorPosition(10, 31);
	if (obj->ReturnGano()) cout << "Has llegado al fondo, ganaste";
	else cout << "Has tocado un borde montado de un tronco y te chocaste, perdiste";
	_sleep(8000);
	getch();
	delete obj;
	return 0;
}
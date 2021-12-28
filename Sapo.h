#pragma once
#include "Figura.h"
class Sapo : public Figura
{
private:
	bool IsOnTop, isRightDirection, ChocoBorde;
public:
	Sapo();
	~Sapo();
	void Imprimir();
	void MoverHorizontal(int WindowWidth, int Input);
	void MoverVertical(int WindowHeight, int Input);
	void MoverAutomatico(bool IsRight, int WindowWidth);
	bool ReturnIsOnTop();
	void CambiarIsOnTop(bool Cambio);
	bool ReturnIsRight();
	bool ReturnChocoBorde();
	void CambiarIsRight(bool Cambio);
};

#include "Controladora.h"

Controladora::Controladora()
{
	Sapito = new Sapo();
	ArrObjetos = new Objetos();
	DireccionAutomaticaSapo = 0;
	Gano = false;
	Perdio = false;
}

Controladora::~Controladora()
{
	delete Sapito, ArrObjetos;
}

void Controladora::InicializarArreglo()
{
	ArrObjetos->InicializarArreglo();
}

void Controladora::Desplazar_Sapito(int WindowWidth, int WindowHeight, char tecla)
{
	if ((tecla == '75' || tecla == 75) && Sapito->ReturnIsOnTop() == false) Sapito->MoverHorizontal(WindowWidth, -1);
	if ((tecla == '77' || tecla == 77) && Sapito->ReturnIsOnTop() == false) Sapito->MoverHorizontal(WindowWidth, 1);
	if (tecla == 72 || tecla == '72') {
		Sapito->CambiarIsOnTop(false);
		Sapito->MoverVertical(WindowHeight, -1);
	}
	if (tecla == 80 || tecla == '80') {
		Sapito->CambiarIsOnTop(false);
		Sapito->MoverVertical(WindowHeight, 1);
	}
}

void Controladora::Mover(int WindowWidth)
{
	if (Sapito->retornar_y() == 1) {
		Gano = true;
	}
	if (Sapito->ReturnChocoBorde() && Sapito->ReturnIsOnTop()) {
		Perdio = true;
	}
	if (Sapito->ReturnIsOnTop() == false) {
		Sapito->Borrar();
		Sapito->Imprimir();
	}
	else Sapito->MoverAutomatico(Sapito->ReturnIsRight(), WindowWidth);
	ArrObjetos->MostrarYMoverArreglo(WindowWidth);
	Colision(WindowWidth);
}

void Controladora::Colision(int WindowWidth)
{
	System::Drawing::Rectangle r1;
	r1.X = Sapito->retornar_x();
	r1.Y = Sapito->retornar_y();
	r1.Width = Sapito->retornar_w();
	r1.Height = Sapito->retornar_h();
	for (int i = 0; i < ArrObjetos->GetN(); i++)
	{
		System::Drawing::Rectangle r2;
		r2.X = ArrObjetos->RetornarFigura(i)->retornar_x();
		r2.Y = ArrObjetos->RetornarFigura(i)->retornar_y();
		r2.Width = ArrObjetos->RetornarFigura(i)->retornar_w();
		r2.Height = ArrObjetos->RetornarFigura(i)->retornar_h();
		if (r1.IntersectsWith(r2)) {
			Sapito->Borrar();
			if (ArrObjetos->RetornarFigura(i)->RetornarTipo() == 2) {
				Sapito->CambiarIsOnTop(true);
				if (ArrObjetos->RetornarFigura(i)->RetornarDX() == 1) Sapito->CambiarIsRight(true);
				else Sapito->CambiarIsRight(false);
			}
			Sapito->CambiarX(ArrObjetos->RetornarFigura(i)->retornar_x());
			Sapito->CambiarY(ArrObjetos->RetornarFigura(i)->retornar_y() - 4);
		}
	}
}

bool Controladora::ReturnGano()
{
	return Gano;
}

bool Controladora::ReturnPerdio()
{
	return Perdio;
}
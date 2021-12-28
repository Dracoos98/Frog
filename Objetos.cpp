#include "Objetos.h"

Objetos::Objetos()
{
    N = new int;
    *N = 20;
}

Objetos::~Objetos()
{
    for (int i = 0; i < *N; i++)
    {
        delete ArrObjetos[i];
    }
    delete[] ArrObjetos;
    delete N;
}

void Objetos::InicializarArreglo()
{
    Figura** Aux = new Figura * [*N + 1];
    for (int i = 0; i < *N; i++) {
        if (i % 2 == 0) Aux[i] = new Piedra();
        else Aux[i] = new Madera();
    }
    ArrObjetos = Aux;
}

void Objetos::MostrarYMoverArreglo(int WindowWidth)
{
    for (int i = 0; i < *N; i++) {
        if (ArrObjetos[i]->RetornarTipo() == 1) ((Piedra*)ArrObjetos[i])->Imprimir();
        if (ArrObjetos[i]->RetornarTipo() == 2) ((Madera*)ArrObjetos[i])->Mover(WindowWidth);
    }
}

int Objetos::GetN()
{
    return *N;
}

Figura* Objetos::RetornarFigura(int indice)
{
    return ArrObjetos[indice];
}
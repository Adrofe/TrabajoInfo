#pragma once
#include "pieza.h"
#include "rey.h"


#define MAX_PIEZAS 100


class ListaPiezas
{
private: 
	pieza* listaPiezas[MAX_PIEZAS];
	int nPiezas;

public:
	ListaPiezas();
	~ListaPiezas();
	bool agregarPieza(pieza* pieza);
	void dibuja();
	void eliminar(int index);
	void eliminar(pieza* pieza);
	void borrarContenido();

};


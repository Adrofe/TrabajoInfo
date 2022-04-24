#pragma once
#include "pieza.h"
#include "rey.h"
#include "reina.h"
#include "caballo.h"
#include "Peon.h"
#include "Alfil.h"
#include "Torre.h"


#define MAX_PIEZAS 100


class ListaPiezas
{
private: 
	pieza* listaPiezas[MAX_PIEZAS];
	int nPiezas;
	color proximoTurno = BLANCO;

public:
	ListaPiezas();
	~ListaPiezas();
	bool agregarPieza(pieza* pieza);
	void dibuja();
	void eliminar(int index);
	void eliminar(pieza* pieza);
	void borrarContenido();
	pieza* buscarPieza(int fila, int columna);
	void moverPieza(pieza* pieza, int fila, int columna);
	bool movimientoLegal(pieza* pieza, int fila, int columna);
	bool comprobarTurno(pieza* pieza); //Devuelve el color del proximo movimiento

};


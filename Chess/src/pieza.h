#pragma once
#include "coordenada.h"
#include "freeglut.h"
#include "ETSIDI.h"

enum color {NEGRO, BLANCO};


class pieza
{
	float altura = 6.0f, ancho = 4.0f;
	coordenada coord;
	color icolor;

public:
	pieza(color color, coordenada coord);
	~pieza();
	color getColor();
	coordenada getCoordenada();
	virtual bool movimientoLegal(coordenada destino) = 0;
	virtual void dibuja() = 0;


};


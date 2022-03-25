#pragma once
#include "coordenada.h"

enum color {NEGRO, BLANCO};


class pieza
{
	coordenada coord;
	color icolor;

public:
	pieza(color color, coordenada coord);
	~pieza();
	color getColor();
	coordenada getCoordenada();
	virtual bool movimientoLegal(coordenada destino) = 0;


};


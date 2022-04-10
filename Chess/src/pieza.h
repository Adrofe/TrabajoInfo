#pragma once
#include "coordenada.h"
#include "vector2D.h"
#include "freeglut.h"
#include "ETSIDI.h"

//enum color {NEGRO, BLANCO}; 0 -> negro  1-> blanco


class pieza
{	
	coordenada coord;
	bool icolor;

public:
	float altura = 6.0f, ancho = 4.0f;
	pieza(bool color, coordenada coord);
	pieza();
	~pieza();
	bool getColor();
	coordenada getCoordenada();
	virtual bool movimientoLegal(coordenada destino) = 0;
	virtual void dibuja() = 0;


};


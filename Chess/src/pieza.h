#pragma once
#include "coordenada.h"
#include "vector2D.h"
#include "freeglut.h"
#include "ETSIDI.h"


class pieza
{	
private:
	coordenada coord;
	color icolor;
	float altura = 8.0f, ancho = 6.0f;

public:
	

	pieza(color color, coordenada coord);
	pieza();
	~pieza();
	color getColor();
	coordenada getCoordenada();
	void setColumna(int columna);
	void setFila(int fila);

	virtual bool movimientoLegal(coordenada destino) = 0;
	virtual void dibuja();

	float getAltura() { return altura; }
	float getAncho() { return ancho; }
};


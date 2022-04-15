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


};


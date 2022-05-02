#pragma once
#include "coordenada.h"
#include "vector2D.h"
#include "freeglut.h"
#include "ETSIDI.h"

enum tipo_pieza {REY, REINA, ALFIL, TORRE, CABALLO, PEON};

class pieza
{	
private:
	coordenada coord;
	color icolor;
	float altura = 8.0f, ancho = 6.0f;

protected:
	tipo_pieza tipo;

public:
	

	pieza(color color, coordenada coord);
	pieza();
	~pieza();
	virtual color getColor();
	coordenada getCoordenada();
	void setColumna(int columna);
	void setFila(int fila);

	//virtual bool movimientoLegal(coordenada destino, bool matriz[7][7]);
	virtual void dibuja();
	virtual bool movimientoLegal(coordenada destino)=0;

	float getAltura() { return altura; }
	float getAncho() { return ancho; }

	virtual tipo_pieza getTipo() { return tipo; }

};


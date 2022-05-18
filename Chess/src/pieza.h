#pragma once
#include "coordenada.h"
#include "vector2D.h"
#include "freeglut.h"
#include "ETSIDI.h"
#include <fstream>
#include <string>

enum tipo_pieza {REY, REINA, ALFIL, TORRE, CABALLO, PEON};

class pieza
{	
private:
	coordenada coord;
	float altura = 8.0f, ancho = 6.0f;



protected:
	tipo_pieza tipo;
	int valor;
	color icolor;

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
	virtual void guardarHistorial(int fila, int columna) = 0;

	float getAltura() { return altura; }
	float getAncho() { return ancho; }

	virtual tipo_pieza getTipo() { return tipo; }
	int getValor() { return valor; }
	virtual int getValorPos(int fila, int columna)=0;

};


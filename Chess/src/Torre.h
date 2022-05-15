#pragma once
#include "pieza.h"
class Torre : public pieza {

	int puntPosBlancas[8][8] = {
	  0,  0,  0,  0,  0,  0,  0,  0,
	  5, 10, 10, 10, 10, 10, 10,  5,
	 -5,  0,  0,  0,  0,  0,  0, -5,
	 -5,  0,  0,  0,  0,  0,  0, -5,
	 -5,  0,  0,  0,  0,  0,  0, -5,
	 -5,  0,  0,  0,  0,  0,  0, -5,
	 -5,  0,  0,  0,  0,  0,  0, -5,
	  0,  0,  0,  5,  5,  0,  0,  0
	};
	int puntPosNegras[8][8] = {
	  0,  0,  0,  5,  5,  0,  0,  0
	 - 5,  0,  0,  0,  0,  0,  0, -5,
	 -5,  0,  0,  0,  0,  0,  0, -5,
	 -5,  0,  0,  0,  0,  0,  0, -5,
	 -5,  0,  0,  0,  0,  0,  0, -5,
	 -5,  0,  0,  0,  0,  0,  0, -5,
	  5, 10, 10, 10, 10, 10, 10,  5,
	  0,  0,  0,  0,  0,  0,  0,  0,
	};

public:
	Torre(color color, coordenada coord);
	Torre();

	void dibuja();
	bool movimientoLegal(coordenada destino);
	int getValorPos(int fila, int columna);

};


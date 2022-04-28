#pragma once
#include "pieza.h"

class Alfil : public pieza {

public:
	Alfil(color color, coordenada coord);
	Alfil();

	void dibuja();
	bool  movimientoLegal(coordenada destino);

};


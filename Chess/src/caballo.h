#pragma once
#include "pieza.h"
#include <math.h>

class caballo : public pieza {

public:
	caballo();
	caballo(color color, coordenada coord);

	void dibuja();
	bool movimientoLegal(coordenada destino);

};


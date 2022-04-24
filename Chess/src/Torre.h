#pragma once
#include "pieza.h"
class Torre : public pieza {

public:
	Torre(color color, coordenada coord);
	Torre();

	void dibuja();
	bool movimientoLegal(coordenada destino, bool matriz[8][8]);


};


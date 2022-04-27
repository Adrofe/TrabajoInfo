#pragma once
#include "pieza.h"
class reina : public pieza {

public:
	reina(color color, coordenada coord);
	reina();

	void dibuja();
	bool movimientoLegal(coordenada destino);

};


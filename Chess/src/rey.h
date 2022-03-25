#pragma once
#include "pieza.h"

class rey : public pieza
{
public:
	rey(color color, coordenada coord);
	rey();

	void dibuja();
	bool movimientoLegal(coordenada destino);
};


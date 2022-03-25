#pragma once
#include "pieza.h"

class rey : public pieza
{
public:
	void dibuja();
	bool movimientoLegal(coordenada destino);
};


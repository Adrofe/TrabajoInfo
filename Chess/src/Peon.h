#pragma once
#include "pieza.h"
class Peon : public pieza
{
public:
	Peon();
	Peon(color color, coordenada coord);

	void dibuja();
	bool movimientoLegal(coordenada destino, bool matriz[8][8]);
};


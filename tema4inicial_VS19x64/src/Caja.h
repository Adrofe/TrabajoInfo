#pragma once
#include "Pared.h"
class Caja
{
private:
	
	Pared suelo;
	Pared techo;
	Pared pared_izq;
	Pared pared_dcha;
public:
	Caja();
	void dibuja();

	friend class Interaccion;
};


#pragma once
#include "Vector2D.h"
#include "ObjetoMovil.h"
class Bonus: public ObjetoMovil
{
private:
	float lado;
public:
	// funcion principal de dibujo del bonus
	Bonus();
	void dibuja();
};


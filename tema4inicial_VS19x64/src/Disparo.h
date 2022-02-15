#pragma once
#include "Vector2D.h"
#include "Pared.h"
#include "ObjetoMovil.h"
class Disparo: public ObjetoMovil
{
protected:


	float radio{0.25f};
	Vector2D origen;

public:
	// Funcion para dibujar el disparo
	Disparo();
	void dibuja();
	float getRadio();
	void setPos(float ix, float iy);
	void setPos(Vector2D pos);

	friend class Interaccion;
};


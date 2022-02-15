#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
class ObjetoMovil
{
protected: 
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
public:
	virtual void mueve(float t);
	void setPos(float ix, float iy);
	void setPos(Vector2D pos);
	void setVel(float vx, float vy);
	Vector2D getPos();
};


#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"
class Pared
{
private:
	ColorRGB color;
	Vector2D limite1;
	Vector2D limite2;
public:
	Pared();
	// Funcion para dibujar la pared
	void dibuja();
	void setColor(unsigned char r, unsigned char g, unsigned char b);
	void setLimite(float limite1x, float limite1y, float limite2x, float limite2y);
	void setPos(float x1, float y1, float x2, float y2);
	float distancia(Vector2D punto, Vector2D* direccion = 0);

	friend class Interaccion;
};


#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"
#include "ObjetoMovil.h"
class Esfera: public ObjetoMovil
{
protected:
	ColorRGB color;
	float radio;

public:
	Esfera();
	Esfera(float rad, float x = 0.0f, float y = 0.0f, float vx = 0.0f, float vy = 0.0f);
	void dibuja();
	void setColor(unsigned char r, unsigned char g, unsigned char b);
	void setRadio(float r);
	virtual Esfera* dividir();

	friend class Interaccion;
};


#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
#include "ObjetoMovil.h"
using ETSIDI::SpriteSequence;

class Hombre: public ObjetoMovil
{
private:
	SpriteSequence sprite{ "imagenes/pangPlayer.png",5 };
	float altura{ 1.8f };
public:
	Hombre();
	void dibuja();
	void mueve(float t);
	float getAltura();

	friend class Interaccion;
};


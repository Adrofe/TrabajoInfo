#pragma once
#include "tablero.h"

class partida
{
public:
	tablero tablero;

	void tecla(unsigned char key);
	void inicializa();
	void mover();
	void dibuja();

	float x_ojo;
	float y_ojo;
	float z_ojo;


};


#pragma once
#include "tablero.h"
#include "pieza.h"
#include "rey.h"
#include "coordenada.h"

using namespace std;

class partida
{
public:
	tablero tablero;
	rey irey;

	void tecla(unsigned char key);
	void inicializa();
	void mover();
	void dibuja();

	float x_ojo;
	float y_ojo;
	float z_ojo;


};


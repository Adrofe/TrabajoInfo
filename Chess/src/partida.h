#pragma once
#include "tablero.h"
#include "pieza.h"
#include "rey.h"
#include "coordenada.h"
#include "stdlib.h"

using namespace std;
string a = "c";
coordenada pos(a, 4);

class partida
{
public:
	tablero tablero;
	
	rey irey(0,pos);

	void tecla(unsigned char key);
	void inicializa();
	void mover();
	void dibuja();

	float x_ojo;
	float y_ojo;
	float z_ojo;


};


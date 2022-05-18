#pragma once
#include "ListaPiezas.h"
#include "tablero.h"
#include "coordenada.h"
#include "stdlib.h"


using namespace std;

class partida
{
public:
	tablero tablero;
	ListaPiezas piezas;

	bool existeIA = true;
	bool calculando = false;

	color colorIA = NEGRO;
	
	friend class IA;


	void tecla(unsigned char key);
	void inicializa();
	void mover();
	void dibuja();
	void mouse(int button, int state, int x, int y);
	void getColFilMouse(int x, int y, int &fila, int &columna);
	
	

	float x_ojo;
	float y_ojo;
	float z_ojo;

	friend class Interaccion;
};


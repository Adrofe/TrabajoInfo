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
	coordenada coordenadaPintar[64];
	ListaPiezas piezas;
	bool si = false;
	bool turno = 1;		//1 movimiento de las blancas, 0 movimiento de las negras


	void tecla(unsigned char key);
	void inicializa();
	void mover();
	void dibuja();
	void mouse(int button, int state, int x, int y);
	void getColFilMouse(int x, int y, int &fila, int &columna);
	void movPosibles(pieza* aux);
	

	float x_ojo;
	float y_ojo;
	float z_ojo;


};


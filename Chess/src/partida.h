#pragma once
#include "ListaPiezas.h"
#include "tablero.h"
#include "coordenada.h"
#include "stdlib.h"


using namespace std;

class partida
{
	bool existeIA = false;
	bool calculando = false;
	color colorIA = NEGRO;

public:
	tablero tablero;
	ListaPiezas piezas;





	void inicializa();
	void mover();
	void dibuja();
	void mouse(int button, int state, int x, int y);
	void getColFilMouse(int x, int y, int &fila, int &columna);

	bool getJaqueMateBlanco() { return piezas.getJaqueMateBlanco(); }
	bool getJaqueMateNegro() { return piezas.getJaqueMateNegro(); }

	void setIA(bool IA, color colorIA);
	void limpiarTablero() {
		piezas.borrarContenido();
	}
	
	

	float x_ojo;
	float y_ojo;
	float z_ojo;
};


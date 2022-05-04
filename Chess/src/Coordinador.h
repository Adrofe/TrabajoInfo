#pragma once
#include"partida.h"

class Coordinador
{
public:
	Coordinador();
	virtual ~Coordinador();

	
	void tecla(unsigned char key);
	void mueve();
	void dibuja();

protected:
	partida partida;
	enum Estado { INICIO, JUEGO, FIN, GAMEOVER, PAUSA };
	Estado estado;
};
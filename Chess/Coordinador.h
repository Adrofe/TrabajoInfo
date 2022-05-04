#pragma once
#include"partida.h"

class Coordinador
{
public:
	Coordinador();
	virtual ~Coordinador();

	void teclaEspecial(unsigned char key);
	void tecla(unsigned char key);
	void mueve();
	void dibuja();


	float x_ojo;
	float y_ojo;
	float z_ojo;

protected:
	partida partida;
	enum Estado { INICIO, JUEGO, FIN, GAMEOVER, PAUSA };
	Estado estado;
};
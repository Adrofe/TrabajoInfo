#pragma once
#include "partida.h"
#include "freeglut.h"
#include "ETSIDI.h"

class Coordinador
{
public:
	Coordinador();
	virtual ~Coordinador();

	void mouse(int button, int state, int x, int y);
	void Tecla(unsigned char key);
	void mueve();
	void dibuja();
	void musica();
	

protected:
	partida partida;
	enum Estado { INICIO, MODOS, JUEGO, PAUSA, FIN, JAQUEMATE_BLANCO, JAQUEMATE_NEGRO };
	Estado estado;
private:
	bool modoMusica=false;

};

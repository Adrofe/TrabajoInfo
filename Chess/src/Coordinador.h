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
	void musica(bool activarmusica);
	bool actmusic;

protected:
	partida partida;
	enum Estado { INICIO, JUEGO, FIN, GAMEOVER, PAUSA };
	Estado estado;
private:
	

};

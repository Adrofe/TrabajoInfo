#include "partida.h"
#pragma once

class Coordinador
{
	public:
		Coordinador();
		virtual ~Coordinador();

		void mouse(int button, int state, int x, int y);
		void Tecla(unsigned char key);
		void mueve();
		void dibuja();

	protected:
		partida partida;
		enum Estado { INICIO, JUEGO, FIN, JAQUEMATE, PAUSA };
		Estado estado;




};


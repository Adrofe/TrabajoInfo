#include "partida.h"
#pragma once

class Coordinador
{
	public:
		Coordinador();
		virtual ~Coordinador();

		void teclaEspecial(unsigned char key);
		void Tecla(unsigned char key);
		void mueve();
		void dibuja();

	protected:
		partida partida;
		enum Estado { INICIO, JUEGO, FIN, JAQUEMATE, PAUSA };
		Estado estado;




};


#include "Coordinador.h"

Coordinador::Coordinador()
{
	estado = INICIO;
}

Coordinador::~Coordinador()
{

}

void Coordinador::dibuja()
{
	if (estado == INICIO) {
		gluLookAt(0, 7.5, 30, // posicion del ojo
				0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
				0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/04B_31__.ttf", 16);
		ETSIDI::printxy("Chess", -5, 8);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/04B_31__.ttf", 12);
		ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR", -5, 7);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -5, 6);
		ETSIDI::printxy("DEFENSA PETROV", 2, 1);
	}
	else if (estado == JUEGO)
	{
		partida.dibuja();
	}
	else if (estado == PAUSA)
	{
		partida.dibuja();
		ETSIDI::setTextColor(0, 1, 0);
		ETSIDI::setFont("fuentes/04B_31__.ttf", 16);
		ETSIDI::printxy("PAUSA", -2, 10);
		ETSIDI::printxy("Pulsa C para continuar", -5, 5);
	}
	else if (estado == JAQUEMATE)
	{
		partida.dibuja();
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("fuentes/04B_31__.ttf", 16);
		ETSIDI::printxy("JAQUE MATE: Has perdido", -5, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 5);
	}
	else if (estado == FIN)
	{
		partida.dibuja();
		ETSIDI::setFont("fuentes/04B_31__.ttf", 16);
		ETSIDI::printxy("ENHORABUENA, ¡HAS VENCIDO!", -5, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 9);
	}
}

void Coordinador::mouse(int button, int state, int x, int y)
{
	if (estado == JUEGO)
		partida.mouse(button, state, x, y);
}

void Coordinador::mueve() //funcion a modificar para el jaque mate
{
	if (estado == JUEGO)
	{
		//partida.mover();
		/*if (mundo.getNumEsferas() == 0)
		{
			if (!mundo.cargarNivel())
				estado = FIN;
		}
		if (mundo.getImpacto())
		{
			estado = GAMEOVER;
		}*/
	}
}
void Coordinador::Tecla(unsigned char key)
{
	if (estado == INICIO)
	{
		if (key == 'e')
		{
			partida.inicializa();
			estado = JUEGO;
		}
		if (key == 's')
			exit(0);
	}
	else if (estado == JUEGO)
	{
		partida.tecla(key);
		if (key == 'p')
			estado = PAUSA;
	}
	else if (estado == PAUSA)
	{
		if (key == 'c')
			estado = JUEGO;
	}
	else if (estado == JAQUEMATE)
	{
		if (key == 'c')
			estado = INICIO;
	}
	else if (estado == FIN)
	{
		if (key == 'c')
			estado = INICIO;
	}
}

#include "Coordinador.h"


Coordinador::Coordinador() {
	estado = INICIO;
}
Coordinador::~Coordinador(){
}

void CoordinadorPang::dibuja(){

	x_ojo = 31.9f;
	y_ojo = 100.0f
	z_ojo = 32.0f

	if (estado == INICIO) {
		gluLookAt(x_ojo, y_ojo, z_ojo, // posicion del ojo
			32.0, 0.0, 32.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("Pang 1.1", -5, 8);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR", -5, 7);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -5, 6);
		ETSIDI::printxy("Hernando & Rodriguez-Losada", 2, 1);
	}
	else if (estado == JUEGO)
	{
		partida.dibuja();
	}
	else if (estado == PAUSA)
	{
		partida.dibuja();
		ETSIDI::setTextColor(0, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("PAUSA", -2, 10);
		ETSIDI::printxy("Pulsa C para continuar", -5, 5);
	}
	else if (estado == GAMEOVER)
	{
		partida.dibuja();
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("GAMEOVER: Has perdido", -5, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 5);
	}
	else if (estado == FIN)
	{
		partida.dibuja();
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("ENHORABUENA, ¡Has triunfado!", -5, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 9);
	}
}  
// bien

void Coordinador::teclaEspecial(unsigned char key)
{
	if (estado == JUEGO)
		partida.teclaEspecial(key);
}

void Coordinador::mueve()
{
	if (estado == JUEGO)
	{
		partida.mueve();
}
void Coordinador::tecla(unsigned char key)
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
		estado = JUEGO;
	}
	else if (estado == GAMEOVER)
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
#include "Coordinador.h"
#include "ETSIDI.h"
#include "freeglut.h"
#include <iostream>
#include <stdlib.h>

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
		actmusic = true;
		gluLookAt(31.9f, 100.0f, 32.0f, // posicion del ojo
			32.0, 0.0, 32.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/arialbd.ttf", 12);
		ETSIDI::printxy("Chess", 1, 2);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/arialbd.ttf", 12);
		ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR", 15, -30);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", 10, -30);
		ETSIDI::printxy("PULSA LA TECLA -M- PARA ACTIVAR LA MUSICA", 5, -30);
		ETSIDI::printxy("Alonso, Adris, Anton y Manuel", 4, 1);
	}
	else if (estado == JUEGO)
	{
		actmusic = true;
		partida.dibuja();
	}
	else if (estado == PAUSA)
	{
		actmusic = true;
		partida.dibuja();
		ETSIDI::setTextColor(0, 1, 0);
		ETSIDI::setFont("fuentes/arialbd.ttf", 16);
		ETSIDI::printxy("PAUSA", -2, 10);
		ETSIDI::printxy("Pulsa C para continuar", -5, 5);
		
	}
	else if (estado == GAMEOVER)
	{
		partida.dibuja();
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("fuentes/arialbd.ttf", 16);
		ETSIDI::printxy("JAQUE MATE: Has perdido", -5, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 5);
	}
	else if (estado == FIN)
	{
		partida.dibuja();
		ETSIDI::setFont("fuentes/arialbd.ttf", 16);
		ETSIDI::printxy("ENHORABUENA, �Has ganado!", -5, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 9);
	}
}

void Coordinador::mouse(int button, int state, int x, int y)
{
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

void Coordinador::Tecla(unsigned char key) {
	
	if (estado == INICIO) {
		if (key == 'm') { 
			musica(actmusic); 
		}
		if (key == 'e') {
			partida.inicializa();
			ETSIDI::stopMusica();
			estado = JUEGO;
		}
		if (key == 's')exit(0);
	}
	else if (estado == JUEGO) {
		if (key == 'm') {
			musica(actmusic);
		}
		if (key == 'p') {
			estado = PAUSA;
			musica(actmusic);
		}
	}
	else if (estado == PAUSA) {
		estado == JUEGO;
	}
	else if (estado == GAMEOVER) {
		if (key == 'c')estado = INICIO;
	}
	else if (estado == FIN) {
		if (key == 'c')estado = INICIO;
	}
}

void Coordinador::musica(bool activarmusica) {
	if (activarmusica) {
		ETSIDI::playMusica("sonidos/ambiente.mp3", true);
	}
	else(ETSIDI::stopMusica());
}
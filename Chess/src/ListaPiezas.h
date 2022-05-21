#pragma once
#include "ETSIDI.h"
#include "pieza.h"
#include "rey.h"
#include "reina.h"
#include "caballo.h"
#include "Peon.h"
#include "Alfil.h"
#include "Torre.h"

#include <math.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>



#define MAX_PIEZAS 100


class ListaPiezas
{
private: 
	pieza* listaPiezas[MAX_PIEZAS];
	int nPiezas;
	

	bool enroqueBlanco = true;
	bool enroqueNegro = true;
	bool torreBlancaIzq = true;
	bool torreBlancaDrc = true;
	bool torreNegraIzq = true;
	bool torreNegraDrc = true;

	int PosiblesJaque = 0;

	bool jaqueBlanco;
	bool jaqueNegro;

	bool jaqueMateBlanco = false;
	bool jaqueMateNegro = false;

	color colorIA =	NEGRO;


public:
	coordenada movimientosPosibles[64];
	int nPosibles;

	coordenada coordenadaPintar[64];
	coordenada coordenadaComer[8];

	color proximoTurno = BLANCO;

	bool si = false;

	//Constructores
	ListaPiezas();
	~ListaPiezas();

	void crearPiezas();
	bool agregarPieza(pieza* pieza);
	void dibuja();
	void eliminar(int index);
	void eliminar(pieza* pieza);
	void borrarContenido();
	pieza* buscarPieza(int fila, int columna);


	void enroque(pieza* pieza, int fila, int columna);
	void anularEnroque(pieza* pieza, int fila, int columna);


	void moverPieza(pieza* pieza, int fila, int columna);
	bool movimientoLegal(pieza* pieza, int fila, int columna);
	bool movimientoLegalJaque(pieza* pieza, int fila, int columna); //esto es sin jaque posible
	bool comprobarTurno(pieza* pieza); //Devuelve el color del proximo movimiento
	bool comprobarColor(int index, coordenada coord);
	void movPosibles(pieza* aux);

	bool comprobarAlfil(pieza* pieza, int fila, int columna);
	bool comprobarTorre(pieza* pieza, int fila, int columna);
	bool comprobarReina(pieza* pieza, int fila, int columna);
	bool comprobarPeon(pieza* pieza, int fila, int columna);
	bool comprobarRey(pieza* pieza, int fila, int columna);

	bool comerPieza(pieza* pieza, int fila, int columna);
	void jaque(color Color);
	bool jaqueBool(color Color);
	bool jaquePosible(pieza* pieza,int fila, int columna);
	bool jaqueMate(color color);

	bool getJaqueMateBlanco() { return jaqueMateBlanco; }
	bool getJaqueMateNegro() { return jaqueMateNegro; }

	bool mirarCasilla(int fila, int columna);
	bool comprobarPieza(pieza* aux, int fila, int columna);


	//IA
	void setColorIA(color colorIA);
	void algoritmoIA();
	void algoritmoIAv2(int iteraciones, int profundidad=1);
	int evaluacion(int fila, int columna);
	int evaluacionCompleta();

	int alphaBetaMax(int alpha, int beta, int depthleft);
	int alphaBetaMin(int alpha, int beta, int depthleft);

	int maxi(pieza* pieza1,color color, int profundidad, int fila, int columna);
	int mini(pieza* pieza1,color color, int profundidad, int fila, int columna);

};


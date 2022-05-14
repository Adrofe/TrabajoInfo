#pragma once
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


#define MAX_PIEZAS 100


class ListaPiezas
{
private: 
	pieza* listaPiezas[MAX_PIEZAS];

	//Para simplificar
	//pieza* listaIA[MAX_PIEZAS];
	
	int nPiezas;
	color proximoTurno = BLANCO;

	bool jaqueBlanco = false;
	bool jaqueNegro = false;


	bool existeIA = false;
	color colorIA =	NEGRO;


public:
	coordenada coordenadaPintar[64];
	int nPosibles;
	coordenada coordenadaComer[8];

	friend class IA;

	bool si = false;

	//Constructores
	ListaPiezas();
	ListaPiezas(color colorIA);
	~ListaPiezas();

	void crearPiezas();
	bool agregarPieza(pieza* pieza);
	void dibuja();
	void eliminar(int index);
	void eliminar(pieza* pieza);
	void borrarContenido();
	pieza* buscarPieza(int fila, int columna);

	void moverPieza(pieza* pieza, int fila, int columna);
	bool movimientoLegal(pieza* pieza, int fila, int columna);
	bool comprobarTurno(pieza* pieza); //Devuelve el color del proximo movimiento
	bool comprobarColor(int index, coordenada coord);
	void movPosibles(pieza* aux);

	bool comprobarAlfil(pieza* pieza, int fila, int columna);
	bool comprobarTorre(pieza* pieza, int fila, int columna);
	bool comprobarReina(pieza* pieza, int fila, int columna);
	bool comprobarPeon(pieza* pieza, int fila, int columna);
	bool comprobarRey(pieza* pieza, int fila, int columna);

	bool comerPieza(pieza* pieza, int fila, int columna);
	void jaque();
	bool jaquePosible(pieza* pieza,int fila, int columna);


	bool mirarCasilla(int fila, int columna);
	bool comprobarPieza(pieza* aux, int fila, int columna);


	//IA
	void moverPiezaIA();
	coordenada coordenadaAleatoria(pieza* pieza);

};


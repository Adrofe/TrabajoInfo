#include "ListaPiezas.h"

ListaPiezas::ListaPiezas()
{
	


	coordenada c1("b", 6);
	coordenada c2("f", 5);
	coordenada c3("c", 2);
	coordenada c4("e", 3);
	coordenada c5("e", 5);
	coordenada c6("a", 3);
	coordenada c7("b", 2);
	coordenada c8("g", 7);
	rey* rey1 = new rey();
	rey* rey2 = new rey(BLANCO,c1);
	rey* rey3 = new rey(BLANCO, c2);
	reina* reina1 = new reina(BLANCO, c3);
	reina* reina2 = new reina(NEGRO, c4);
	caballo* caballo1 = new caballo(NEGRO, c5);
	caballo* caballo2 = new caballo(BLANCO, c6);
	Peon* peon1 = new Peon(BLANCO, c7);
	Peon* peon2 = new Peon(NEGRO, c8);
	for (int i = 0; i < MAX_PIEZAS; i++) {
		listaPiezas[i] = 0;
	}
	agregarPieza(rey1);
	agregarPieza(rey2);
	agregarPieza(rey3);
	agregarPieza(reina1);
	agregarPieza(reina2);
	agregarPieza(caballo1);
	agregarPieza(caballo2);
	agregarPieza(peon1);
	agregarPieza(peon2);
}

ListaPiezas::~ListaPiezas()
{
	for (int i = 0; i < MAX_PIEZAS; i++){
		delete listaPiezas[i];
	}
	nPiezas = 0;
}

bool ListaPiezas::agregarPieza(pieza* pieza)
{
	if (nPiezas < MAX_PIEZAS) {
		bool flag = 0;
		for (int i = 0; i < nPiezas; i++) {
			if (listaPiezas[i] == pieza) flag = 1;
		}
		if (flag == 0) listaPiezas[nPiezas++] = pieza; //ultimo puesto sin rellenar
		if (flag == 1) return false;
	}
	else {
		return false;		//capacidad maxima alcanzada
	}
	return true;

}

void ListaPiezas::dibuja()
{
	for (int i = 0; i < nPiezas; i++) {
		listaPiezas[i]->dibuja();
	}
}

void ListaPiezas::eliminar(int index)
{
	if ((index < 0) || (index >= nPiezas))
		return;
	delete listaPiezas[index];
	nPiezas--;
	for (int i = index; i < nPiezas; i++) {
		listaPiezas[i] = listaPiezas[i + 1];
	}
}

void ListaPiezas::eliminar(pieza* pieza)
{
	for (int i = 0; i < nPiezas; i++) {
		if (listaPiezas[i] == pieza) {
			eliminar(i);
			return;
		}
	}
}

void ListaPiezas::borrarContenido()
{
	nPiezas = 0;
	for (int i = 0; i < MAX_PIEZAS; i++) {
		delete listaPiezas[i];
	}
}

pieza* ListaPiezas::buscarPieza(int fila, int columna)
{
	static bool mismaCol= FALSE, mismaFil = FALSE;
	for (int i = 0; i < nPiezas; i++) {
		
		if (columna == listaPiezas[i]->getCoordenada().getColumna()) {
			mismaCol = TRUE;
		}
		else (mismaCol = FALSE);

		if (fila == listaPiezas[i]->getCoordenada().getFila()) {
			mismaFil = TRUE;
		}
		else(mismaFil = FALSE);

		if ((mismaCol == TRUE) && (mismaFil == TRUE)) {
			return listaPiezas[i];
		}
	}

	return nullptr;
}

void ListaPiezas::moverPieza(pieza* pieza, int fila, int columna)
{
	//Buscamos la pieza en el array
	int index = -1;
	for (int i = 0; i < nPiezas; i++) {
		if (listaPiezas[i] == pieza) {
			index = i;
		}
	}

	//Si encontramos la pieza cambiamos su fila y columna
	if (index != -1) {
		//Comprobamos si el movimiento es legal
		if (movimientoLegal(pieza, fila, columna)) {
			listaPiezas[index]->setFila(fila);
			listaPiezas[index]->setColumna(columna);
		}
		else {
			std::cout << "Movimiento ilegal de la pieza" << endl;
		}
		
	}

}

bool ListaPiezas::movimientoLegal(pieza* pieza, int fila, int columna)
{
	coordenada coordDestino(fila, columna);

	//Buscamos la pieza en el array
	int index = -1;
	for (int i = 0; i < nPiezas; i++) {
		if (listaPiezas[i] == pieza) {
			index = i;
		}
	}

	if (index != -1) {
		if (listaPiezas[index]->movimientoLegal(coordDestino)) {
			return true;
		}
		else return false;
	}


	return false;
}

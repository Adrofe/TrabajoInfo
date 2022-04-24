#include "ListaPiezas.h"

ListaPiezas::ListaPiezas()
{
	


	coordenada c1("a", 2);
	coordenada c2("b", 2);
	coordenada c3("c", 2);
	coordenada c4("d", 2);
	coordenada c5("e", 2);
	coordenada c6("f", 2);
	coordenada c7("g", 2);
	coordenada c8("h", 2);
	coordenada c9("a", 1);
	coordenada c10("b", 1);
	coordenada c11("c", 1);
	coordenada c12("d", 1);
	coordenada c13("e", 1);
	coordenada c14("f", 1);
	coordenada c15("g", 1);
	coordenada c16("h", 1);

	coordenada c17("a", 7);
	coordenada c18("b", 7);
	coordenada c19("c", 7);
	coordenada c20("d", 7);
	coordenada c21("e", 7);
	coordenada c22("f", 7);
	coordenada c23("g", 7);
	coordenada c24("h", 7);
	coordenada c25("a", 8);
	coordenada c26("b", 8);
	coordenada c27("c", 8);
	coordenada c28("d", 8);
	coordenada c29("e", 8);
	coordenada c30("f", 8);
	coordenada c31("g", 8);
	coordenada c32("h", 8);



	rey* rey1 = new rey(BLANCO,c13);
	rey* rey2 = new rey(NEGRO,c29);
	
	reina* reina1 = new reina(BLANCO, c12);
	reina* reina2 = new reina(NEGRO, c28);

	caballo* caballo1 = new caballo(BLANCO, c10);
	caballo* caballo2 = new caballo(BLANCO, c15);
	caballo* caballo3 = new caballo(NEGRO, c26);
	caballo* caballo4 = new caballo(NEGRO, c31);

	Alfil* alfil1 = new Alfil(BLANCO, c11);
	Alfil* alfil2 = new Alfil(BLANCO, c14);
	Alfil* alfil3 = new Alfil(NEGRO, c27);
	Alfil* alfil4 = new Alfil(NEGRO, c30);

	Torre* torre1 = new Torre(BLANCO, c9);
	Torre* torre2 = new Torre(BLANCO, c16);
	Torre* torre3 = new Torre(NEGRO, c25);
	Torre* torre4 = new Torre(NEGRO, c32);

	
	Peon* peon1 = new Peon(BLANCO, c1);
	Peon* peon2 = new Peon(BLANCO, c2);
	Peon* peon3 = new Peon(BLANCO, c3);
	Peon* peon4 = new Peon(BLANCO, c4);
	Peon* peon5 = new Peon(BLANCO, c5);
	Peon* peon6 = new Peon(BLANCO, c6);
	Peon* peon7 = new Peon(BLANCO, c7);
	Peon* peon8 = new Peon(BLANCO, c8);
	Peon* peon9 = new Peon(NEGRO, c19);
	Peon* peon10 = new Peon(NEGRO, c20);
	Peon* peon11 = new Peon(NEGRO, c21);
	Peon* peon12 = new Peon(NEGRO, c22);
	Peon* peon13 = new Peon(NEGRO, c23);
	Peon* peon14 = new Peon(NEGRO, c24);
	Peon* peon15 = new Peon(NEGRO, c17);
	Peon* peon16 = new Peon(NEGRO, c18);




	for (int i = 0; i < MAX_PIEZAS; i++) {

		listaPiezas[i] = 0;
	}

	agregarPieza(rey1);
	agregarPieza(rey2);
	agregarPieza(caballo1);
	agregarPieza(caballo2);
	agregarPieza(caballo3);
	agregarPieza(caballo4);
	agregarPieza(torre1);
	agregarPieza(torre2);
	agregarPieza(torre3);
	agregarPieza(torre4);
	agregarPieza(alfil1);
	agregarPieza(alfil2);
	agregarPieza(alfil3);
	agregarPieza(alfil4);
	agregarPieza(reina1);
	agregarPieza(reina2);
	agregarPieza(peon1);
	agregarPieza(peon2);
	agregarPieza(peon3);
	agregarPieza(peon4);
	agregarPieza(peon5);
	agregarPieza(peon6);
	agregarPieza(peon7);
	agregarPieza(peon8);
	agregarPieza(peon9);
	agregarPieza(peon10);
	agregarPieza(peon11);
	agregarPieza(peon12);
	agregarPieza(peon13);
	agregarPieza(peon14);
	agregarPieza(peon15);
	agregarPieza(peon16);
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

		if (comprobarTurno(pieza)){
			//Comprobamos si el movimiento es legal
			if (movimientoLegal(pieza, fila, columna)) {
				listaPiezas[index]->setFila(fila);
				listaPiezas[index]->setColumna(columna);
				//Cambiamos el color del proximo turno
				if (proximoTurno == BLANCO) {
					proximoTurno = NEGRO;
				}
				else { proximoTurno = BLANCO; }
				
			}
			else {
				std::cout << "Movimiento ilegal de la pieza" << endl;
			}
		}
		else {
			std::cout << "No mueve este color" << endl;
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
			for (int a = 0; a < 32; a++) {
				if ((coordDestino.getColumna() == listaPiezas[a]->getCoordenada().getColumna()) && (coordDestino.getFila() == listaPiezas[a]->getCoordenada().getFila())) {
					if (listaPiezas[index]->getColor() == listaPiezas[a]->getColor()) {
						return false;
					}
				} 
				
			
			}
			return true;
		}
		else return false;
	}



	return false;
}

bool ListaPiezas::comprobarTurno(pieza* pieza)
{
	if (pieza->getColor() == proximoTurno) {
		return true;
	}
	else return false;
}


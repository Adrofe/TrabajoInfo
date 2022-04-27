#include "ListaPiezas.h"

ListaPiezas::ListaPiezas()
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			matrizVacias[i][j] = false;
		}
	}


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

	casillasVacias();
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
	 bool mismaCol= FALSE, mismaFil = FALSE;
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

void ListaPiezas::casillasVacias()
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			matrizVacias[i][j] = false;
		}
	}
	coordenada aux;

	int fila = 0;
	int columna = 0;

	for (int i = 0; i < nPiezas; i++) {
	
		fila = (listaPiezas[i]->getCoordenada().getFila()) -1;
		columna = (listaPiezas[i]->getCoordenada().getColumna()) -1;
		matrizVacias[fila][columna] = true;

	}
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
	casillasVacias();

	for (int p = 8; p >= 0; p--) {
		for (int n = 0; n < 8; n++) {
			std::cout << matrizVacias[p][n] << " ";
		}
		std::cout << endl;
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
		if (comprobarColor(index, coordDestino)) {
			if (listaPiezas[index]->movimientoLegal(coordDestino)) {
				if (comprobarPieza(listaPiezas[index], fila, columna)) {
					return true;
				}
				//else return false;
			}
			else {
				return false;
			}
		}
		else {
			std::cout << "Hay una pieza del mismo color" << endl;
			return false;
		}
		
	}
	//else return false;
	return false;
}

bool ListaPiezas::comprobarTurno(pieza* pieza)
{
	if (pieza->getColor() == proximoTurno) {
		return true;
	}
	else return false;
}

bool ListaPiezas::comprobarColor(int index, coordenada coord)
{
	
	for (int a = 0; a < nPiezas; a++) {
		if (listaPiezas[a]->getCoordenada()==coord) {
			if (listaPiezas[index]->getColor() == listaPiezas[a]->getColor()) {
				return false;
			}else return false;
		}
		else return true;
	}
	
	//return true;
}

void ListaPiezas::movPosibles(pieza* aux)
{
	int a = 1;
	if (comprobarTurno(aux)) {
		for (int i = 1; i < 9; i++) {
			for (int j = 1; j < 9; j++) {
				if (movimientoLegal(aux, i, j)) {
					coordenadaPintar[a] = { i,j };
					std::cout << i << " " << j << endl;
					a++;
					si = true;
				}
			}
		}

		for (int b = a; b < 64; b++) {
			coordenadaPintar[b] = { -1, -1 };
		}
	}
}


bool ListaPiezas::comprobarAlfil(pieza* pieza, int fila, int columna)
{
	coordenada destino(fila,columna);

	int j = 0;
	int i = 0;
	int s = 0;
	int l = 0;
	std::cout << "Comprueba alfil" << endl;
	if (abs(destino.getColumna() - pieza->getCoordenada().getColumna()) == abs(destino.getFila() - pieza->getCoordenada().getFila())) { //movimento en lateral
		std::cout << "diagonal" << endl;
		if (((destino.getColumna() - pieza->getCoordenada().getColumna()) > 0) && ((destino.getFila() - pieza->getCoordenada().getFila()) > 0)) { // arriba derecha
			for (i = pieza->getCoordenada().getFila(), j = pieza->getCoordenada().getColumna() ; (i < destino.getFila()), (j < destino.getColumna()); i++, j++) {
				if (mirarCasilla(i,j)) {
					std::cout << "falso1" << endl;
					return false;
				}
			}
			return true;
			std::cout << "retorno1" << endl;
		}

		else if (((destino.getColumna() - pieza->getCoordenada().getColumna()) < 0) && ((destino.getFila() - pieza->getCoordenada().getFila()) < 0)) {//abajo izq
			for (s = pieza->getCoordenada().getFila(), l = pieza->getCoordenada().getColumna(); (s > destino.getFila()), (l > destino.getColumna()); s--, l--) {
				if (mirarCasilla(s, l)) {
					
					std::cout << "falso2" << endl;
					return false;
				}
			}
			return true;
			std::cout << "retorno2" << endl;
		}
		
	}


	//Movimiento en diagonal hacia la izquierda
	else if ((destino.getColumna() - pieza->getCoordenada().getColumna()) == (pieza->getCoordenada().getFila() - destino.getFila())) {
		 if (((destino.getColumna() - pieza->getCoordenada().getColumna()) < 0) && ((destino.getFila() - pieza->getCoordenada().getFila()) > 0)) {
			for (i = pieza->getCoordenada().getFila(), j = pieza->getCoordenada().getColumna(); (i < destino.getFila()), (j > destino.getColumna()); i++, j--) { //arriba izq
				if (mirarCasilla(i, j)) {
					
					std::cout << "falso3" << endl;
					return false;
				}
			}
			return true;
			std::cout << "retorno3" << endl;
		 }

		else if (((destino.getColumna() - pieza->getCoordenada().getColumna()) > 0) && ((destino.getFila() - pieza->getCoordenada().getFila()) < 0)) {
			for (s = pieza->getCoordenada().getFila(), l = pieza->getCoordenada().getColumna(); (s > destino.getFila()), (l < destino.getColumna()); s--, l++) {// abajo drcha
				if (mirarCasilla(s, l)) {
					
					std::cout << "falso4" << endl;
					return false;
				}
			}
			return true;
			std::cout << "retorno4" << endl;
		}
	}
	else return true;

}

bool ListaPiezas::comprobarTorre(pieza* pieza, int fila, int columna)
{
	int ib = 0;
	int pd = 0;
	coordenada coordInicio = pieza->getCoordenada();
	coordenada destino(fila,columna);

	if (destino.getFila() - coordInicio.getFila() >= 0) {
		for ( ib = coordInicio.getFila() + 1; ib <= destino.getFila(); ib++) {
			std::cout << ib << endl;
			if (mirarCasilla(ib, coordInicio.getColumna())) {
				return false;
			}
			std::cout << ib << endl;
		}

		if (destino.getColumna() - coordInicio.getColumna() >= 0) {
			for (pd = coordInicio.getColumna() + 1; pd <= destino.getColumna(); pd++) {
				std::cout << pd << endl;
				if (mirarCasilla(coordInicio.getFila(), pd)) {
					return false;
				}
				std::cout << pd << endl;
			}
		}
		return true;
	}
	/*
	//Movimiento en la misma fila
	else if (coordInicio.getFila() == destino.getFila()) {
		return true;
	}
	//Movimiento en la misma columna
	else if (coordInicio.getColumna() == destino.getColumna()) {
		return true;
	}
	else return false;
	*/
	return true;
}

bool ListaPiezas::mirarCasilla(int fila, int columna)
{
	coordenada casilla(fila, columna);

	for (int i = 0; i < nPiezas; i++) {

		if (casilla == listaPiezas[i]->getCoordenada()) {
			std::cout << "si hay ficha en: " << fila << " " << columna << endl;
			return true;
		}

	}
 return false;
}

bool ListaPiezas::comprobarPieza(pieza* aux, int fila, int columna)
{
	
	if (aux->getTipo() == ALFIL) return comprobarAlfil(aux, fila, columna);
	else if (aux->getTipo() == TORRE) return comprobarTorre(aux, fila, columna);
}



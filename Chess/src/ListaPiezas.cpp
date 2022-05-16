#include "ListaPiezas.h"

ListaPiezas::ListaPiezas()
{
	crearPiezas();
	ofstream archivo;//modo escritura
	
	archivo.open("Historial.txt", ios::out);//abrir archivo llamado Historial.txt, si este archivo ya existe, se reemplaza, es decir que cada vez que juguemos una partida nueva se borrar� el contenido de la anterior
	

	if (archivo.fail()) {//comprobar si el archivo se ha abierto correctamente
		cout << "no se pudo abrir el archivo";
		exit(1);
	}



	archivo.close();//cerramos el archivo
}

ListaPiezas::ListaPiezas(color colorIA)
{
	this->colorIA = colorIA;
	crearPiezas();

	for (int i = 0; i < nPiezas; i++) {
		if (listaPiezas[i]->getColor() == colorIA) {

		}
	}

}

ListaPiezas::~ListaPiezas()
{
	for (int i = 0; i < MAX_PIEZAS; i++){
		delete listaPiezas[i];
	}
	nPiezas = 0;
}

void ListaPiezas::crearPiezas()
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

	coordenada fantasma("z", 100);



	rey* rey1 = new rey(BLANCO, c13);
	rey* rey2 = new rey(NEGRO, c29);

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

	Peon* FANTASMA_ABAJO = new Peon(NONE, fantasma); //creamos una pieza fantasma, porque nos daba un error al comer la ultima pieza del array. Esta esta pintada fuera de la vision.
	Peon* FANTASMA_ARRIBA = new Peon(NONE, fantasma);



	for (int i = 0; i < MAX_PIEZAS; i++) {

		listaPiezas[i] = 0;
	}

	agregarPieza(FANTASMA_ARRIBA);
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
	agregarPieza(FANTASMA_ABAJO);


	// inicializamos los booleamos de jaque a false
	jaqueBlanco = false;
	jaqueNegro  = false;

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
	coordenada casilla(fila, columna);
	for (int i = 0; i < nPiezas; i++) {
		
		if (casilla == listaPiezas[i]->getCoordenada()) {
			return listaPiezas[i];
		}
	}

	return nullptr;
}


void ListaPiezas::moverPieza(pieza* pieza1, int fila, int columna)
{
	//Buscamos la pieza en el array
	int index = -1;
	int indexDes = -1;

	pieza* piezaDestino = buscarPieza(fila,columna);
	for (int i = 0; i < nPiezas; i++) {
		if (listaPiezas[i] == pieza1) {
			index = i;
		}
		if (listaPiezas[i] == piezaDestino) {
			indexDes = i;
		}
	}
	if (index != -1) {
		if (pieza1 != nullptr) {
			if (comprobarTurno(pieza1)) {
				//Comprobamos si el movimiento es legal
				
				if (movimientoLegal(pieza1, fila, columna)) {
					//if(jaqueBlanco || jaqueNegro)
					//if (jaquePosible(pieza1, fila, columna)) {
						if (comerPieza(pieza1, fila, columna)) eliminar(listaPiezas[indexDes]);
						pieza1->setFila(fila);
						pieza1->setColumna(columna);
						//movimiento = pieza1->guardarHistorial(fila,columna);
						//char fil = fila;
						//char col = columna;
						pieza1->guardarHistorial(fila,columna);
						//archivo << movimiento << " ";
						jaque(BLANCO);
						jaque(NEGRO);
						//Cambiamos el color del proximo turno
						if (proximoTurno == BLANCO) {
							proximoTurno = NEGRO;
						}
						else { proximoTurno = BLANCO; }
					//}

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

	
}

bool ListaPiezas::movimientoLegal(pieza* pieza1, int fila, int columna)
{
	coordenada coordDestino(fila, columna);
	pieza* piezaDestino;
	piezaDestino = buscarPieza(fila, columna);


	//Buscamos la pieza en el array
	int index = -1;

	for (int i = 0; i < nPiezas; i++) {
		if (listaPiezas[i] == pieza1) {
			index = i;
		}
	}



	if (index != -1) {

		//comprueba que el color sea diferente al sitio al que te quieres mover
		for (int a = 0; a < nPiezas; a++) {
			if (coordDestino == listaPiezas[a]->getCoordenada()) {
				if (listaPiezas[index]->getColor() == listaPiezas[a]->getColor()) {
					return false;
				}
			}
		}
		if (comprobarColor(index, coordDestino)) {
			if (listaPiezas[index]->movimientoLegal(coordDestino)) {
				if (comprobarPieza(listaPiezas[index], fila, columna)) {
					//if (jaqueBlanco || jaqueNegro) {
						if (jaquePosible(listaPiezas[index], fila, columna)) {

							return true;
						}
					//}
					//else return true;

				}
				
				//else return false;
			}
			else {
				return false;
			}
		}
		else {
			//std::cout << "Hay una pieza del mismo color" << endl;
			return false;
		}
		
	}
	//else return false;
	return false;
}

bool ListaPiezas::movimientoLegalJaque(pieza* pieza1, int fila, int columna)
{
	coordenada coordDestino(fila, columna);
	pieza* piezaDestino;
	piezaDestino = buscarPieza(fila, columna);


	//Buscamos la pieza en el array
	int index = -1;

	for (int i = 0; i < nPiezas; i++) {
		if (listaPiezas[i] == pieza1) {
			index = i;
		}
	}



	if (index != -1) {

		//comprueba que el color sea diferente al sitio al que te quieres mover
		for (int a = 0; a < nPiezas; a++) {
			if (coordDestino == listaPiezas[a]->getCoordenada()) {
				if (listaPiezas[index]->getColor() == listaPiezas[a]->getColor()) {
					return false;
				}
			}
		}
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
			//std::cout << "Hay una pieza del mismo color" << endl;
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
	nPosibles = 0;
	int a = 1;
	int b = 1;
	if (aux != nullptr) {
		if (comprobarTurno(aux)) {
			for (int i = 1; i < 9; i++) {
				for (int j = 1; j < 9; j++) {
					
					 if (movimientoLegal(aux, i, j)) {

						 coordenada coord(i, j);
						 movimientosPosibles[nPosibles++] = { i,j };


						 if (buscarPieza(i, j) != nullptr) {
							 coordenadaComer[b] = { i,j };
							 b++;
						 }
						 else {
							 coordenadaPintar[a] = { i,j };
							// std::cout << i << " " << j << endl;
							 a++;
						 }
						si = true;
					}
				}
			}

			for (int c = a; c < 64; c++) {
				coordenadaPintar[c] = { -1,-1 };
			}
			
			for (int d = b; d < 8; d++) {
				coordenadaComer[d] = { -1,-1 };
			}
			
		}
	}
	nPosibles = a;
}


bool ListaPiezas::comprobarAlfil(pieza* pieza, int fila, int columna)
{
	coordenada destino(fila,columna);
	coordenada restaDrcha = destino - pieza->getCoordenada();
	coordenada restaIzq = pieza->getCoordenada() - destino;

	int j = 0;
	int i = 0;
	int s = 0;
	int l = 0;
	


	if (((restaDrcha.getColumna() >= 0) && (restaDrcha.getFila()) > 0)) { // arriba derecha
		for (i = pieza->getCoordenada().getFila() + 1, j = pieza->getCoordenada().getColumna() + 1 ; (i < destino.getFila()), (j < destino.getColumna()); i++, j++) {
			if (buscarPieza(i,j) != nullptr){
				return false;	
			//if (mirarCasilla(i,j)) {
				//return false;
			}
		}
	}

	if (((restaIzq.getColumna() >= 0) && (restaIzq.getFila()) > 0)) {//abajo izq
		for (s = pieza->getCoordenada().getFila() - 1, l = pieza->getCoordenada().getColumna() - 1; (s > destino.getFila()), (l > destino.getColumna()); s--, l--) {
			if (mirarCasilla(s, l)) {					
				return false;
			}
		}
	}
		
		if (((restaIzq.getColumna() >= 0) && (restaDrcha.getFila()) > 0)) { //arriba izq
		for (i = pieza->getCoordenada().getFila() + 1, j = pieza->getCoordenada().getColumna() - 1; (i < destino.getFila()), (j > destino.getColumna()); i++, j--) {
			if (mirarCasilla(i, j)) {
				return false;
			}
		}
		}

		if (((restaDrcha.getColumna() >= 0) && (restaIzq.getFila()) > 0)) {// abajo drcha
		for (s = pieza->getCoordenada().getFila() - 1, l = pieza->getCoordenada().getColumna() + 1; (s > destino.getFila()), (l < destino.getColumna()); s--, l++) {
			if (mirarCasilla(s, l)) {
				return false;
			}
		}
		}
		return true;
}

bool ListaPiezas::comprobarTorre(pieza* pieza, int fila, int columna)
{
	int ib = 0;
	int pd = 0;
	int fd = 0;
	int px = 0;

	coordenada coordInicio = pieza->getCoordenada();
	coordenada destino(fila,columna);

	if (destino.getFila() - coordInicio.getFila() >= 0) {
		for (ib = coordInicio.getFila() + 1; ib < destino.getFila(); ib++) {
			if (mirarCasilla(ib, coordInicio.getColumna())) {
				return false;
			}
		}
	}

	if (destino.getColumna() - coordInicio.getColumna() >= 0) {
		for (pd = coordInicio.getColumna() + 1; pd < destino.getColumna(); pd++) {
			if (mirarCasilla(coordInicio.getFila(), pd)) {
				return false;
			}
		}
	}

	if (coordInicio.getColumna() - destino.getColumna() >= 0) {
		for (fd = coordInicio.getColumna() - 1; fd > destino.getColumna(); fd--) {
			if (mirarCasilla(coordInicio.getFila(), fd)) {
				return false;
			}
		}
	}

	if (coordInicio.getFila() - destino.getFila() >= 0) {
		for (px = coordInicio.getFila() - 1; px > destino.getFila(); px--) {
			if (mirarCasilla(px, coordInicio.getColumna())) {
				return false;
			}
		}
	}

	return true;
	
	
}

bool ListaPiezas::comprobarReina(pieza* pieza, int fila, int columna)
{
	coordenada destino(fila, columna);
	coordenada resta = destino - pieza->getCoordenada();

	if (abs(destino.getColumna() - pieza->getCoordenada().getColumna()) == abs(destino.getFila() - pieza->getCoordenada().getFila())) {
		return comprobarAlfil(pieza, fila, columna);
	}

	if (pieza->getCoordenada().getFila() == destino.getFila()) {
		return comprobarTorre(pieza, fila, columna);
	}

	if (pieza->getCoordenada().getColumna() == destino.getColumna()) {
		return comprobarTorre(pieza, fila, columna);;
	}

	return true;

}

bool ListaPiezas::comprobarPeon(pieza* pieza, int fila, int columna)
{
	coordenada destino(fila, columna);
	bool flag = false;

	if (pieza->getColor() == BLANCO)
	{


		if (((destino.getColumna() - pieza->getCoordenada().getColumna()) == 1) && ((destino.getFila() - pieza->getCoordenada().getFila()) == 1)) {
			if (mirarCasilla(fila, columna)) return true;
			else return false;
		}
		if (((destino.getColumna() - pieza->getCoordenada().getColumna()) == -1) && ((destino.getFila() - pieza->getCoordenada().getFila()) == 1)) {
			if (mirarCasilla(fila, columna)) return true;
			else return false;
		}

		if (mirarCasilla(pieza->getCoordenada().getFila() + 1, pieza->getCoordenada().getColumna())) return false;

		if ((pieza->getCoordenada().getFila()) == (2))
		{

			if (mirarCasilla(pieza->getCoordenada().getFila() + 2, pieza->getCoordenada().getColumna())) flag = true;
			if (mirarCasilla(pieza->getCoordenada().getFila() + 1, pieza->getCoordenada().getColumna())) return false;

			if (destino.getFila() == 3) return true;

			else if (flag) return false;

			
		}

		

		flag = false;
		return true;
	}
		else {



			if (((destino.getColumna() - pieza->getCoordenada().getColumna()) == -1) && ((destino.getFila() - pieza->getCoordenada().getFila()) == -1)) {
				if (mirarCasilla(fila, columna)) return true;
				else return false;
			}
			if (((destino.getColumna() - pieza->getCoordenada().getColumna()) == 1) && ((destino.getFila() - pieza->getCoordenada().getFila()) == -1)) {
				if (mirarCasilla(fila, columna)) return true;
				else return false;
			}

			if (mirarCasilla(pieza->getCoordenada().getFila() - 1, pieza->getCoordenada().getColumna())) return false;

			if ((pieza->getCoordenada().getFila()) == (7))
			{
				if (mirarCasilla(pieza->getCoordenada().getFila() - 2, pieza->getCoordenada().getColumna())) flag = true;
				if (mirarCasilla(pieza->getCoordenada().getFila() - 1, pieza->getCoordenada().getColumna())) return false;

				if (destino.getFila() == 6) return true;

				else if (flag) return false;
			}


			flag = false;
			return true;
		}
	

	
}

bool ListaPiezas::comprobarRey(pieza* pieza, int fila, int columna)
{
	coordenada destino(fila, columna);
	coordenada inicio(pieza->getCoordenada().getFila(), pieza->getCoordenada().getColumna());
	color colorReyMov = pieza->getColor();
	int index;

	for (int i = 0; i < nPiezas; i++) {
		if ((listaPiezas[i]->getTipo() == REY)&&(listaPiezas[i]->getColor()!=colorReyMov)) {
			index = i;
		}
	}
	coordenada reyEnemigo = listaPiezas[index]->getCoordenada();


	if (mirarCasilla(fila, columna)) {
		if (buscarPieza(fila, columna) != nullptr)
			if (buscarPieza(fila, columna)->getColor() !=pieza->getColor()) return TRUE;
		return false;
	}
	else {
		//Miramos las casillas del rey enemigo una a una
		for (int i = reyEnemigo.getFila() + 1; i >= reyEnemigo.getFila() - 1; i--) {
			for (int j = reyEnemigo.getColumna() - 1; j <= reyEnemigo.getColumna() + 1; j++) {
				coordenada aux(i, j);
				if (destino == aux) return false;
			}
		}
	}

	return true;
}

bool ListaPiezas::comerPieza(pieza* pieza1, int fila, int columna) // se tiene que implementar en mover pieza
{
	coordenada destino(fila, columna);
	pieza* piezaDestino;
	piezaDestino = buscarPieza(fila, columna);

	//Buscamos la pieza en el array
	int index = -1;
	for (int i = 0; i < nPiezas; i++) {
		if (listaPiezas[i] == piezaDestino) {
			index = i;
		}
	}


	//Comprobamos el color de la pieza de destino
	if (mirarCasilla(fila, columna)) {
		if (pieza1->getColor() != listaPiezas[index]->getColor()) {
			//Comprobamos si no es el rey
			//if (listaPiezas[index]->getTipo() != REY) {
				return true;

			//}
		}
	}
	 return false;

}

void ListaPiezas::jaque(color Color)
{
	pieza* aux;
	coordenada CoordRey(-1,-1);

	if (Color == BLANCO) { jaqueNegro = FALSE; }
	if (Color == NEGRO) { jaqueBlanco = FALSE; }

	for (int i = 0; i < nPiezas; i++) {
		if (listaPiezas[i]->getTipo() == REY && listaPiezas[i]->getColor() != Color) {
			CoordRey.setCol(listaPiezas[i]->getCoordenada().getColumna());
			CoordRey.setFil(listaPiezas[i]->getCoordenada().getFila());
		}
	}

	for (int i = 0; i < nPiezas; i++) {
		if (movimientoLegalJaque(listaPiezas[i], CoordRey.getFila(), CoordRey.getColumna())){

					if (Color == BLANCO) { jaqueNegro = TRUE; }
					if (Color == NEGRO) { jaqueBlanco = TRUE; }
					std::cout << " hay jaque "<< jaqueNegro<< " " << jaqueBlanco << endl;
		}

	}

}

bool ListaPiezas::jaqueBool(color Color)
{
	pieza* aux;
	coordenada CoordRey(-1, -1);


	for (int i = 0; i < nPiezas; i++) {
		if (listaPiezas[i]->getTipo() == REY && listaPiezas[i]->getColor() != Color) {
			CoordRey.setCol(listaPiezas[i]->getCoordenada().getColumna());
			CoordRey.setFil(listaPiezas[i]->getCoordenada().getFila());
		}
	}

	for (int i = 0; i < nPiezas; i++) {
		if (movimientoLegalJaque(listaPiezas[i], CoordRey.getFila(), CoordRey.getColumna())) {

			return true;
		}

	}
	return false;
}

bool ListaPiezas::jaquePosible(pieza* pieza, int fila, int columna) 
{
	coordenada CoordApoyo;

	CoordApoyo.setFil(pieza->getCoordenada().getFila());
	CoordApoyo.setCol(pieza->getCoordenada().getColumna());

	pieza->setFila(fila);
	pieza->setColumna(columna);
	if (jaqueBool(BLANCO)) { 

		pieza->setFila(CoordApoyo.getFila());
		pieza->setColumna(CoordApoyo.getColumna());

		if (pieza->getColor() == BLANCO) return true;

		jaqueBlanco = FALSE;
		return false;
	}
	if (jaqueBool(NEGRO)) { 

		pieza->setFila(CoordApoyo.getFila());
		pieza->setColumna(CoordApoyo.getColumna());

		if (pieza->getColor() == NEGRO) return true;

		jaqueNegro = FALSE;
		return false;

	}
					
		pieza->setFila(CoordApoyo.getFila());
		pieza->setColumna(CoordApoyo.getColumna());
			

	return true;
}




bool ListaPiezas::mirarCasilla(int fila, int columna)
{
	coordenada casilla(fila, columna);

	for (int i = 0; i < nPiezas; i++) {

		if (casilla == listaPiezas[i]->getCoordenada()) {
			return true;
		}

	}
 return false;
}

bool ListaPiezas::comprobarPieza(pieza* aux, int fila, int columna)
{
	//if (buscarPieza(fila, columna) != nullptr)
	//	if (buscarPieza(fila, columna)->getTipo() == REY) return FALSE;

	if (aux->getTipo() == ALFIL) return comprobarAlfil(aux, fila, columna);
	else if (aux->getTipo() == TORRE) return comprobarTorre(aux, fila, columna);
	else if (aux->getTipo() == REINA) return comprobarReina(aux, fila, columna);
	else if (aux->getTipo() == PEON) return comprobarPeon(aux, fila, columna);
	else if (aux->getTipo() == REY) return comprobarRey(aux, fila, columna);
		
}

void ListaPiezas::moverPiezaIA()
{
	int piezasIA[20];
	int nIA = 0;
	srand(time(NULL));

	//Creamos una lista de piezas con las piezas de la IA
	for (int i = 0; i < nPiezas; i++) {
		if (listaPiezas[i]->getColor() == colorIA) {
			piezasIA[nIA] = i;
			nIA++;
		}
	}

	int piezaAleatoria;
	coordenada coordenadaRandom;

	//Escogemos una pieza aleatoria

	bool flag = true;
	while (flag) {

		piezaAleatoria = rand() * 33;
		piezaAleatoria = (rand() % nIA);

		movPosibles(listaPiezas[piezasIA[piezaAleatoria]]);


		int random;
		//if (nPosibles > 0) {
			random = rand() * 33;
			random = (rand() % nPosibles);
			cout << random << endl;

			coordenadaRandom = movimientosPosibles[random];

			std::cout <<"Mov Posible f"<< coordenadaRandom.getFila() << " c " << coordenadaRandom.getColumna() << endl;


			if (movimientoLegal(listaPiezas[piezasIA[piezaAleatoria]], coordenadaRandom.getFila(), coordenadaRandom.getFila()) == TRUE) flag = false;
			std::cout << "Iteracion finalizada" << endl;
		//}

	}
	moverPieza(listaPiezas[piezasIA[piezaAleatoria]], coordenadaRandom.getFila(), coordenadaRandom.getColumna());
	
}

coordenada ListaPiezas::coordenadaAleatoria(pieza* aux)
{
	coordenada coordenada;
	return coordenada;
	
}

void ListaPiezas::algoritmoIA(int iteraciones, int profundidad)
{
	int iter = 0;
	//while (iter < iteraciones) {

		int puntuacionOptima = -999;
		int filaOptima = -1;
		int columnaOptima = -1;
		int indexOptimo = 0;

		
		for (int i = 0; i < nPiezas; i++) {
			//Recorremos todas las piezas de la IA
			if (listaPiezas[i]->getColor() == colorIA) {
				movPosibles(listaPiezas[i]);
				for (int j = 0; j < nPosibles; j++) {
					int punt=0;
					punt = evaluacion(movimientosPosibles[j]) + listaPiezas[i]->getValorPos(movimientosPosibles[j].getFila()-1, movimientosPosibles[j].getColumna()-1);
					//std::cout << "Punt" << punt << " Movimiento de " << listaPiezas[i]->getTipo() << " a " << movimientosPosibles[j].getFila() << " " << movimientosPosibles[j].getColumna() << endl;
					if (punt > puntuacionOptima) {
						if (movimientoLegal(listaPiezas[i], movimientosPosibles[j].getFila(), movimientosPosibles[j].getColumna())) {

							puntuacionOptima = punt;
							columnaOptima = movimientosPosibles[j].getColumna();
							filaOptima = movimientosPosibles[j].getFila();
							indexOptimo = i;
							std::cout << "Puntuacion optima: " << puntuacionOptima << " FilaOptima: " << filaOptima << " ColumnaOptima: " << columnaOptima << endl;
							std::cout << "Pieza: " << listaPiezas[i]->getTipo() << " coordenada: " << listaPiezas[i]->getCoordenada().getFila() << " " << listaPiezas[i]->getCoordenada().getColumna() << endl;
						}
					}
				}
			}
		}

		moverPieza(listaPiezas[indexOptimo], filaOptima, columnaOptima);



		iter++;
	//}



}

int ListaPiezas::evaluacion(coordenada coord)
{
	int fila = coord.getFila();
	int columna = coord.getColumna();

	if (mirarCasilla(fila,columna)) {
		return buscarPieza(fila, columna)->getValor();
	}
	else return 0;
}

/* Valores matem�ticos para evaluar los puntos con la ia IA*

PARTES CON UNOS PUNTOS INICIALES SI PUEDES COMER SUMAS PUNTOS SI TE PUEDEN COMER LOS RESTAS.

 peon:
   * Por cada peon +10 puntos
   * Por cada casilla que un peon avanza +1 puntos
   * ademas de ver a quienes puede comer
 caballo:
   * Por cada caballo +30 puntos
   * Si est� cerca o lejos del centro del tablero +-5 puntos y si puede comer a los que mas puntos dan
 alfil:
   * Por cada alfil +30 puntos
   * A�adir un punto por cada casilla a la que se pueda mover el alfil y si puede comer a los que mas puntos dan
 torre:
   * Por cada torre +50 puntos
   * A�adir un punto por cada casilla a la que se pueda mover la torre y si puede comer a los que mas puntos dan
 dama:
   * Por cada dama +90 puntos
   * Si est� cerca o lejos del centro del tablero +-5 puntos ademas de poder comer piezas eso da puntos
  

  FALTA TODA LA INTERFAZ DE LA PANTALLA PONIENDO UN TIEMPO O PONIENDO Y DE QUIEN ES EL TURNO

*/


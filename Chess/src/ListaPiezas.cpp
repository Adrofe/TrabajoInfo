#include "ListaPiezas.h"
#include "ETSIDI.h"
#include<windows.h>

ListaPiezas::ListaPiezas()
{
	for (int i = 0; i < MAX_PIEZAS; i++) {

		listaPiezas[i] = 0;
	}

	ofstream archivo;//modo escritura
	
	archivo.open("Historial.txt", ios::out);//abrir archivo llamado Historial.txt, si este archivo ya existe, se reemplaza, es decir que cada vez que juguemos una partida nueva se borrará el contenido de la anterior

	if (archivo.fail()) {//comprobar si el archivo se ha abierto correctamente
		cout << "no se pudo abrir el archivo";
		exit(1);
	}

	archivo.close();//cerramos el archivo
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
	borrarContenido();
	proximoTurno = BLANCO;

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
		if(listaPiezas[i]!=0)
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
			ETSIDI::play("sonidos/comer.mp3");
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

void ListaPiezas::enroque(pieza* pieza, int fila, int columna)
{
	//Comprobamos que la pieza que llega es un rey
	if (pieza->getTipo() == REY) {
		//Segun donde se vaya a mover, movemos la torre correspondiente. La legalidad del movimiento se comprueba tanto en la pieza como en comprobarRey
		if (fila == 1 && columna == 3) {
			buscarPieza(1, 1)->setColumna(4);
		}
		if (fila == 1 && columna == 7) {
			buscarPieza(1, 8)->setColumna(6);
		}
		if (fila == 8 && columna == 3) {
			buscarPieza(8, 1)->setColumna(4);
		}
		if (fila == 8 && columna == 7) {
			buscarPieza(8, 8)->setColumna(6);
		}
	}
}

void ListaPiezas::anularEnroque(pieza* pieza, int fila, int columna)
{
	//Si se mueve una torre comprobamos cual se mueve y anulamos el enroque con ella
	if (pieza->getTipo() == TORRE) {
		if ((pieza->getCoordenada().getFila() == 1) && (pieza->getCoordenada().getColumna() == 1)) torreBlancaIzq = false;
		if ((pieza->getCoordenada().getFila() == 1) && (pieza->getCoordenada().getColumna() == 8)) torreBlancaDrc = false;
		if ((pieza->getCoordenada().getFila() == 8) && (pieza->getCoordenada().getColumna() == 1)) torreNegraIzq = false;
		if ((pieza->getCoordenada().getFila() == 8) && (pieza->getCoordenada().getColumna() == 8)) torreNegraDrc = false;
	}
	//Si se mueve el rey anulamos su enroque
	if (pieza->getTipo() == REY) {
		if ((pieza->getCoordenada().getFila() == 1) && (pieza->getCoordenada().getColumna() == 5)) enroqueBlanco = false;
		if ((pieza->getCoordenada().getFila() == 8) && (pieza->getCoordenada().getColumna() == 5)) enroqueNegro = false;
	}
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

	//Si existe la pieza
	if (index != -1) {
		//Si no es nullptr
		if (pieza1 != nullptr) {
			//Comprobamos que es su turno
			if (comprobarTurno(pieza1)) {
				//Comprobamos si el movimiento es legal	
				if (movimientoLegal(pieza1, fila, columna)) {

					//Comprobamos si hay enroque o si hay que anularlo
					enroque(pieza1, fila, columna);
					anularEnroque(pieza1, fila, columna);

					//Movemos la pieza
					pieza1->setFila(fila);
					pieza1->setColumna(columna);
					ETSIDI::play("sonidos/movimiento.mp3"); //sonido de movimiento de pieza

					//Eliminamos si procede la pieza a donde nos movemos
					eliminar(listaPiezas[indexDes]);
					//delete listaPiezas[indexDes];
	
					//Guardamos el historial
					pieza1->guardarHistorial();
					
					//Recalculamos los jaques
					jaque(BLANCO);
					jaque(NEGRO);

					//Comprobamos si hay algun jaque Mate
					if (jaqueNegro&&jaqueMate(NEGRO)) {
						cout << "Jaque mate Blanco" << endl;
						jaqueMateBlanco = true;
						Sleep(300);
						ETSIDI::play("sonidos/jaqueMate.mp3");
					}
					if (jaqueBlanco && jaqueMate(BLANCO)) {
						cout << "Jaque mate Negro" << endl;
						jaqueMateNegro = true;
						Sleep(300);
						ETSIDI::play("sonidos/jaqueMate.mp3");
					}
					
					
					//Cambiamos el color del proximo turno
					if (proximoTurno == BLANCO) {
						proximoTurno = NEGRO;
					}
					else { proximoTurno = BLANCO; }
					int n = 0;
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
		//Comprobamos si es su turno
		if (comprobarColor(index, coordDestino)) {
			//Comprobamos si es un movimiento legal
			if (listaPiezas[index]->movimientoLegal(coordDestino)) {
				//Comprobamos las posibles colisiones
				if (comprobarPieza(listaPiezas[index], fila, columna)) {
					//Comprobamos si el movimiento provoca jaque
					if (jaquePosible(listaPiezas[index], fila, columna)) {
						PosiblesJaque++;
						return true;
					}
				}
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
		
	}
	return false;
}

bool ListaPiezas::movimientoLegalJaque(pieza* pieza1, int fila, int columna)
{
	//HACE LO MISMO QUE MOVIMIENTO LEGAL PERO SIN JAQUE POSIBLE, PARA PODER USARLA EN ESA FUNCION

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
}

void ListaPiezas::movPosibles(pieza* aux)
{
	/*
	Aqui se utiliza coordenadaPintar y coordenadaComer, que utiliza la clase tablero para pintar los movientos posibles y las capturas
	*/

	nPosibles = 0;
	int a = 1;
	int b = 1;
	if (aux != nullptr) {
		//Comprobamos si es su turno
		if (comprobarTurno(aux)) {
			//Recorremos todos los movimientos posibles
			for (int i = 1; i < 9; i++) {
				for (int j = 1; j < 9; j++) {
					
					//Si el movimiento es legal
					 if (movimientoLegal(aux, i, j)) {

						 coordenada coord(i, j);
						 movimientosPosibles[nPosibles++] = { i,j };

						 //Si hay una pieza guardamos la captura para pintarla
						 if (buscarPieza(i, j) != nullptr) {
							 coordenadaComer[b] = { i,j };
							 b++;
						 }
						 else {
							 //Si no hay pieza es un movimiento legal y se guarda en coordenadaPintar
							 coordenadaPintar[a] = { i,j };
							 a++;
						 }
						//Variable para que solo se pinte si se pulsa una pieza
						si = true;
					}
				}
			}
			//Rellenamos el resto del vector con -1 -1
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
	
	// Comprobamos las colisiones en la diagonal arriba derecha
	if (((restaDrcha.getColumna() >= 0) && (restaDrcha.getFila()) > 0)) { 
		for (i = pieza->getCoordenada().getFila() + 1, j = pieza->getCoordenada().getColumna() + 1 ; (i < destino.getFila()), (j < destino.getColumna()); i++, j++) {
			if (buscarPieza(i,j) != nullptr){
				return false;	
			}
		}
	}

	// Comprobamos las colisiones en la diagonal abajo izquierda
	if (((restaIzq.getColumna() >= 0) && (restaIzq.getFila()) > 0)) {
		for (s = pieza->getCoordenada().getFila() - 1, l = pieza->getCoordenada().getColumna() - 1; (s > destino.getFila()), (l > destino.getColumna()); s--, l--) {
			if (mirarCasilla(s, l)) {					
				return false;
			}
		}
	}
	
	// Comprobamos las colisiones en la diagonal arriba izq
	if (((restaIzq.getColumna() >= 0) && (restaDrcha.getFila()) > 0)) {
		for (i = pieza->getCoordenada().getFila() + 1, j = pieza->getCoordenada().getColumna() - 1; (i < destino.getFila()), (j > destino.getColumna()); i++, j--) {
			if (mirarCasilla(i, j)) {
				return false;
			}
		}
	}

	// Comprobamos las colisiones en la diagonal abajo derecha
	if (((restaDrcha.getColumna() >= 0) && (restaIzq.getFila()) > 0)) {
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

	//Comprobamos las colisiones hacia arriba en la misma columna
	if (destino.getFila() - coordInicio.getFila() >= 0) {
		for (ib = coordInicio.getFila() + 1; ib < destino.getFila(); ib++) {
			if (mirarCasilla(ib, coordInicio.getColumna())) {
				return false;
			}
		}
	}

	//Comprobamos las colisiones hacia la derecha en la misma fila
	if (destino.getColumna() - coordInicio.getColumna() >= 0) {
		for (pd = coordInicio.getColumna() + 1; pd < destino.getColumna(); pd++) {
			if (mirarCasilla(coordInicio.getFila(), pd)) {
				return false;
			}
		}
	}

	//Comprobamos las colisiones hacia la izquierda en la misma fila
	if (coordInicio.getColumna() - destino.getColumna() >= 0) {
		for (fd = coordInicio.getColumna() - 1; fd > destino.getColumna(); fd--) {
			if (mirarCasilla(coordInicio.getFila(), fd)) {
				return false;
			}
		}
	}

	//Comprobamos las colisiones hacia abajo en la misma columna
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

	//Para comprobar la reina comprobamos utilizamos el comprobar alfil y comprobar torre segun que movimiento sea
	//Diagonal
	if (abs(destino.getColumna() - pieza->getCoordenada().getColumna()) == abs(destino.getFila() - pieza->getCoordenada().getFila())) {
		return comprobarAlfil(pieza, fila, columna);
	}

	//Mismma fila
	if (pieza->getCoordenada().getFila() == destino.getFila()) {
		return comprobarTorre(pieza, fila, columna);
	}

	//Misma columna
	if (pieza->getCoordenada().getColumna() == destino.getColumna()) {
		return comprobarTorre(pieza, fila, columna);;
	}

	return true;

}

bool ListaPiezas::comprobarPeon(pieza* pieza, int fila, int columna)
{
	coordenada destino(fila, columna);
	bool flag = false;

	//Primero comprobamos el color del peon
	if (pieza->getColor() == BLANCO)
	{
		//Comprobacion para la captura en la diagonal derecha
		if (((destino.getColumna() - pieza->getCoordenada().getColumna()) == 1) && ((destino.getFila() - pieza->getCoordenada().getFila()) == 1)) {
			if (mirarCasilla(fila, columna)) return true;
			else return false;
		}
		//Comprobacion para la captura en la diagonal izquierda
		if (((destino.getColumna() - pieza->getCoordenada().getColumna()) == -1) && ((destino.getFila() - pieza->getCoordenada().getFila()) == 1)) {
			if (mirarCasilla(fila, columna)) return true;
			else return false;
		}

		//Colision en el movimiento hacia delante
		if (mirarCasilla(pieza->getCoordenada().getFila() + 1, pieza->getCoordenada().getColumna())) return false;

		//Movimiento de dos casillas hacia delante si el peon no se ha movido
		if ((pieza->getCoordenada().getFila()) == (2))
		{
			//Comprobamos si hay colisiones
			if (mirarCasilla(pieza->getCoordenada().getFila() + 2, pieza->getCoordenada().getColumna())) flag = true;
			if (mirarCasilla(pieza->getCoordenada().getFila() + 1, pieza->getCoordenada().getColumna())) return false;

			if (destino.getFila() == 3) return true;
			else if (flag) return false;
		}
		return true;
	}
		else {
		//El negro tiene el mismo esquema que el del peon blanco pero cambiando las comprobaciones para ajustarse a su naturaleza simétrica

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
	int index=-1;

	//Buscamos al rey enemigo
	for (int i = 0; i < nPiezas; i++) {
		if ((listaPiezas[i]->getTipo() == REY)&&(listaPiezas[i]->getColor()!=colorReyMov)) {
			index = i;
		}
	}
	//Guardamos su coordenada
	coordenada reyEnemigo = listaPiezas[index]->getCoordenada();

	//Comprobamos si hay una colision
	if (mirarCasilla(fila, columna)) {
		if (buscarPieza(fila, columna) != nullptr)
			//Si hay una pieza pero es de distinto color permitimos el movimiento
			if (buscarPieza(fila, columna)->getColor() !=pieza->getColor()) return true;
		return false;
	}
	else {
		//Miramos las casillas del rey enemigo una a una
		for (int i = reyEnemigo.getFila() + 1; i >= reyEnemigo.getFila() - 1; i--) {
			for (int j = reyEnemigo.getColumna() - 1; j <= reyEnemigo.getColumna() + 1; j++) {
				coordenada aux(i, j);
				//Si alguna casilla del movimiento del rey enemigo coincide con una del rey que llama a la funcion se ilegaliza el movimiento
				if (destino == aux) return false;
			}
		}
	}

	//Enroque hacia la izquierda del blanco
	if ((pieza->getColor() == BLANCO) && (fila == 1) && (columna == 3)) {
		//Si la torre izquierda y el rey no se han movido se continuan las comprobaciones
		if ((torreBlancaIzq == true) && (enroqueBlanco == true)) {
			//Casillas vacias a la izquierda
			if ((mirarCasilla(1, 3) == true) || (mirarCasilla(1, 4) == true)) {
				return false;
			}
			//Comprobamos que ninguna de las casillas tenga jaque
			else if ((jaquePosible(pieza, 1, 3) == false) || (jaquePosible(pieza, 1, 4) == false)) {
				return false;
			}
			//Si no hay jaque permitimos el movimiento
			else return true;
		}
		else return false;
	}
	//Enroque hacia la izquierda del blanco, la lógica es la misma para el primer enroque
	if ((pieza->getColor() == BLANCO) && (fila == 1) && (columna == 7)) {
		if ((torreBlancaDrc == true) && (enroqueBlanco == true)) {
			//Casillas vacias a la derecha
			if ((mirarCasilla(1, 6) == true) || (mirarCasilla(1, 7) == true)) {
				return false;
			}
			else if ((jaquePosible(pieza, 1, 6) == false) || (jaquePosible(pieza, 1, 7) == false)) {
				return false;
			}
			else return true;
		}
		else return false;
	}
	//Enroque hacia la izquierda del negro
	if ((pieza->getColor() == NEGRO) && (fila == 8) && (columna == 3)) {
		if ((torreNegraIzq == true) && (enroqueNegro == true)) {
			//Casillas vacias a la izquierda
			if ((mirarCasilla(8, 3) == true) || (mirarCasilla(8, 4) == true)) {
				return false;
			}
			else if ((jaquePosible(pieza, 8, 3) == false) || (jaquePosible(pieza, 8, 4) == false)) {
				return false;
			}
			else return true;
		}
		else return false;
	}
	//Enroque hacia la derecha del negro
	if ((pieza->getColor() == NEGRO) && (fila == 8) && (columna == 7)) {
		if ((torreBlancaIzq == true) && (enroqueBlanco == true)) {
			//Casillas vacias a la derecha
			if ((mirarCasilla(8, 6) == true) || (mirarCasilla(8, 7) == true)) {
				return false;
			}
			else if ((jaquePosible(pieza, 8, 6) == false) || (jaquePosible(pieza, 8, 7) == false)) {
				return false;
			}
			else return true;
		}
		else return false;
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
			//Comprobamos que no produzca jaque
			if (jaquePosible(pieza1, fila, columna)) return false;
			return true;
		}
	}
	 return false;
}

void ListaPiezas::jaque(color Color)
{
	coordenada CoordRey(-1,-1);

	//Reiniciamos los jaque temporalmente segun el color
	if (Color == BLANCO) { jaqueNegro = FALSE; }
	if (Color == NEGRO) { jaqueBlanco = FALSE; }

	//Buscamos al rey enemigo
	for (int i = 0; i < nPiezas; i++) {
		if (listaPiezas[i]->getTipo() == REY && listaPiezas[i]->getColor() != Color) {
			CoordRey.setCol(listaPiezas[i]->getCoordenada().getColumna());
			CoordRey.setFil(listaPiezas[i]->getCoordenada().getFila());
		}
	}

	//Para todas las piezas comprobamos si ataca al rey
	for (int i = 0; i < nPiezas; i++) {
		//Usamos movimientoLegalJaque para no caer en un bucle de llamadas de funciones
		if (movimientoLegalJaque(listaPiezas[i], CoordRey.getFila(), CoordRey.getColumna())) {

			if (Color == BLANCO) {
				jaqueNegro = TRUE;
				ETSIDI::play("sonidos/jaque.mp3");
			}
			if (Color == NEGRO) {
				jaqueBlanco = TRUE;
				ETSIDI::play("sonidos/jaque.mp3");
			}
			std::cout << " hay jaque " << jaqueNegro << " " << jaqueBlanco << endl;
		}
	}
}

bool ListaPiezas::jaqueBool(color Color)
{
	//Hace lo mismo que jaque(color color) pero devuelve true o false en vez de modificar el atributo interno
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

bool ListaPiezas::jaquePosible(pieza* pieza1, int fila, int columna) 
{

	/*
	Esta funcion que un hipotetico movimiento provoca jaque o no
	*/
	coordenada CoordApoyo;
	coordenada CoordApoyoFicha;
	bool hayPieza = false;
	pieza* piezaDestino;

	//Guardamos las coordenadas de inicio de la pieza
	CoordApoyo.setFil(pieza1->getCoordenada().getFila());
	CoordApoyo.setCol(pieza1->getCoordenada().getColumna());

	//Miramos la casilla de destino, si hay una pieza la movemos temporalmente fuera del tablero
	if (mirarCasilla(fila, columna)) {
		hayPieza = true;
		piezaDestino = buscarPieza(fila, columna);
		piezaDestino->setFila(100);
		piezaDestino->setColumna(100);
	}

	//Movemos la pieza que realiza el movimiento a la posicion de destino
	pieza1->setFila(fila);
	pieza1->setColumna(columna);


	//Si se produce jaque y no estamos nosotros en jaque
	if (jaqueBool(BLANCO)&&(jaqueBlanco!=true)) { 

		//Devolvemos la pieza que se mueve a su posicion original
		pieza1->setFila(CoordApoyo.getFila());
		pieza1->setColumna(CoordApoyo.getColumna());
		//Devolvemos si existia una pieza en destino a su sitio
		if (hayPieza) {
			piezaDestino->setFila(fila);
			piezaDestino->setColumna(columna);
		}
		//Si la pieza era blanca permitimos el movimiento
		if (pieza1->getColor() == BLANCO) return true;

		jaqueBlanco = false;
		return false;
	}
	//Hacemos lo mismo con el negro
	if (jaqueBool(NEGRO) && (jaqueNegro != true)) {

		//Devolvemos la pieza que se mueve a su posicion original
		pieza1->setFila(CoordApoyo.getFila());
		pieza1->setColumna(CoordApoyo.getColumna());

		//Devolvemos si existia una pieza en destino a su sitio
		if (hayPieza) {
			piezaDestino->setFila(fila);
			piezaDestino->setColumna(columna);
		}

		if (pieza1->getColor() == NEGRO) return true;

		jaqueNegro = false;
		return false;

	}

	//Devolvemos las piezas a su sitio
	if (hayPieza) {
		piezaDestino->setFila(fila);
		piezaDestino->setColumna(columna);
	}			
	pieza1->setFila(CoordApoyo.getFila());
	pieza1->setColumna(CoordApoyo.getColumna());
			

	return true;
}

bool ListaPiezas::jaqueMate(color color)
{
	//Para el jaque mate comprobamos todos los movimientos del rival y si es 0 devuelve true
	bool movPosible = false;
	for (int i = 0; i < nPiezas; i++) {
		if (listaPiezas[i]->getColor() == color) {
			for (int a = 1; a < 9; a++) {
				for (int b = 1; b < 9; b++) {
					if (movimientoLegal(listaPiezas[i], a, b)) {
						movPosible = true;
						cout << "Mov de " << listaPiezas[i]->getTipo() << " a " << a << " " << b << endl;
					}
				}
			}
		}
	}
	if (movPosible == true) {
		return false;
	}
	else return true;
}




bool ListaPiezas::mirarCasilla(int fila, int columna)
{
	//Devuelve true si hay una pieza en la casilla o false si no
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
	//Para comprobar las colisiones, segun el tipo de pieza se invoca su funcion correspondiente
	if (aux->getTipo() == ALFIL) return comprobarAlfil(aux, fila, columna);
	else if (aux->getTipo() == TORRE) return comprobarTorre(aux, fila, columna);
	else if (aux->getTipo() == REINA) return comprobarReina(aux, fila, columna);
	else if (aux->getTipo() == PEON) return comprobarPeon(aux, fila, columna);
	else if (aux->getTipo() == REY) return comprobarRey(aux, fila, columna);
		
}

void ListaPiezas::setColorIA(color colorIA)
{
	this->colorIA = colorIA;
	cout << "ColorIA:" << this->colorIA;
}

void ListaPiezas::algoritmoIA()
{
	int puntuacionOptima = -999;
	int filaOptima = -1;
	int columnaOptima = -1;
	int indexOptimo = 0;

	for (int i = 0; i < nPiezas; i++) {
		//Recorremos todas las piezas de la IA
		if (listaPiezas[i]->getColor() == colorIA) {
			//Calculamos sus movmientos posibles
			movPosibles(listaPiezas[i]);
			for (int j = 0; j < nPosibles; j++) {
				/*
				Para todos los movimientos posibles calculamos una puntuacion que es la suma del valor de la pieza enemiga más el valor de su posicion, más lo que gana la IA
				al mover su pieza a esa determinada posicion, en resumen, lo que le quita al rival más lo que gana ella
				*/

				int punt = 0;
				punt = evaluacion(movimientosPosibles[j].getFila(), movimientosPosibles[j].getColumna()) + listaPiezas[i]->getValorPos(movimientosPosibles[j].getFila(), movimientosPosibles[j].getColumna());
				
				//Si esa puntuacion es mayor guardamos los datos del movimiento
				if (punt > puntuacionOptima) {
					if (movimientoLegal(listaPiezas[i], movimientosPosibles[j].getFila(), movimientosPosibles[j].getColumna())) {

						puntuacionOptima = punt;
						columnaOptima = movimientosPosibles[j].getColumna();
						filaOptima = movimientosPosibles[j].getFila();
						indexOptimo = i;
						//std::cout << "Puntuacion optima: " << puntuacionOptima << " FilaOptima: " << filaOptima << " ColumnaOptima: " << columnaOptima << endl;
						//std::cout << "Pieza: " << listaPiezas[i]->getTipo() << " coordenada: " << listaPiezas[i]->getCoordenada().getFila() << " " << listaPiezas[i]->getCoordenada().getColumna() << endl;
					}
				}
			}
		}
	}

	//Finalmente movemos la pieza a esa posicion
	moverPieza(listaPiezas[indexOptimo], filaOptima, columnaOptima);

}

int ListaPiezas::evaluacion(int fila, int columna) {
	//Devuelve el valor de una pieza más el valor de esa pieza en esa posicion
	if (mirarCasilla(fila, columna)) {
		int valor = buscarPieza(fila, columna)->getValor() + buscarPieza(fila, columna)->getValorPos(fila, columna);
		return valor;
	}
	else return 0;
}

//Algoritmo que intenta implementar el metodo minimax pero que no funciona
void ListaPiezas::algoritmoIAv2(int iteraciones, int profundidad)
{
	int puntuacionOptima = -999;
	int index=0, fila=1, columna=1;

	for (int i = 0; i < nPiezas; i++) {
		if (listaPiezas[i]->getColor() == colorIA) {
			for (int j = 1; j < 9; j++) {
				for (int k = 1; k < 9; k++) {
					if (movimientoLegal(listaPiezas[i], j, k)) {
						int punt;
						punt = maxi(listaPiezas[i],colorIA, 0, j, k);
						if (punt > puntuacionOptima) {
							puntuacionOptima = punt;
							fila = j;
							columna = k;
							index = i;
						}
					}
				}
			}
		}
	}

	moverPieza(listaPiezas[index], fila, columna);
}

int ListaPiezas::evaluacionCompleta()
{
	//Devuelve la puntuacion de un color especifico
	int puntuacion = 0;

	for (int i = 1; i < 9; i++) {
		for (int j = 1; j < 9; j++) {
			if (mirarCasilla(i,j))
			{
				if (buscarPieza(i, j)->getColor() == colorIA) {
					puntuacion += evaluacion(i, j);
				}
				else {
					puntuacion -= evaluacion(i, j);
				}
			}
		}
	}
	return puntuacion;
}

int ListaPiezas::maxi(pieza* pieza1, color color1, int profundidad, int fila, int columna)
{
	if (profundidad == 0) return evaluacionCompleta();

	color prox;
	if (color1 == NEGRO) {
		prox = BLANCO;
	}
	else prox = NEGRO;

	int max = -999;
	for (int n = 0; n < nPiezas; n++) {
		for (int i = 1; i < 9; i++) {
			for (int j = 1; j < 9; j++) {
				int puntuacion;
				bool mover = false;
				coordenada apoyo1;
				coordenada apoyo2;
				pieza* piezaCasilla;
				if (listaPiezas[n]->getColor() == color1 && listaPiezas[n]->getColor() != NONE) {
					if (movimientoLegal(listaPiezas[n], i, j)) {
						//Mover pieza
						if (mirarCasilla(i, j)) {
							mover = true;
							piezaCasilla = buscarPieza(i, j);
							apoyo1 = piezaCasilla->getCoordenada();
							piezaCasilla->setFila(100);
							piezaCasilla->setColumna(100);
						}
						apoyo2 = listaPiezas[n]->getCoordenada();
						listaPiezas[n]->setFila(i);
						listaPiezas[n]->setColumna(j);


						puntuacion = mini(listaPiezas[n], prox, profundidad - 1, fila, columna);
						if (puntuacion > max)max = puntuacion;


						//Devolver pieza
						listaPiezas[n]->setFila(apoyo2.getFila());
						listaPiezas[n]->setColumna(apoyo2.getColumna());
						if (mover) {
							piezaCasilla->setFila(apoyo1.getFila());
							piezaCasilla->setColumna(apoyo1.getColumna());
						}
					}
					}
				}
			}
		}
		return max;
}

int ListaPiezas::mini(pieza* pieza1,color color1, int profundidad, int fila, int columna)
{

	color prox;
	if (color1 == NEGRO) {
		prox = BLANCO;
	}
	else prox = NEGRO;


	if (profundidad == 0) return -(evaluacionCompleta());
	int min = 999;
	for (int n = 0; n < nPiezas; n++) {
		for (int i = 1; i < 9; i++) {
			for (int j = 1; j < 9; j++) {
				int puntuacion;
				bool mover = false;
				coordenada apoyo1;
				coordenada apoyo2;
				pieza* piezaCasilla;
				if (listaPiezas[n]->getColor() == color1 && listaPiezas[n]->getColor() != NONE) {
					if (movimientoLegal(listaPiezas[n], fila, columna)) {
						//Mover pieza
						if (mirarCasilla(i, j)) {
							mover = true;
							piezaCasilla = buscarPieza(i, j);
							apoyo1 = piezaCasilla->getCoordenada();
							piezaCasilla->setFila(100);
							piezaCasilla->setColumna(100);
						}
						apoyo2 = listaPiezas[n]->getCoordenada();
						listaPiezas[n]->setFila(i);
						listaPiezas[n]->setColumna(j);


						puntuacion = mini(listaPiezas[n],prox, profundidad - 1, fila, columna);
						if (puntuacion < min)min = puntuacion;


						//Devolver pieza
						listaPiezas[n]->setFila(apoyo2.getFila());
						listaPiezas[n]->setColumna(apoyo2.getColumna());
						if (mover) {
							piezaCasilla->setFila(apoyo1.getFila());
							piezaCasilla->setColumna(apoyo1.getColumna());
						}
					}
				}
			}
		}
	}
	return min;
}


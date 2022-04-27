#include "Alfil.h"

Alfil::Alfil()
{
	tipo = ALFIL;
}

Alfil::Alfil(color color, coordenada coord) : pieza(color, coord)
{
	tipo = ALFIL;
}

void Alfil::dibuja()
{
	pieza::dibuja();

	//Se crea un vector2D con las coordenadas de la pieza
	coordenada coordPieza = getCoordenada();
	vector2D vector = coordPieza.toVector();

	//Se añade un offset para centrar las piezas
	float x = vector.x + 1.0f;
	float y = vector.y;


	//textura
	if (getColor() == BLANCO) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/alfilBlanco.png").id);
	}
	else {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/alfilNegro.png").id);
	}


	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	//sin bordes
	/*glTexCoord2d(0, 1); glVertex3f(y, 0.1f, x);
	glTexCoord2d(1, 1); glVertex3f(y, 0.1f, x + getAncho());
	glTexCoord2d(1, 0); glVertex3f(y + getAltura(), 0.1f, x + getAncho());
	glTexCoord2d(0, 0); glVertex3f(y + getAltura(), 0.1f, x);*/
	//con bordes
	glTexCoord2d(0, 1); glVertex3f(y + 0.2f, 0.2f, x + 0.2f);
	glTexCoord2d(1, 1); glVertex3f(y + 0.2f, 0.2f, x + getAncho() - 0.2f);
	glTexCoord2d(1, 0); glVertex3f(y + getAltura() - 0.2f, 0.2f, x + getAncho() - 0.2f);
	glTexCoord2d(0, 0); glVertex3f(y - 0.2f + getAltura(), 0.2f, x + 0.2f);
	//
	glEnd();
	glEnable(GL_LIGHTING);

	//Liberar memoria de la textura
	glBindTexture(GL_TEXTURE_2D, 0);
}

bool Alfil::movimientoLegal(coordenada destino)
{
	coordenada coordInicio = getCoordenada();

	if (((destino.getColumna() - coordInicio.getColumna()) == 0) && ((destino.getFila() - coordInicio.getFila()) == 0)) { return false; }
	else if (abs(destino.getColumna() - getCoordenada().getColumna()) == abs(destino.getFila() - getCoordenada().getFila())) {
		return true;
	}
	else return false;
}
/*
bool Alfil::movimientoLegal(coordenada destino, bool matriz[7][7])
{
	
	coordenada coordInicio = getCoordenada();

	
	
	if (((destino.getColumna() - coordInicio.getColumna()) == 0) && ((destino.getFila() - coordInicio.getFila()) == 0)) { return false; }

	bool obstaculo = false;
	int j = 0;
	int i = 0;
	int s = 0;
	int l = 0;
	
	//Movimiento en diagonal hacia arriba la derecha
	if ((destino.getColumna() - getCoordenada().getColumna()) == (destino.getFila() - getCoordenada().getFila())) { //movimento en lateral
		
		if (((destino.getColumna() - getCoordenada().getColumna()) > 0) && ((destino.getFila() - getCoordenada().getFila()) > 0)) { // arriba derecha
			for (i = getCoordenada().getFila(), j = getCoordenada().getColumna(); (i < destino.getFila()), (j < destino.getColumna()); i++, j++) {
				if (matriz[i][j]) {
					return false;
				}
			}
			return true;
		}

		else if (((destino.getColumna() - getCoordenada().getColumna()) < 0) && ((destino.getFila() - getCoordenada().getFila()) < 0)) {//abajo izq
			for (s = getCoordenada().getFila(), l = getCoordenada().getColumna(); (s > destino.getFila()), (l > destino.getColumna()); s--, l--) {
				if (matriz[s][l]) {
					return false;
				}
			}
			return true;
		}
		//	
	}


	//Movimiento en diagonal hacia la izquierda
	else if ((destino.getColumna() - getCoordenada().getColumna()) == (getCoordenada().getFila() - destino.getFila())) {
		if (((destino.getColumna() - getCoordenada().getColumna()) < 0) && ((destino.getFila() - getCoordenada().getFila()) > 0)) {
			for (i = getCoordenada().getFila(), j = getCoordenada().getColumna(); (i < destino.getFila()), (j > destino.getColumna()); i++, j--) { //arriba izq
				if (matriz[i][j]) {
					return false;
				}
			}
			return true;
		}
		else if (((destino.getColumna() - getCoordenada().getColumna()) > 0) && ((destino.getFila() - getCoordenada().getFila()) < 0)) {
			for (s = getCoordenada().getFila(), l = getCoordenada().getColumna(); (s > destino.getFila()), (l < destino.getColumna()); s--, l++) {// abajo drcha
				if (matriz[s][l]) {
					return false;
				}
			}
			return true;
		}
	}
	else return false;
	
}
*/


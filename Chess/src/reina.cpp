#include "reina.h"

reina::reina(color color, coordenada coord) : pieza(color,coord)
{
}

reina::reina()
{

}

void reina::dibuja()
{
	pieza::dibuja();

	//Se crea un vector2D con las coordenadas de la pieza
	coordenada coordPieza = getCoordenada();
	vector2D vector = coordPieza.toVector();

	//Se añade un offset para centrar las piezas
	float x = vector.x + 1.0f;
	float y = vector.y;


	//Textura
	if (getColor()==BLANCO){
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/reinaBlanca.png").id);
	}
	else {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/reinaNegra.png").id);
	}


	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	//
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

bool reina::movimientoLegal(coordenada destino, bool matriz[8][8])
{
	coordenada coordInicio = getCoordenada();

	if (((destino.getColumna() - coordInicio.getColumna()) == 0) && ((destino.getFila() - coordInicio.getFila()) == 0)) { return false; }

	//Movimiento en la misma fila
	else if (coordInicio.getFila() == destino.getFila()) {
		return true;
	}
	//Movimiento en la misma columna
	else if (coordInicio.getColumna() == destino.getColumna()) {
		return true;
	}
	//Movimiento en diagonal hacia la derecha
	else if ((destino.getColumna() - coordInicio.getColumna()) == (destino.getFila() - coordInicio.getFila())) {
		return true;
	}
	//Movimiento en diagonal hacia la izquierda
	else if ((destino.getColumna() - coordInicio.getColumna()) == (coordInicio.getFila() - destino.getFila())) {
		return true;
	}
	else return false;
}

#include "rey.h"
#include<iostream>

rey::rey( color color, coordenada coord) : pieza(color,coord)
{
	tipo = REY;
}

rey::rey()
{
	tipo = REY;
}

void rey::dibuja()
{

	pieza::dibuja();

	//Se crea un vector2D con las coordenadas de la pieza
	coordenada coordPieza = getCoordenada();
	vector2D vector = coordPieza.toVector();

	//Se añade un offset para centrar las piezas
	float x = vector.x+1.0f;
	float y = vector.y;



	//textura
	if (getColor() == BLANCO) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/reyBlanco.png").id);
	}
	else {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/reyNegro.png").id);
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

bool rey::movimientoLegal(coordenada destino)
{
	coordenada coordInicio = getCoordenada();

	//NO movimiento a la misma casilla

	if (((destino.getColumna() - coordInicio.getColumna()) == 0) && ((destino.getFila() - coordInicio.getFila()) == 0)) {
		return false;
	}

	// movimiento esquinas 

	else if ((abs(destino.getColumna() - coordInicio.getColumna()) == 1) && (abs(destino.getFila() - coordInicio.getFila()) == 1)) {
		return true;
	}

	//movimiento columna y lateral
	else if ((abs(destino.getColumna() - coordInicio.getColumna()) == 0) && (abs(destino.getFila() - coordInicio.getFila()) == 1)) {
		return true;
	}
	else if ((abs(destino.getColumna() - coordInicio.getColumna()) == 1) && (abs(destino.getFila() - coordInicio.getFila()) == 0)) {
		return true;
	}
	else return false;
}



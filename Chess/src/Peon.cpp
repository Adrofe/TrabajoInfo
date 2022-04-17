#include "Peon.h"

Peon::Peon()
{
}

Peon::Peon(color color, coordenada coord) : pieza(color, coord)
{
}

void Peon::dibuja()
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
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/peonBlanco.png").id);
	}
	else {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/peonNegro.png").id);
	}


	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 1); glVertex3f(y, 0.1f, x);
	glTexCoord2d(1, 1); glVertex3f(y, 0.1f, x + getAncho());
	glTexCoord2d(1, 0); glVertex3f(y + getAltura(), 0.1f, x + getAncho());
	glTexCoord2d(0, 0); glVertex3f(y + getAltura(), 0.1f, x);
	glEnd();
	glEnable(GL_LIGHTING);

	//Liberar memoria de la textura
	glBindTexture(GL_TEXTURE_2D, 0);
}

bool Peon::movimientoLegal(coordenada destino)
{
	coordenada coordInicio = getCoordenada();
	if (pieza::getColor() == BLANCO) {
		if ((((coordInicio.getFila()) - (destino.getFila())) == (-1)) && ((coordInicio.getColumna()) == (destino.getColumna()))) {

			return true;
		}
	}
	else {
		if ((((coordInicio.getFila()) - (destino.getFila())) == (1)) && ((coordInicio.getColumna()) == (destino.getColumna()))) {

			return true;
		}
	}
	if ((coordInicio.getFila()) == ((2) || (7))) {
		if (pieza::getColor() == BLANCO) {
			if ((((coordInicio.getFila()) - (destino.getFila())) == (-2)) && ((coordInicio.getColumna()) == (destino.getColumna()))) {

				return true;
			}
		}
		else {
			if ((((coordInicio.getFila()) - (destino.getFila())) == (2)) && ((coordInicio.getColumna()) == (destino.getColumna()))) {

				return true;
			}
		}
	}
	else return false;
}

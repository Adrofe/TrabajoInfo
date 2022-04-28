#include "Peon.h"

Peon::Peon()
{
	tipo = PEON;
}

Peon::Peon(color color, coordenada coord) : pieza(color, coord)
{
	tipo = PEON;
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
	if ((coordInicio.getFila()) == (2) || ((coordInicio.getFila()) == (7))) {

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
	return false;
}

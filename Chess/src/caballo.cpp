#include "caballo.h"

caballo::caballo()
{
}

caballo::caballo(color color, coordenada coord) : pieza(color, coord)
{
}

void caballo::dibuja()
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
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/CaballoBlanco.png").id);
	}
	else {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/CaballoNegro.png").id);
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
	glTexCoord2d(1, 0); glVertex3f(y + getAltura() - 0.2, 0.2f, x + getAncho() - 0.2f);
	glTexCoord2d(0, 0); glVertex3f(y - 0.2f + getAltura(), 0.2f, x + 0.2f);
	//
	glEnd();
	glEnable(GL_LIGHTING);

	//Liberar memoria de la textura
	glBindTexture(GL_TEXTURE_2D, 0);

}

bool caballo::movimientoLegal(coordenada destino)
{
	coordenada coordInicio = getCoordenada();

	//movimiento en L hacia la izquierda o derecha
	if ((abs((coordInicio.getFila())-(destino.getFila())) == ( 1 )) && (abs((coordInicio.getColumna()) - (destino.getColumna())) == ( 2 ))){

		return true;
	}

	//movimiento en L hacia abajo o arriba
	else if ((abs((coordInicio.getColumna()) - (destino.getColumna())) == ( ( 1 ))) && (abs((coordInicio.getFila()) - (destino.getFila())) == ( 2 ))) {

		return true;
	}
	else return false;
}

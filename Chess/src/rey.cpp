#include "rey.h"


rey::rey(color color, coordenada coord) : pieza(color,coord)
{
}

rey::rey()
{
}

void rey::dibuja()
{
	//Se crea un vector2D con las coordenadas de la pieza
	coordenada coordPieza = getCoordenada();
	vector2D vector = coordPieza.toVector();

	//Se añade un offset para centrar las piezas
	float x = vector.x + 2.0f;
	float y = vector.y + 1.0f;

	//Textura
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/rey.png").id);

	glDisable(GL_LIGHTING);
	glColor3ub(255, 255, 255);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 1); glVertex3f(x, 0.1f, y);
	glTexCoord2d(1, 1); glVertex3f(x, 0.1f, y+altura);
	glTexCoord2d(1, 0); glVertex3f(x+ancho, 0.1f, y+altura);
	glTexCoord2d(0, 0); glVertex3f(x+ancho, 0.1f, y);
	glEnd();
	glEnable(GL_LIGHTING);
}

bool rey::movimientoLegal(coordenada destino)
{
	return true;
}

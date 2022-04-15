#include "rey.h"


rey::rey( color color, coordenada coord) : pieza(color,coord)
{
}

rey::rey()
{
}

void rey::dibuja()
{

	pieza::dibuja();

	float altura = 6.0f, ancho = 4.0f;

	//Se crea un vector2D con las coordenadas de la pieza
	coordenada coordPieza = getCoordenada();
	vector2D vector = coordPieza.toVector();

	//Se añade un offset para centrar las piezas
	float x = vector.x + 2.0f;
	float y = vector.y + 1.0f;

	//Textura
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/reydef2.png").id);



	glDisable(GL_LIGHTING);
	//
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 1); glVertex3f(y, 0.1f, x);
	glTexCoord2d(1, 1); glVertex3f(y, 0.1f, x+ancho);
	glTexCoord2d(1, 0); glVertex3f(y+altura, 0.1f, x+ancho);
	glTexCoord2d(0, 0); glVertex3f(y+altura, 0.1f, x);
	glEnd();
	glEnable(GL_LIGHTING);

	//Liberar memoria de la textura
	glBindTexture(GL_TEXTURE_2D, 0);
}

bool rey::movimientoLegal(coordenada destino)
{
	return true;
}

#include "tablero.h"
#include "freeglut.h"
#include "ETSIDI.h"

void tablero::dibuja()
{
	//Textura
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/tablero3.png").id);

	glDisable(GL_LIGHTING);
	glColor3ub(255, 255, 255);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 1); glVertex3f(0.0f,0.0f,0.0f);
	glTexCoord2d(1, 1); glVertex3f(0.0f, 0.0f, 64.0f);
	glTexCoord2d(1, 0); glVertex3f(64.0f, 0.0f, 64.0f);
	glTexCoord2d(0, 0); glVertex3f(64.0f, 0.0f, 0.0f);
	glEnd();
	glEnable(GL_LIGHTING);
}

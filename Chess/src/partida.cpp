#include "partida.h"
#include "freeglut.h"
#include "ETSIDI.h"

void partida::inicializa()
{
	x_ojo = 31.9;
	y_ojo = 100;
	z_ojo = 32;
	coordenada a("f", 6);
	irey.icolor = BLANCO;
	irey.coord = a;

}

void partida::dibuja()
{

	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		32.0, 0.0, 32.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y) 

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo.png").id);

	glDisable(GL_LIGHTING);
	glColor3ub(255, 255, 255);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 1); glVertex3f(-20.0f, -1.0f, -20.0f);
	glTexCoord2d(1, 1); glVertex3f(-20.0f, -1.0f, 80.0f);
	glTexCoord2d(1, 0); glVertex3f(80.0f, -1.0f, 80.0f);
	glTexCoord2d(0, 0); glVertex3f(80.0f, -1.0f, -20.0f);
	glEnd();
	glEnable(GL_LIGHTING);

	tablero.dibuja();
	irey.dibuja();
}

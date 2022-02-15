#include "Disparo.h"
#include "freeglut.h"
#include "Esfera.h"
#include <stdlib.h>

Disparo::Disparo() {
	velocidad.x = 0; velocidad.y = 4;
	aceleracion.x = 0; aceleracion.y = 0;
	origen.x = -5.0f;
	origen.y = 0.0f;

}
// Funcion para dibujar el disparo
void Disparo::dibuja()
{
	// TODO: Agregar aquí el código de implementación.
	glColor3f(0.0f, 1.0f, 1.0f);
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glPopMatrix();

	//Estela
	glDisable(GL_LIGHTING);
	glColor3f(rand() / (float)RAND_MAX, rand() / (float)RAND_MAX, rand() / (float)RAND_MAX);//color aleatorio
	glBegin(GL_POLYGON);
	glVertex3d(posicion.x-0.2, posicion.y, 0.1f);
	glVertex3d(posicion.x, posicion.y-3.0f, 0.1f);
	glVertex3d(posicion.x, posicion.y-3.0f, 0);
	glVertex3d(posicion.x+0.2, posicion.y, 0);
	glEnd();
	glEnable(GL_LIGHTING);

	//Estela2
	glDisable(GL_LIGHTING);
	glColor3f(rand() / (float)RAND_MAX, rand() / (float)RAND_MAX, rand() / (float)RAND_MAX);//color aleatorio
	glBegin(GL_POLYGON);
	glVertex3d(posicion.x+0.1f, posicion.y, 0.1f);
	glVertex3d(posicion.x, -1.0f, 0.1f);
	glVertex3d(posicion.x, -1.0f, 0);
	glVertex3d(posicion.x-0.1, posicion.y, 0);
	glEnd();
	glEnable(GL_LIGHTING);
}

float Disparo::getRadio()
{
	return radio;
}

void Disparo::setPos(float ix, float iy)
{
	ObjetoMovil::setPos(ix, iy);
	origen.x = ix;
	origen.y = iy;
}

void Disparo::setPos(Vector2D pos)
{
	ObjetoMovil::setPos(pos);
	origen.x = pos.x;
	origen.y = pos.y;
}

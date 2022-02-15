#include "DisparoEspecial.h"

DisparoEspecial::DisparoEspecial()
{
	velocidad.y = 8.0f;
	radio = 0.5f;
	posicion.x = 5.0f;
}

void DisparoEspecial::dibuja()
{
	// TODO: Agregar aquí el código de implementación.
	glColor3f(155.0f, 155.0f, 155.0f);
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glPopMatrix();

	//Estela
	glDisable(GL_LIGHTING);
	glColor3f(rand() / (float)RAND_MAX, rand() / (float)RAND_MAX, rand() / (float)RAND_MAX);//color aleatorio
	glBegin(GL_POLYGON);
	glVertex3d(posicion.x - 0.2, posicion.y, 0.1f);
	glVertex3d(posicion.x, posicion.y - 4.0f, 0.1f);
	glVertex3d(posicion.x, posicion.y - 4.0f, 0);
	glVertex3d(posicion.x + 0.2, posicion.y, 0);
	glEnd();
	glEnable(GL_LIGHTING);

	//Estela2
	glDisable(GL_LIGHTING);
	glColor3f(255,0,0);//color aleatorio
	glBegin(GL_POLYGON);
	glVertex3d(posicion.x + 0.5f, posicion.y, 0.1f);
	glVertex3d(posicion.x, origen.y, 0.1f);
	glVertex3d(posicion.x, origen.y, 0);
	glVertex3d(posicion.x -0.5f, posicion.y, 0);
	glEnd();
	glEnable(GL_LIGHTING);

}

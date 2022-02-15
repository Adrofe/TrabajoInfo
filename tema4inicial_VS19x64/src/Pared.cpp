#include "Pared.h"
#include "freeglut.h"

Pared::Pared() {
	color.r = color.g = color.b = 255; //Valor por defecto de la pared: blanco
}

// Funcion para dibujar la pared
void Pared::dibuja()
{
	// TODO: Agregar aquí el código de implementación.
	glDisable(GL_LIGHTING);
	glColor3ub(color.r, color.g, color.b);
	glBegin(GL_POLYGON);
	glVertex3d(limite1.x, limite1.y, 10);
	glVertex3d(limite2.x, limite2.y, 10);
	glVertex3d(limite2.x, limite2.y, -10);
	glVertex3d(limite1.x, limite1.y, -10);
	glEnd();
	glEnable(GL_LIGHTING);
}


void Pared::setColor(unsigned char r, unsigned char g, unsigned char b)
{
	// TODO: Agregar aquí el código de implementación.
	color.r = r;
	color.g = g;
	color.b = b;
}

void Pared::setLimite(float limite1x, float limite1y, float limite2x, float limite2y)
{
	// TODO: Agregar aquí el código de implementación.
	limite1.x = limite1x;
	limite1.y = limite1y;
	limite2.x = limite2x;
	limite2.y = limite2y;
}

void Pared::setPos(float x1, float y1, float x2, float y2)
{
	limite1.x = x1;
	limite1.y = y1;
	limite2.x = x2;
	limite2.y = y2;
}

float Pared::distancia(Vector2D punto, Vector2D* direccion)
{
//Calculo de distancia de una pared a un punto, adicionalmente
//se modifica el valor de un vector direccion opcional que contendrá
//el vector unitario saliente que indica la direccion de la
		Vector2D u = (punto - limite1);
		Vector2D v = (limite2 - limite1).unitario();
		float longitud = (limite1 - limite2).modulo();
		Vector2D dir;
		float valor = u * v;
		float distancia = 0;
		if (valor < 0)
			dir = u;
		else if (valor > longitud)
			dir = (punto - limite2);
		else
			dir = u - v * valor;
		distancia = dir.modulo();
		if (direccion != 0) //si nos dan un vector…
			*direccion = dir.unitario();
		return distancia;
}

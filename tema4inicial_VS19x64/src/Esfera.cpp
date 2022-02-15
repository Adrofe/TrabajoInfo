#include "Esfera.h"
#include "freeglut.h"

Esfera::Esfera() {
	color.r = color.b = color.g = 255; //Valor por defecto de la esfera: blanco
	radio = 1.0f;
	aceleracion.y = -9.8f; //aceleracion de la gravedad
	velocidad.x = 5; velocidad.y = 15;
}

Esfera::Esfera(float rad, float x, float y, float vx, float vy)
{
	radio = rad;
	posicion.x = x;
	posicion.y = y;
	velocidad.x = vx;
	velocidad.y = vy;
	color.r = color.g = 255;
	color.b = 100; //color distinto 
	aceleracion.y=-9.8;
}

void Esfera::dibuja()
{
	// TODO: Agregar aquí el código de implementación.
	glColor3ub(color.r, color.g, color.b);
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-posicion.x, -posicion.y, 0);
}


void Esfera::setColor(unsigned char r, unsigned char g, unsigned char b)
{
	// TODO: Agregar aquí el código de implementación.
	color.r = r;
	color.g = g;
	color.b = b;
}


void Esfera::setRadio(float r)
{
	// TODO: Agregar aquí el código de implementación.
	if (r < 0.1f)r = 0.1f;
	radio = r;
}

Esfera* Esfera::dividir()
{
	if (radio < 1.0f) return 0; //no dividimos 
	radio/=2.0f; //Dividimos el radio por 2 
	//Creamos una esfera nueva, copiando la actual 
	Esfera *aux=new Esfera(*this); 
	//Les damos nuevas velocidades 
	aux->setVel(5,8);//a la nueva mitad 
	setVel(-5,8);//a la mitad original 
	return aux;
}



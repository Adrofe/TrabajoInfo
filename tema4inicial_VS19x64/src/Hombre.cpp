#include "Hombre.h"
#include "freeglut.h"

Hombre::Hombre() {
	aceleracion.y = 0;
	posicion.x = 0; posicion.y = 0;
	sprite.setCenter(1, 0);
	sprite.setSize(2, 2);
}


void Hombre::dibuja()
{
	// TODO: Agregar aquí el código de implementación.
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.5);
	glColor3f(1.0f, 0.0f, 0.0f);
	//glutSolidSphere(altura, 20, 20);

	//Dibujo de la animacion del sprite
	if (velocidad.x > 0.01)sprite.flip(false, false);
	if (velocidad.x < -0.01)sprite.flip(true, false);
	if ((velocidad.x < 0.01) && (velocidad.x > -0.01))
		sprite.setState(0);
	else if (sprite.getState() == 0)
		sprite.setState(1, false);
	sprite.draw();

	glPopMatrix();
}


void Hombre::mueve(float t)
{
	ObjetoMovil::mueve(t);
	sprite.loop();
}

float Hombre::getAltura()
{
	return altura;
}

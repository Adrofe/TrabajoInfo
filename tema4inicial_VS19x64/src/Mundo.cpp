#include "Mundo.h"
#include "freeglut.h"
#include <math.h>
#include "Interaccion.h"

void Mundo::rotarOjo()
{
	float dist=sqrt(x_ojo*x_ojo+z_ojo*z_ojo);
	float ang=atan2(z_ojo,x_ojo);
	ang+=0.05f;
	x_ojo=dist*cos(ang);
	z_ojo=dist*sin(ang);
}
void Mundo::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			0.0, y_ojo, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    
	caja.dibuja();
	hombre.dibuja();
	plataforma.dibuja();
	bonus.dibuja();
	esferas.dibuja();
	disparos.dibuja();

	disparo_Especial.dibuja();

}

void Mundo::teclaEspecial(unsigned char key)
{
	switch (key) {
	case GLUT_KEY_LEFT:
		hombre.setVel(-5.0f, 0.0f);
		break;
	case GLUT_KEY_RIGHT:
		hombre.setVel(5.0f, 0.0f);
		break;
	}
}

void Mundo::mover()
{
	hombre.mueve(0.025f);
	bonus.mueve(0.025f);
	Interaccion::rebote(hombre, caja);

	esferas.mueve(0.025f);
	
	esferas.rebote(caja);
	esferas.rebote(plataforma);
	esferas.rebote();
	Esfera* aux = esferas.colision(hombre);
	if (aux != 0) {
		esferas.eliminar(aux); //Si alguna esfera choca
		ETSIDI::play("sonidos/impacto.wav");
	}

	disparos.mueve(0.025f);
	disparos.colision(caja);
	disparos.colision(plataforma);

	disparo_Especial.mueve(0.025f);
	Interaccion::colision(disparo_Especial, plataforma);
	Interaccion::colision(disparo_Especial, caja);

	for (int i = 0; i < esferas.getNumero(); i++) {
		if (Interaccion::colision(disparo_Especial, *esferas[i])) {
			Esfera* e = esferas[i]->dividir();
			if (e == 0) //no division 
				esferas.eliminar(esferas[i]);
			else esferas.agregar(e); 
			disparo_Especial.setPos(0,0); 
			disparo_Especial.setVel(0,10); 
			ETSIDI::play("sonidos/impacto.wav"); 
			break; 
		} 
	}

}

void Mundo::inicializa()
{
	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 30;

	bonus.setPos(5.0f, 5.0f);
	plataforma.setPos(-5.0f, 9.0f, 5.0f, 9.0f);


	Esfera* e1 = new Esfera(1, 2, 4, 5, 15);	// esfera1
	e1->setColor(200,0,0); esferas.agregar(e1); // esfera1 a la lista
	Esfera *e2=new Esfera(2,-2,4,-5,15);		// esfera2
	e2->setColor(255,255,255);
	esferas.agregar(e2);						//esfera2 a la lista
	//esferas.agregar(e2);


	for (int i = 0; i < 6; i++) {
		Esfera* aux = new Esfera(0.75f+i*0.25f,i,1+i,i,i);
		esferas.agregar(aux); //agregar a la lista
	}

	EsferaPulsante* e3 = new EsferaPulsante;
	e3->setColor(0, 255, 0);
	esferas.agregar(e3);

}

Mundo::~Mundo()
{
	esferas.destruirContenido();
	disparos.destruirContenido();
}

void Mundo::tecla(unsigned char key)
{
	switch (key)
	{
	case ' ':
	{
		Disparo* d = new Disparo();
		Vector2D pos = hombre.getPos();
		d->setPos(pos.x, pos.y);
		if (disparos.agregar(d))
			hombre.setVel(0, 0);
		else delete d;
		break;
	}
	case '1':
		esferas.agregar(new Esfera(0.5f, 0, 10));
		break;
	case '2':
		esferas.agregar(new Esfera(1.0f, 0, 10));
		break;
	case '3':
		esferas.agregar(new Esfera(1.5f, 0, 10));
		break;
	case '4':
		esferas.agregar(new Esfera(2.0f, 0, 10));
		break;
	}

}

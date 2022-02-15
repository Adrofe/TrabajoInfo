#include "Interaccion.h"

void Interaccion::rebote(Hombre &h, Caja c)
{
	float xmax = c.suelo.limite2.x;
	float xmin = c.suelo.limite1.x;
	if (h.posicion.x > xmax)h.posicion.x = xmax;
	if (h.posicion.x < xmin)h.posicion.x = xmin;
}

bool Interaccion::rebote(Esfera& e, Pared p)
{
	Vector2D dir;
	float dif = p.distancia(e.posicion, &dir) - e.radio;
	if (dif <= 0.0f)
	{
		Vector2D v_inicial = e.velocidad;
		e.velocidad = v_inicial - dir * 2.0 * (v_inicial * dir);
		e.posicion = e.posicion - dir * dif;
		return true;
	}
	return false;

}

void Interaccion::rebote(Esfera& e, Caja c)
{
	rebote(e, c.suelo);
	rebote(e, c.pared_dcha);
	rebote(e, c.pared_izq);
	rebote(e, c.techo);
}

void Interaccion::rebote(Esfera& e1, Esfera& e2)
{
	float D = e1.radio + e2.radio;
	Vector2D d = e1.posicion - e2.posicion;
	float modulo = d.modulo();
	float Area1 = 3.1415 * e1.radio * e1.radio;
	float Area2 = 3.1415 * e2.radio * e2.radio;
	Vector2D V1_2 = e1.velocidad - e2.velocidad;
	Vector2D X1_2 = e1.posicion - e2.posicion;
	Vector2D V2_1 = e2.velocidad - e1.velocidad;
	Vector2D X2_1 = e2.posicion - e1.posicion;

	if (modulo < D) {
		e1.velocidad = e1.velocidad - X1_2 * (V1_2 * X1_2) * ((2 * Area2) / ((Area1 + Area2) * (X1_2.modulo() * X1_2.modulo())));
		e2.velocidad = e2.velocidad - X2_1 * (V2_1 * X2_1) * ((2 * Area1) / ((Area1 + Area2) * (X2_1.modulo() * X2_1.modulo())));
	}
}

bool Interaccion::colision(Esfera e, Hombre h)
{
	Vector2D pos = h.getPos(); //la posicion de la base del hombre
	pos.y += h.getAltura() / 2.0f;	//Posicion del centro

	float distancia = (e.posicion - pos).modulo();
	if (distancia < e.radio) return true;
	return false;
}

bool Interaccion::colision(Disparo& d, Pared p)
{
	float dif = p.distancia(d.posicion) - d.radio;
	if (dif <= 0.0f)
	{
		d.velocidad.y = 0;
		return true;
	}
	return false;

}

bool Interaccion::colision(Disparo& d, Caja c)
{
	if (colision(d, c.techo)) {
		return true;
	}
	else { return false; }
	
}

bool Interaccion::colision(Disparo d, Esfera e)
{
	Pared aux; //Creamos una pared auxiliar 
	Vector2D p1=d.posicion;
	Vector2D p2=d.origen;
	aux.setPos(p1.x,p1.y,p2.x,p2.y); //Que coincida con el disparo.
	float dist=aux.distancia(e.posicion); //para calcular su distancia 
	if(dist<e.radio) return true; 
	return false;
}

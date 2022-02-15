#include "EsferaPulsante.h"

EsferaPulsante::EsferaPulsante()
{
	aceleracion.y = 0.0f;
	posicion.x = 0.0f; posicion.y = 5.0f;
	velocidad.x = 0.0f; velocidad.y = 0.0f;
	
}

void EsferaPulsante::mueve(float t)
{
	Esfera::mueve(t);
	if (radio > radio_max) pulso = -pulso;
	if (radio < radio_min) pulso = -pulso;
	radio += pulso * t;
	color.r = radio * 255;
	color.g = 255 - radio * 100;
	color.b = 100 + radio * 50;
}

Esfera* EsferaPulsante::dividir()
{
	if (radio < 1.0f) return 0; //no dividimos 
	radio /= 2.0f; //Dividimos el radio por 2 
	pulso += 0.5f;
	//Creamos una esfera nueva, copiando la actual 
	Esfera* aux = new Esfera(*this);
	//Les damos nuevas velocidades 
	aux->setVel(5, 8);//a la nueva mitad 
	setVel(-5, 8);//a la mitad original 
	return aux;
}

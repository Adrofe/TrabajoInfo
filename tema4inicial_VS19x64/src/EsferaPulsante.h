#pragma once
#include "Esfera.h"
class EsferaPulsante: public Esfera
{
private:
	float pulso{ 0.5f };
	float radio_max{ 2.0f };
	float radio_min{ 0.5f };
public: 
	EsferaPulsante();
	void mueve(float t);
	Esfera* dividir();
};


#pragma once
#include "Esfera.h"
#include "Interaccion.h"
#define MAX_ESFERAS 100

class ListaEsferas
{
public:
	ListaEsferas();
	bool agregar(Esfera* e);
	void dibuja();
	void mueve(float t);
	void rebote(Caja caja);
	void rebote(Pared p);
	void rebote(); //rebote entre las esferas
	void destruirContenido();
	void eliminar(int index);
	void eliminar(Esfera* e);
	Esfera* colision(Hombre& h);

	Esfera* operator[](int i);
	int getNumero() { return numero; }



private:
	Esfera* lista[MAX_ESFERAS];
	int numero;
};


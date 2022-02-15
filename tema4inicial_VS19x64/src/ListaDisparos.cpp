#include "ListaDisparos.h"

//Hola

ListaDisparos::ListaDisparos()
{
	numero = 0;
	for (int i = 0; i < MAX_DISPAROS; i++) {
		lista[i] = 0;
	}
}

ListaDisparos::~ListaDisparos()
{
	for (int i = 0; i < numero; i++) //destruccion de los disparos
		delete lista[i];
	numero = 0; //inicializa la lista
}

bool ListaDisparos::agregar(Disparo* d)
{
	if (numero < MAX_DISPAROS) {
		bool flag = 0;
		for (int i = 0; i < numero; i++) {
			if (lista[i] == d) flag = 1;
		}
		if (flag == 0) lista[numero++] = d; //ultimo puesto sin rellenar
		if (flag == 1) return false;
	}
	else {
		return false;		//capacidad maxima alcanzada
	}
	return true;
}

void ListaDisparos::destruirContenido()
{
	for (int i = 0; i < numero; i++) //destruccion de los disparos
		delete lista[i];
	numero = 0; //inicializa la lista
}

void ListaDisparos::mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->mueve(t);
}

void ListaDisparos::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}

void ListaDisparos::colision(Pared p)
{
	for (int i = 0; i < numero; i++){
		Interaccion::colision(*(lista[i]), p);
	}
}

void ListaDisparos::colision(Caja C)
{
	for (int i = 0; i < numero; i++) {
		Interaccion::colision(*(lista[i]), C);
	}
}

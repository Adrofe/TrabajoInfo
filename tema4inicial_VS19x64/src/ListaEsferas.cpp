#include "ListaEsferas.h"

ListaEsferas::ListaEsferas()
{
	numero = 0;
	for (int i = 0; i < MAX_ESFERAS; i++) {
		lista[i] = 0;
	}
}

bool ListaEsferas::agregar(Esfera *e)
{
	if (numero < MAX_ESFERAS){
		bool flag = 0;
		for (int i = 0; i < numero; i++) {
			if (lista[i] == e) flag = 1;
		}
		if (flag == 0) lista[numero++] = e; //ultimo puesto sin rellenar
		if (flag == 1) return false;
		}
	else {
		return false;		//capacidad maxima alcanzada
	}
	return true;

}

void ListaEsferas::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}

void ListaEsferas::mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->mueve(t);
}

void ListaEsferas::rebote(Caja caja)
{
	for (int i = 0; i < numero; i++)
		Interaccion::rebote(*(lista[i]), caja);
}

void ListaEsferas::rebote(Pared p)
{
	for (int i = 0; i < numero; i++) {
		Interaccion::rebote(*(lista[i]), p);
	}
}

void ListaEsferas::rebote()
{
	for (int i = 0; i < numero; i++) {
		for (int j = 0; j < i; j++) {
			Interaccion::rebote(*(lista[i]), *(lista[j]));
		}
	}
}

void ListaEsferas::destruirContenido()
{
	for (int i = 0; i < numero; i++) //destruccion de esferas contenidas
		delete lista[i];
	numero = 0; //inicializa la lista
}

void ListaEsferas::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++) {
		lista[i] = lista[i + 1];
	}
}

void ListaEsferas::eliminar(Esfera* e)
{
	for (int i = 0; i < numero; i++) {
		if (lista[i] == e) {
			eliminar(i);
			return;
		}
	}
}

Esfera* ListaEsferas::colision(Hombre& h)
{
	for(int i=0;i<numero;i++)
	{
		if (Interaccion::colision(*(lista[i]), h)) return lista[i];
	}
	return 0;
}

Esfera* ListaEsferas::operator[](int i)
{
	if (i >= numero)//si me paso, devuelvo la ultima
		i = numero - 1;
	if (i < 0)	//si el indice es negativo, devuelvo la primera
		i = 0;
	return lista[i];
}
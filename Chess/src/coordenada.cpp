
#pragma once

#include "coordenada.h"
#include "vector2D.h"



coordenada::coordenada()
{
	letra = "a";
	numero = 1;
}

coordenada::coordenada(string letra, int numero)
{
	this->letra = letra;
	this->numero = numero;

}

void coordenada::toChess(vector2D vector)
{
	
	switch ((int)vector.x) {
	case 0:
		letra = 'a';
		break;
	case 8:
		letra = 'b';
		break;
	case 16:
		letra = 'c';
		break;
	case 24:
		letra = 'd';
		break;
	case 32:
		letra = 'e';
		break;
	case 40:
		letra = 'f';
		break;
	case 48:
		letra = 'g';
		break;
	case 56:
		letra = 'h';
		break;
	default:
		break;
	}

	for (int i = 0; i < 64;i=i+8) {
		if ((int)vector.y == i) {
			numero = i/8+1;
		}
	}
	


}

vector2D coordenada::toVector()
{
	float x, y;

	if (letra == "a") x = 0.0f;
	else if (letra == "b") x = 8.0f;
	else if (letra == "c") x = 16.0f;
	else if (letra == "d") x = 24.0f;
	else if (letra == "e") x = 32.0f;
	else if (letra == "f") x = 40.0f;
	else if (letra == "g") x = 48.0f;
	else if (letra == "h") x = 56.0f;

	for (int i = 1; i < 9; i++) {
		if (numero == i) {
			y = i * 8 - 8;
		}
	}
	vector2D vector(x, y);
	return vector;
}

string coordenada::tostring(int numero)
{
	string letra2;
	switch (numero) {
	case 1:
		letra2 = 'a';
		break;
	case 2:
		letra2 = 'b';
		break;
	case 3:
		letra2 = 'c';
		break;
	case 4:
		letra2 = 'd';
		break;
	case 5:
		letra2 = 'e';
		break;
	case 6:
		letra2 = 'f';
		break;
	case 7:
		letra2 = 'g';
		break;
	case 8:
		letra2 = 'h';
		break;
	default:
		letra2 = 'a';
		break;
	}
	return letra2;
}



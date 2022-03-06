
#pragma once

#include "coordenada.h"
#include "vector2D.h"



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
	case 1:
		letra = 'b';
		break;
	case 2:
		letra = 'c';
		break;
	case 3:
		letra = 'd';
		break;
	case 4:
		letra = 'e';
		break;
	case 5:
		letra = 'f';
		break;
	case 6:
		letra = 'g';
		break;
	case 7:
		letra = 'h';
		break;
	default:
		break;
	}

	for (int i = 0; i < 8;i++) {
		if ((int)vector.y == i) {
			numero = i;
		}
	}
	


}



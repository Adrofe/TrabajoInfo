#include "pieza.h"

pieza::pieza(bool color, coordenada coord)
{
	this->icolor = color;
	this->coord = coord;
}

pieza::pieza()
{
	coordenada icoord;
	coord = icoord;
	icolor = 1;
}

pieza::~pieza()
{
}

bool pieza::getColor()
{
	return icolor;
}

coordenada pieza::getCoordenada()
{
	return coord;
}

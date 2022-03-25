#include "pieza.h"

pieza::pieza(color color, coordenada coord)
{
	this->icolor = color;
	this->coord = coord;
}

pieza::~pieza()
{
}

color pieza::getColor()
{
	return icolor;
}

coordenada pieza::getCoordenada()
{
	return coord;
}

#include "pieza.h"

pieza::pieza(color color, coordenada coord)
{
	this->icolor = color;
	this->coord = coord;
}

pieza::pieza()
{
	coordenada icoord;
	coord = icoord;
	icolor = BLANCO;
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

void pieza::setColumna(int columna)
{
	coord.setCol(columna);
}

void pieza::setFila(int fila)
{
	coord.setFil(fila);
}

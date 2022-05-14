#include "reina.h"

reina::reina(color color, coordenada coord) : pieza(color,coord)
{
	tipo = REINA;
	valor = 9;
}

reina::reina()
{
	tipo = REINA;
	valor = 9;
}

void reina::dibuja()
{
	pieza::dibuja();

	//Se crea un vector2D con las coordenadas de la pieza
	coordenada coordPieza = getCoordenada();
	vector2D vector = coordPieza.toVector();

	//Se añade un offset para centrar las piezas
	float x = vector.x + 1.0f;
	float y = vector.y;


	//Textura
	if (getColor()==BLANCO){
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/reinaBlanca.png").id);
	}
	else {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/reinaNegra.png").id);
	}


	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	//
	//sin bordes
	/*glTexCoord2d(0, 1); glVertex3f(y, 0.1f, x);
	glTexCoord2d(1, 1); glVertex3f(y, 0.1f, x + getAncho());
	glTexCoord2d(1, 0); glVertex3f(y + getAltura(), 0.1f, x + getAncho());
	glTexCoord2d(0, 0); glVertex3f(y + getAltura(), 0.1f, x);*/
	//con bordes
	glTexCoord2d(0, 1); glVertex3f(y + 0.2f, 0.2f, x + 0.2f);
	glTexCoord2d(1, 1); glVertex3f(y + 0.2f, 0.2f, x + getAncho() - 0.2f);
	glTexCoord2d(1, 0); glVertex3f(y + getAltura() - 0.2f, 0.2f, x + getAncho() - 0.2f);
	glTexCoord2d(0, 0); glVertex3f(y - 0.2f + getAltura(), 0.2f, x + 0.2f);
	//
	glEnd();
	glEnable(GL_LIGHTING);

	//Liberar memoria de la textura
	glBindTexture(GL_TEXTURE_2D, 0);

}

bool reina::movimientoLegal(coordenada destino)
{
	coordenada coordInicio = getCoordenada();

	if (((destino.getColumna() - coordInicio.getColumna()) == 0) && ((destino.getFila() - coordInicio.getFila()) == 0)) { return false; }

	else if (abs(destino.getColumna() - getCoordenada().getColumna()) == abs(destino.getFila() - getCoordenada().getFila())) {
		return true;
	}

	else if (coordInicio.getFila() == destino.getFila()) {
		return true;
	}
	else if (coordInicio.getColumna() == destino.getColumna()) {
		return true;
	}

	return false;
}

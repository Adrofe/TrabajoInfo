#include "CoordinadorPang.h"

CoordinadorPang::CoordinadorPang()
{
	estado = INICIO;
}

void CoordinadorPang::dibuja()
{
	if (estado == INICIO) {
		//CODIGO PARA PINTAR UNA PANTALLA NEGRA CON LETRAS 
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y) 
		ETSIDI::setTextColor(1,1,0);
		ETSIDI::setFont("fuentes/Bitwise.ttf",16);
		ETSIDI::printxy("Pang 1.1", -5,8);
		ETSIDI::setTextColor(1,1,1);
		ETSIDI::setFont("fuentes/Bitwise.ttf",12);
		ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR", -5,7);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -5,6);
		ETSIDI::printxy("Hernando & Rodriguez-Losada",2,1);
	}
	else if (estado == JUEGO) {
		mundo.dibuja();
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/GILLUBCD.ttf", 16);
		ETSIDI::printxy("Pang 1.2", -11, 17);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/GILLUBCD.ttf", 12);
		ETSIDI::printxy("ETSIDI", 3.5, 17);
	}
}

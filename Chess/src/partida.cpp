#include "partida.h"
#include "freeglut.h"
#include "ETSIDI.h"

void partida::inicializa()
{
	x_ojo = 31.9f;
	y_ojo = 100.0f;
	z_ojo = 32.0f;
}

void partida::dibuja()
{

	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		32.0, 0.0, 32.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y) 

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo.png").id);

	glDisable(GL_LIGHTING);
	glColor3ub(255, 255, 255);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 1); glVertex3f(-20.0f, -1.0f, -20.0f);
	glTexCoord2d(1, 1); glVertex3f(-20.0f, -1.0f, 80.0f);
	glTexCoord2d(1, 0); glVertex3f(80.0f, -1.0f, 80.0f);
	glTexCoord2d(0, 0); glVertex3f(80.0f, -1.0f, -20.0f);
	glEnd();
	glEnable(GL_LIGHTING);

	tablero.dibuja();
	irey.dibuja();
}

void partida::mouse(int button, int state, int x, int y)
{
    printf_s("%d, %d\n", button, state);
    printf_s("x: %d y: %d\n", x, y); // te dice en que coordenadas has hecho clik exactamente con el (0,0) en la esquina de arriba de la ventana 

    static int columna = 0;
    static int fila = 0;
    static bool mismaFil = FALSE;
    static bool mismaCol = FALSE;

    if (button == GLUT_LEFT_BUTTON && (state == GLUT_DOWN )) {
        getColFilMouse(x, y, columna, fila);
        printf_s("columna: %d, fila: %d \n", columna, fila); //te dice la columna y la fila que has hecho click

        /*if (columna == irey.getCoordenada().getColumna()) {
            if (fila == irey.getCoordenada().getFila()) {
                comprueba = TRUE;
            }
            else(comprueba = FALSE);
        }
        else (comprueba = FALSE);*/


        if (fila == irey.getCoordenada().getColumna()) {
            mismaCol = TRUE;
        }
        else (mismaCol = FALSE);
        if (columna == irey.getCoordenada().getFila()) {
            mismaFil = TRUE;
        }
        else(mismaFil = FALSE);
    }

    
    if (button == GLUT_LEFT_BUTTON && (state == GLUT_UP)) {
        getColFilMouse(x, y, columna, fila);
        if ((mismaCol == TRUE) && (mismaFil==TRUE)) {
            irey.setColumna(fila);
            irey.setFila(columna);
            mismaFil = FALSE;
            mismaCol = FALSE;
        }

    }
}

void partida::getColFilMouse(int x, int y, int &columna, int &fila)
{
    int x0 = 0, y0 = 0;
    int c, f;
    //Prueba movimiento de la pieza lo inicializa todo desde aqui para el cambio de posicion


       //te dice en que coordenadas has hecho clik exactamente con el (0,0) en la esquina de abajo del tablero
    x0 = x - 170;
    y0 = y - 657;
    printf_s("x0: %d y0: %d\n", x0, y0);
    c = 0;
    f = 0;
    if (((x0 > -1) && (x0 < 660)) && ((y0 < 1) && (y0 > -620))) {
        for (int i = 1; i < 9; i++) {

            if ((x0 > c) && (x0 < (c + 80))) {

                columna = i; //te estable la columna por un intervalo 

            }


            if ((y0 < -f) && (y0 > -(f + 75))) {

                fila = i; // te establece la fila por un intervalo
            }

            //esto varia si se cambian las dimensiones de la ventada creada por freeglut
            c = c + 80;
            f = f + 75;
        }
        printf_s("columna: %d, fila: %d \n", columna, fila); //te dice la columna y la fila que has hecho click
    }
    else std::cout << "MOVIMIENTO INCORRECTO: FUERA DE RANGO" << endl;
}



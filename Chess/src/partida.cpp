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

	//glEnable(GL_TEXTURE_2D);
  //  glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo.png").id);

	glDisable(GL_LIGHTING);
	glColor3ub(0, 0, 0);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 1); glVertex3f(-20.0f, -1.0f, -20.0f);
	glTexCoord2d(1, 1); glVertex3f(-20.0f, -1.0f, 80.0f);
	glTexCoord2d(1, 0); glVertex3f(80.0f, -1.0f, 80.0f);
	glTexCoord2d(0, 0); glVertex3f(80.0f, -1.0f, -20.0f);
	glEnd();
	glEnable(GL_LIGHTING);

    //Liberar memoria de la textura
   // glBindTexture(GL_TEXTURE_2D, 0);

	tablero.dibuja();
    piezas.dibuja();
    if (piezas.si) {
        tablero.PintarMovPosibles(piezas.coordenadaPintar, piezas.coordenadaComer);
     
    }
}


void partida::mouse(int button, int state, int x, int y)
{
    printf_s("%d, %d\n", button, state);

    static int columna = 0;
    static int fila = 0;
    static pieza* aux;
    

    if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN )) {
        getColFilMouse(x, y, fila, columna);
        aux = piezas.buscarPieza(fila, columna);
        piezas.movPosibles(aux);

    }

    
    if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_UP)) {
        getColFilMouse(x, y, fila, columna);
        piezas.moverPieza(aux, fila, columna);
        piezas.si = false;
        
    }
}


void partida::getColFilMouse(int x, int y, int &fila, int &columna)
{
    int x0 = 0, y0 = 0; // ESTE ES EL NUEVO 0,0 QUE SE DEFINE MAS ABAJO
    int c, f;

//te dice en que coordenadas has hecho clik exactamente con el (0,0) en la esquina de abajo del tablero (LAS X TIENES SENTIDO POSITIVO Y LAS Y NEGATIVO, SE TRABAJA EN EL CUARTO CUADRANTE)
    x0 = x - 170;
    y0 = y - 657;
    printf_s("x0: %d y0: %d\n", x0, y0);
    c = 0;
    f = 0;
    if (((x0 > -1) && (x0 < 661)) && ((y0 < 1) && (y0 > -620))) {
        for (int i = 1; i < 9; i++) {

            if ((x0 > c) && (x0 < (c + 82))) {

                columna = i; //te estable la columna un intervalo 

            }


            if ((y0 < -f) && (y0 > -(f + 75))) {

                fila = i; // te establece la fila un intervalo
            }

            //esto varia si se cambian las dimensiones de la ventada creada por freeglut
            c = c + 82; //82 son los pixeles que ocupa una casilla en x
            f = f + 77; //77 son los pixeles que ocupa una casilla en y
        }
        printf_s("columna: %d, fila: %d \n", columna, fila); //te dice la columna y la fila que has hecho click
    }
    else std::cout << "MOVIMIENTO INCORRECTO: FUERA DE RANGO" << endl;
}




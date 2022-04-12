
#include "freeglut.h"
#include "partida.h"

partida iPartida;

bool o = FALSE;
coordenada b("a", 2);

//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
void Mouse(int button, int state, int x, int y); //cuando se pulse el raton

int main(int argc,char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(1000,700);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
	glutCreateWindow("Chess");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective( 40.0, 800/600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25,OnTimer,0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	glutMouseFunc(Mouse);

	//Creamos el tablero
	iPartida.inicializa();
		
	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();	

	return 0;   
}

void OnDraw(void)
{
	//Borrado de la pantalla	
   	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();

	iPartida.dibuja();

	if (o == TRUE) {
		iPartida.irey.dibuja();
	}

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//poner aqui el código de teclado

	glutPostRedisplay();
}

void OnTimer(int value)
{
//poner aqui el código de animacion

	//no borrar estas lineas
	glutTimerFunc(25,OnTimer,0);
	glutPostRedisplay();
}
void Mouse(int button, int state, int x, int y) {

	printf_s("%d, %d\n", button, state);
	printf_s("x: %d y: %d\n", x, y); // te dice en que coordenadas has hecho clik exactamente con el (0,0) en la esquina de arriba de la ventana 

	int x0 = 0, y0 = 0;
	int columna = -1;
	int fila = 0;
	int c, f;

	if (button == GLUT_LEFT_BUTTON && (state == GLUT_DOWN || state == GLUT_UP)) {

		//Prueba movimiento de la pieza lo inicializa todo desde aqui para el cambio de posicion
		
		iPartida.irey.coord = b;
		o = TRUE;

		//te dice en que coordenadas has hecho clik exactamente con el (0,0) en la esquina de abajo del tablero
		x0 = x - 170;
		y0 = y - 657;
		printf_s("x0: %d y0: %d\n", x0, y0);
		c = 0;
		f = 0;
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
		b = { b.tostring(fila),columna }; //terminar despues hay que mirar que pasa si hago click fuera del tablero
		//b es una variable global que luego la tendremos que sustituir por la pieza que estemos seleccionando

		printf_s("columna: %d, fila: %d \n", columna, fila); //te dice la columna y la fila que has hecho click
		
	}
	
	//no borrar
	glutPostRedisplay();
}

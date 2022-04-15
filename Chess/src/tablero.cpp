#include "tablero.h"
#include "freeglut.h"


void tablero::dibuja()
{
	//Textura
	//glEnable(GL_TEXTURE_2D);
	//glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/tablero3.png").id);
	float A = 0.0f, B = 0.0f;
	unsigned int r, g, b;
	for (int i = 1; i < 9; i++) {
		for (int j = 1; j < 9; j++) {
			if (((i % 2 != 0) && (j % 2 != 0)) || ((i % 2 == 0) && (j % 2 == 0))) {

				r = 129;
				g = 96;
				b = 79;
			}
			else {

				r = 195;
				g = 159;
				b = 129;
			}

			glDisable(GL_LIGHTING);
			glColor3ub(r, g, b);
			glBegin(GL_POLYGON);
			glTexCoord2d(0, 1); glVertex3f(B, 0.0f, A);
			glTexCoord2d(1, 1); glVertex3f(B, 0.0f, A+8.0f);
			glTexCoord2d(1, 0); glVertex3f(B + 8.0f, 0.0f, A + 8.0f);
			glTexCoord2d(0, 0); glVertex3f(B + 8.0f, 0.0f,A);
			glEnd();
			glEnable(GL_LIGHTING);
			A = A + 8.0f;

		}
		A = 0.0f;
		B = B + 8.0f;
	}
}

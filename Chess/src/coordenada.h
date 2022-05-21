#pragma once

#include<iostream>

enum{};
using namespace std;
class vector2D;
enum color{NEGRO, BLANCO, NONE};

class coordenada
{
	string letra;
	int numero;
public:

	coordenada();
	coordenada(string letra, int numero);
	coordenada(int fila, int columna);
	vector2D toVector();
	string toLetraCol(int numero); 
	int getFila();
	int getColumna();
	string getLetra() { return letra; }
	void setCol(int columna);
	void setFil(int fila);
	color getColorCasilla();

	bool operator==(coordenada coord);
	coordenada operator-(coordenada coord);

};


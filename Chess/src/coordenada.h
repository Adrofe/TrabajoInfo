#pragma once

#include<iostream>

enum{};
using namespace std;
class vector2D;

class coordenada
{
	string letra;
	int numero;
public:

	coordenada(string letra, int numero);
	coordenada();
	void toChess(vector2D vector);
	vector2D toVector();


};


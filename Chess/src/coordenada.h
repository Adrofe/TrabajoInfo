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

	coordenada();
	coordenada(string letra, int numero);
	void toChess(vector2D vector);
	vector2D toVector();
	string tostring(int numero);


};


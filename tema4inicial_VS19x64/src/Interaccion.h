#pragma once
#include "Vector2D.h"
#include "Hombre.h"
#include "Caja.h"
#include "Esfera.h"
#include "Disparo.h"
#include "Pared.h"

class Interaccion
{
public:
	static void rebote(Hombre& h, Caja c);
	static bool rebote(Esfera& e, Pared p);
	static void rebote(Esfera& e, Caja c);
	static void rebote(Esfera& e1, Esfera& e2);
	static bool colision(Esfera e, Hombre h);

	static bool colision(Disparo& d, Pared p);
	static bool colision(Disparo& d, Caja c);
	static bool colision(Disparo d, Esfera e);
};
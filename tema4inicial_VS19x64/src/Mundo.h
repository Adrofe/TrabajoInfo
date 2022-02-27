#include "Caja.h"
#include "Hombre.h"
#include "Esfera.h"
#include "Disparo.h"
#include "ListaEsferas.h"
#include "ListaDisparos.h"
#include "EsferaPulsante.h"
#include "DisparoEspecial.h"

class Mundo
{
private:
	ListaEsferas esferas;
	ListaDisparos disparos;


public:
	Hombre hombre;
	Caja caja;
	Pared plataforma;	
	EsferaPulsante esferaPulsante;
	DisparoEspecial disparo_Especial;

public:
	~Mundo();

	void tecla(unsigned char key);
	void inicializa();
	void rotarOjo();
	void mover();
	void dibuja();
	void teclaEspecial(unsigned char key);

	float x_ojo;
	float y_ojo;
	float z_ojo;
};

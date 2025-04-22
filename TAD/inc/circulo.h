#ifndef CIRCULO_H
# define CIRCULO_H

# include "general.h"
# include "ponto.h"

typedef struct s_circulo
{
	float raio;
	Ponto centro;
} Circulo; 

Circulo 	*C_cria(float raio, Ponto centro);
void		C_liberta(Circulo *C);
float		C_calcular_area(Circulo *C);
bool		C_interior(Circulo *C, Ponto *P);


#endif
#include "../inc/circulo.h"

Circulo *C_cria(float raio, Ponto centro)
{
	Circulo *C = (Circulo *)malloc(sizeof(Circulo));
	if (C == NULL)
	{
		printf("Erro ao alocar memoria para o circulo\n");
		return NULL;
	}
	C->raio = raio;
	C->centro = centro;
	return C;
}

void	C_liberta(Circulo *C)
{
	if (C != NULL)
	{
		free(C);
		C = NULL;
	}
}

float	C_calcular_area(Circulo *C)
{
	if (C == NULL)
		return -1;
	return M_PI * C->raio * C->raio;
}

bool	C_interior(Circulo *C, Ponto *P)
{
	if (C == NULL || P == NULL)
		return false;
	float distancia = P_calcular_distancia(&C->centro, P);
	return distancia < C->raio;
}
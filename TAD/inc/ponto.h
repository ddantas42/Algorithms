#ifndef PONTO_H
# define PONTO_H

# include "general.h"

typedef struct ponto
{
	float x;
	float y;
} Ponto;

void	P_imprimir_ponto(Ponto *P);
void	P_ler_ponto(Ponto *P);
Ponto	P_somar_pontos(Ponto *P1, Ponto *P2);
float 	P_calcular_distancia(Ponto *P1, Ponto *P2);
void	P_espelhar(Ponto *P);
Ponto	P_ponto_medio(Ponto *P1, Ponto *P2);
Ponto	P_ponto_medio_varios(Ponto **P);

#endif

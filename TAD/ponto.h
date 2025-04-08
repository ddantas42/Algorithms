#ifndef PONTO_H
# define PONTO_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct ponto
{
	float x;
	float y;
} Ponto;

void	imprimir_ponto(Ponto *P);
void	ler_ponto(Ponto *P);
Ponto	somar_pontos(Ponto *P1, Ponto *P2);
float 	calcular_distancia(Ponto *P1, Ponto *P2);
void	espelhar(Ponto *P);
Ponto	ponto_medio(Ponto *P1, Ponto *P2);
Ponto	ponto_medio_varios(Ponto **P);

#endif

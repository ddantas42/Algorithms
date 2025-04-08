#include "ponto.h"

void	imprimir_ponto(Ponto *P)
{
	printf("Ponto: (%.2f, %.2f)\n", P->x, P->y);
}

void	ler_ponto(Ponto *P)
{
	printf("Digite as coordenadas do ponto (x,y):\n");
	printf("x: ");
	scanf("%f", &P->x);
	printf("y: ");
	scanf("%f", &P->y);
}

Ponto	somar_pontos(Ponto *P1, Ponto *P2)
{
	Ponto soma;
	soma.x = P1->x + P2->x;
	soma.y = P1->y + P2->y;
	return soma;
}

float 	calcular_distancia(Ponto *P1, Ponto *P2)
{
	float dx = P2->x - P1->x;
	float dy = P2->y - P1->y;
	return sqrt(dx * dx + dy * dy);
}

void	espelhar(Ponto *P)
{
	float temp = P->x;
	P->x = P->y;
	P->y = temp;
	printf("Ponto espelhado: (%f, %f)\n", P->x, P->y);
}

Ponto	ponto_medio(Ponto *P1, Ponto *P2)
{
	Ponto meio;
	meio.x = (P1->x + P2->x) / 2;
	meio.y = (P1->y + P2->y) / 2;
	return meio;
}

Ponto	ponto_medio_varios(Ponto **P)
{
	Ponto	meio;
	int		n = 0;
	meio.x = 0;
	meio.y = 0;

	if (P == NULL)
		return meio;
	while (*P != NULL)
	{
		meio.x += (*P)->x;
		meio.y += (*P)->y;
		P++;
		n++;
	}
	meio.x /= n;
	meio.y /= n;
	return meio;
}
#include "ponto.h"

void testar_ponto();
void imprimir_pontos(Ponto *P1, Ponto *P2, Ponto *P3);
void somar_pontos_test(Ponto *P1, Ponto *P2, Ponto *P3);
void calcular_distancia_test(Ponto *P1, Ponto *P2, Ponto *P3);
void espelhar_ponto_test(Ponto *P1);
void ponto_medio_test(Ponto *P1, Ponto *P2);
void ponto_medio_varios_test(Ponto *P1, Ponto *P2, Ponto *P3);

int main()
{
	Ponto P1, P2, P3;

	testar_ponto(&P1, &P2, &P3);
	imprimir_pontos(&P1, &P2, &P3);
	somar_pontos_test(&P1, &P2, &P3);
	calcular_distancia_test(&P1, &P2, &P3);
	espelhar_ponto_test(&P1);
	ponto_medio_test(&P1, &P2);
	ponto_medio_varios_test(&P1, &P2, &P3);

	printf("---- Fim dos testes ----\n");
	printf("Pressione Enter para sair...");
	getchar();
	getchar();
	return 0;
}

void testar_ponto(Ponto *P1, Ponto *P2, Ponto *P3)
{
	printf("---- Testar Ponto ----\n");
	printf("Digite as coordenadas dos seguintes tres pontos:\n");
	printf("Ponto 1:\n"), ler_ponto(P1);
	printf("Ponto 2:\n"), ler_ponto(P2);
	printf("Ponto 3:\n"), ler_ponto(P3);
}

void imprimir_pontos(Ponto *P1, Ponto *P2, Ponto *P3)
{
	printf("---- Imprimir Pontos ----\n");
	imprimir_ponto(P1);
	imprimir_ponto(P2);
	imprimir_ponto(P3);
}

void somar_pontos_test(Ponto *P1, Ponto *P2, Ponto *P3)
{
	printf("---- Somar Pontos ----\n");
	Ponto soma = somar_pontos(P1, P2);
	printf("Soma de Ponto 1 e Ponto 2: ");
	imprimir_ponto(&soma);

	printf("Soma de Ponto 2 e Ponto 3: ");
	soma = somar_pontos(P2, P3);
	imprimir_ponto(&soma);
}

void calcular_distancia_test(Ponto *P1, Ponto *P2, Ponto *P3)
{
	printf("---- Calcular Distancia ----\n");
	printf("Distancia entre Ponto 1 e Ponto 2: %.2f\n", calcular_distancia(P1, P2));
	printf("Distancia entre Ponto 2 e Ponto 3: %.2f\n", calcular_distancia(P2, P3));
}

void espelhar_ponto_test(Ponto *P1)
{
	printf("---- Espelhar Ponto 1 ----\n");
	imprimir_ponto(P1);
	printf("Ponto 1 espelhado: ");
	espelhar(P1);
	imprimir_ponto(P1);
}

void ponto_medio_test(Ponto *P1, Ponto *P2)
{
	printf("---- Ponto Medio ----\n");
	Ponto meio = ponto_medio(P1, P2);
	printf("Ponto medio entre Ponto 1 e Ponto 2: ");
	imprimir_ponto(&meio);
}

void ponto_medio_varios_test(Ponto *P1, Ponto *P2, Ponto *P3)
{
	printf("---- Ponto Medio Varios ----\n");
	Ponto **pontos = (Ponto **)malloc(4 * sizeof(Ponto *));
	pontos[0] = P1;
	pontos[1] = P2;
	pontos[2] = P3;
	pontos[3] = NULL;
	Ponto meio_varios = ponto_medio_varios(pontos);
	printf("Ponto medio entre Ponto 1, Ponto 2 e Ponto 3: ");
	imprimir_ponto(&meio_varios);
	free(pontos);
}
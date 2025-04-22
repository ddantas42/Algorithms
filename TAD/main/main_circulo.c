#include "../inc/ponto.h"
#include "../inc/circulo.h"


void criar_circulos(Circulo **C1, Circulo **C2, Circulo **C3)
{
	Ponto	centros[3] = {0, 0, 0};
	float	raios[3] = {0, 0, 0};

	for (int i = 0; i < 3; i++)
	{
		printf("Digite as coordenadas do centro do circulo %d:\n", i + 1);
		P_ler_ponto(&centros[i]);
		printf("Digite o raio do circulo %d: ", i + 1);
		scanf("%f", &raios[i]);
	}
	*C1 = C_cria(raios[0], centros[0]);
	*C2 = C_cria(raios[1], centros[1]);
	*C3 = C_cria(raios[2], centros[2]);
}

void calcular_area(Circulo *C1, Circulo *C2, Circulo *C3)
{
	printf("Area do circulo 1: %.2f\n", C_calcular_area(C1));
	printf("Area do circulo 2: %.2f\n", C_calcular_area(C2));
	printf("Area do circulo 3: %.2f\n", C_calcular_area(C3));
}

void verificar_interior(Circulo *C1, Circulo *C2, Circulo *C3, int size)
{
	Circulo *circulos[3] = {C1, C2, C3};

	Ponto p1, p2;
	printf("Digite as coordenadas do ponto 1:\n"); P_ler_ponto(&p1);
	printf("Digite as coordenadas do ponto 2:\n"); P_ler_ponto(&p2);
	for (int i = 0; i < size; i++)
	{
		if (C_interior(circulos[i], &p1))
			printf("Ponto 1 esta dentro do circulo %d\n", i + 1);
		else
			printf("Ponto 1 nao esta dentro do circulo %d\n", i + 1);
		if (C_interior(circulos[i], &p2))
			printf("Ponto 2 esta dentro do circulo %d\n", i + 1);
		else
			printf("Ponto 2 nao esta dentro do circulo %d\n", i + 1);
	}
}

void print_circles(Circulo *C1, Circulo *C2, Circulo *C3)
{
	printf("---- Imprimir Circulos ----\n");
	printf("Circulo 1: Centro: (%.2f, %.2f), Raio: %.2f\n", C1->centro.x, C1->centro.y, C1->raio);
	printf("Circulo 2: Centro: (%.2f, %.2f), Raio: %.2f\n", C2->centro.x, C2->centro.y, C2->raio);
	printf("Circulo 3: Centro: (%.2f, %.2f), Raio: %.2f\n", C3->centro.x, C3->centro.y, C3->raio);
}

int main()
{
	Circulo *C1, *C2, *C3;
	
	printf("---- Criar Circulos ----\n");
	criar_circulos(&C1, &C2, &C3);
	printf("Circulo 1: Centro: (%.2f, %.2f), Raio: %.2f\n", C1->centro.x, C1->centro.y, C1->raio);


	print_circles(C1, C2, C3);
	printf("---- Calcular Area ----\n");
	calcular_area(C1, C2, C3);

	printf("---- Verificar se pontos estao dentro dos circulos ----\n");
	verificar_interior(C1, C2, C3, 3);

	printf("---- Libertar memoria ----\n");
	C_liberta(C1);
	C_liberta(C2);
	C_liberta(C3);

	return 0;
}

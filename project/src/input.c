#include "../inc/project.h"

static int verificar_formato(int scanf_nbr, t_lists *lists)
{
	if (scanf_nbr > 0)
		return 0;

	if (scanf_nbr == EOF)
		free_lists(lists, "Error: EOF detected. Closing...\n");
		
	printf("Error: Invalid Input\n");

	scanf("%*[^\n]");
	fflush(NULL);

	return 1;
}

int ler_int(char *prompt, char *err, int limit_down, int limit_up, t_lists *lists)
{
	int n = -1;
	int scanf_nbr = -1;

	do
	{
		printf("%s", prompt);

		scanf_nbr = scanf("%d", &n);
		scanf("%*[^\n]");
		fflush(stdin);

		if (verificar_formato(scanf_nbr, lists) == 1)
			continue;

		if (n < limit_down || n > limit_up)
			printf("%s", err);

	} while (n < limit_down || n > limit_up);
	
	fflush(NULL);
	return n;
}
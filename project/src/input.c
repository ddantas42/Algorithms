#include "../inc/project.h"

/*
 * verificar_formato - Checks the format of the input read by scanf.
 * @param scanf_nbr: The return value of scanf indicating the number of items read.
 * @param lists: Pointer to the lists structure for error handling.
 * @return 0 if the input is valid, 1 if there is an error.
*/
static int verificar_formato(int scanf_nbr, t_lists *lists)
{
	if (scanf_nbr > 0)
		return 0;

	if (scanf_nbr == EOF)
		free_lists(lists, "Error: EOF detected. Closing...\n", 1);
		
	printf("Error: Invalid Input\n");

	scanf("%*[^\n]");
	fflush(NULL);

	return 1;
}


/*
 * ler_int - Reads an integer from the user with a prompt and error message.
 * @param prompt: The prompt message to display to the user.
 * @param err: The error message to display if the input is invalid.
 * @param limit_down: The minimum valid value for the input.
 * @param limit_up: The maximum valid value for the input.
 * @param lists: Pointer to the lists structure for error handling.
*/
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
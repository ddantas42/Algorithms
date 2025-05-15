#include "../inc/project.h"

int main()
{
	t_patiente *blue = NULL;
	t_patiente *gree = NULL;
	int option;

	do
	{
		printf(MAIN_MENU);
		scanf("%d", &option);

		switch (option)
		{
			case 1:
				register_new_patient(&head);
				break;
			case 9:
				printf("Exiting...\n");
				break;
			default:
				printf("Invalid option. Please try again.\n");
		}
	} while (option != 2);

	free_list(head);

	return 0;
}
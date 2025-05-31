#include "../inc/project.h"

// static void clear_screen()
// {
// 	#ifdef _WIN32
// 	    system("cls");
// 	#else
// 	    system("clear");
// 	#endif
// }

static t_lists *init_lists()
{
	t_lists *lists = (t_lists *)calloc(1, sizeof(t_lists));
	if (!lists)
	{
		printf("Failed to allocate memory for lists\n");
		exit(1);
	}

	lists->color_names = (char **)calloc(6 + 1, sizeof(char *));
	if (!lists->color_names)
	{
		free(lists);
		printf("Failed to allocate memory for color names\n");
		exit(1);
	}
	char *colors[] = {"Blue", "Green", "Yellow", "Orange", "Red", "None"};
	for (int i = 0; i < 6; i++)
	{
		lists->color_names[i] = (char *)calloc(7 + 1, sizeof(char));
		if (!lists->color_names[i])
			free_lists(lists, "Failed to allocate memory for color names", 1);
		strcpy(lists->color_names[i], colors[i]);
	}
	
	return lists;
}

int main()
{
	t_lists	*list = init_lists();
	int		option = 0;

	// Time in minutes
	int		current_time = 0;
	
	// clear_screen();
	do
	{
		printf(MAIN_MENU, current_time / 60, current_time % 60);
		option = ler_int(MENU_PROMPT,MENU_ERR, 0, 11, list);

		switch (option)
		{
			case 0: break;
			case 1:	register_new_patient(list, current_time); break;
			case 2:	call_patient_to_triage(list, current_time); break;

			case 6: visualize_patients_waiting_triage(list); break;
			
			case 10: print_every_list(list); break;

			case 11: printf("Exiting...\n"); break;
		}

		// Update time
		if (option == 0)
			current_time += ler_int("\nTime passed (minutes): ", "Invalid time. Please enter a valid time in minutes. (0 - 1440)\n",0, 1440, list);
			
		update_patients(list, current_time);
		
	} while (option != 11);

	free_lists(list, "Exiting program. Freeing resources...\n", 0);

	return 0;
}

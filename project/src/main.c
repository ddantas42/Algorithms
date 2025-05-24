#include "../inc/project.h"

t_lists *init_lists()
{
	t_lists *lists = (t_lists *)malloc(sizeof(t_lists));
	if (!lists)
	{
		printf("Failed to allocate memory for lists\n");
		exit(1);
	}
	lists->blue = NULL;
	lists->green = NULL;
	lists->yellow = NULL;
	lists->orange = NULL;
	lists->red = NULL;

	lists->triage = NULL;
	lists->attendance_waiting = NULL;
	lists->attendance = NULL;
	lists->attended = NULL;
	return lists;
}

int main()
{
	t_lists	*list = init_lists();
	int		option = 0;

	// Time in minutes
	int		current_time = 0;

	do
	{
		printf(MAIN_MENU, current_time / 60, current_time % 60);
		scanf("%d", &option);

		switch (option)
		{
			case 1:	register_new_patient(list, current_time); break;
			case 2: call_patient_to_triage(list); break;

			case 6: visualize_patients_waiting_triage(list); break;

			case 10: printf("Exiting...\n"); break;

			default: printf("Invalid option. Please try again.\n");
		}

		if (option >= 1 && option <= 3)
			update_time(&current_time);
		update_patients(list, current_time);
		
	} while (option != 10);

	free_lists(list);

	return 0;
}
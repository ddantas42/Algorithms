#include "../../inc/project.h"

static t_patiente *select_patient(t_patiente **non_null_lists, int size)
{
	(void)non_null_lists;
	(void)size;
	return NULL;
}

/**
 * Calls a person to triage based on colors and time spent
 * A patiente with red color will be immediatly called if there are any
 * After that each color has a chance of getting called, only one will be selected
 * Blue has 10%, Green has 15%, Yellow has 25% and Orange has 50%
 */
void	call_patient_to_triage(t_lists *lists)
{
	t_patiente *patiente_to_triage = NULL;
	t_patiente	**non_null_lists = NULL;
	int			size_of_lists = 0;

	if (lists->red == NULL)
	{
		// get non null lists and get total of them
		non_null_lists = get_waiting_for_triage_lists(lists);
		for (int i = 0; i < 4; i++)
			if (non_null_lists[i] != NULL)
				size_of_lists++; 
		
		patiente_to_triage = select_patient(non_null_lists, size_of_lists);				

		// generate random number from 1 to 100
		// srand(time(NULL));
		// random_number = rand() % 101;

		// if (random_number <= 10)
		// 	patiente_to_triage = pop_bottom(&lists->blue);
		// else if (random_number <= 25)
		// 	patiente_to_triage = pop_bottom(&lists->green);
		// else if (random_number <= 50)
		// 	patiente_to_triage = pop_bottom(&lists->yellow);
		// else 
		// 	patiente_to_triage = pop_bottom(&lists->orange);
	}
	else
		patiente_to_triage = pop_bottom(&lists->red);

	if (patiente_to_triage == NULL)
		printf("Couldn't find any patient to go on triage\n");
	else 
	{
		printf("Patient %s selected for triage", patiente_to_triage->name);
		insert(&lists->triage, patiente_to_triage);
	}
}
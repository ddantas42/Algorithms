#include "../../inc/project.h"

/**
 * Selects the patient that will go to triage after red list is empty
 * After getting the non_null_lists, it will select list for the patient to be pulled from
 * With the following chances:
 * If there are 4 lists: List1 10%, List2 15%, List3 25% and List4 50%
 * If there are 3 lists: List1 15%, List2 25% and List3 60%
 * If there are 2 lists: List1 25% and List2 75%
 * If there is 1 list: List1 100%
 * List1 has priority over List2, List2 over List3 and List3 over List4
 */
static t_patiente *select_patient(t_patiente **non_null_lists, int size)
{
	t_patiente *selected_patient = NULL;
	int 		random_number = 0;
	int			limits[4] = {10, 25, 50, 100}; // basic case when size == 4
	
	if (size == 0)
		return NULL;
	else if (size == 1)
		return pop_bottom(&non_null_lists[0]);
	else if (size == 2)
	{
		limits[0] = 25;
		limits[1] = 100;
	}
	else if (size == 3)
	{
		limits[0] = 15;
		limits[1] = 50;
		limits[2] = 100;
	}

	// Generate a random number between 1 and 100
	srand(time(NULL));
	random_number = rand() % 100 + 1; // 1 to 100

	if (random_number <= limits[0])
		selected_patient = pop_bottom(&non_null_lists[0]);
	else if (random_number <= limits[1])
		selected_patient = pop_bottom(&non_null_lists[1]);
	else if (random_number <= limits[2])
		selected_patient = pop_bottom(&non_null_lists[2]);
	else if (random_number <= limits[3])
		selected_patient = pop_bottom(&non_null_lists[3]);

	return selected_patient;
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

	printf("\n ---- Call patient to triage ---- \n");
	
	if (lists->red == NULL)
	{
		// get non null lists and get total of them
		non_null_lists = get_waiting_for_triage_lists(lists);
		for (int i = 0; i < 4; i++)
			if (non_null_lists[i] != NULL)
				size_of_lists++; 
		
		patiente_to_triage = select_patient(non_null_lists, size_of_lists);				
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
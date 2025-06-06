#include "../../inc/project.h"

/**
 * Calculates and prints the average wait time between patient registration and the beginning of triage.
 * This function iterates through all relevant patient lists (triage, blue, green, yellow, orange, red, attendance, attended)
 * and calculates the total wait time from registration to the beginning of triage for each patient.
 * It then computes the average wait time and prints it in hours and minutes.
 * @note No separatin between colors since it's not relevant for this operation.
 * @param list Pointer to the list of patients.
 */
void	avg_time_register_and_beginning_triage_per_queue(t_lists *list)
{
	int 		total_wait_time = 0;
	int 		count = 0;
	t_patient 	*current = NULL;
	t_patient 	*relevant_lists[] = {
		list->triage, list->blue, list->green, list->yellow,
		list->orange, list->red, list->attendance, list->attended, NULL
	}; 

	printf("\n ---- Average Wait Time Between Register and Beginning of Triage ---- \n");

	for (size_t i = 0; i < sizeof(relevant_lists) / sizeof(relevant_lists[0]) ; i++)
	{
		current = relevant_lists[i];
		while (current != NULL)
		{
			total_wait_time += (current->triage_time - current->arrive_time);
			count++;
			current = current->next;
		}
	}

	if (count == 0)
	{
		printf("\tNo patients have been called to triage yet.\n");
		return;
	}

	printf("Average wait time between registration and beginning of triage: %d hours and %.2d minutes\n", TIME((int)(total_wait_time / count)));
}
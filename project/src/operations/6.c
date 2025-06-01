#include "../../inc/project.h"

/**
 * Visualizes the patients currently waiting for triage.
 * This function iterates through the list of patients waiting for triage
 * and prints their details, including ID, name, age, color, and arrival time.
 * If there are no patients waiting for triage, it prints a message indicating that.
 * @param lists Pointer to the list of patients.
 */
void 	visualize_patients_waiting_triage(t_lists *lists)
{
	t_patient *current = NULL;

	printf("\n ---- Patients Waiting for Triage ---- \n");
	
	if (lists->arrive == NULL)
	{
		printf("\tNo patients waiting for triage.\n");
		return;
	}

	current = lists->arrive;

	printf("Patients waiting for triage:\n");
	while (current != NULL)
	{
		printf("\tPatient ID: %d, Name: %s, Age: %d, Color: %s, Arrive Time: %d:%.2d\n",
			current->id, current->name, current->age,
			lists->color_names[current->color],
			TIME(current->arrive_time));
		current = current->next;
	}
}
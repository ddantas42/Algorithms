#include "../../inc/project.h"


/**
 * Calls a patient to triage from the arrival list.
 * This function pops the top patient from the arrival list,
 * sets their triage time to the current time, and inserts them into the triage list.
 * If there are no patients in the arrival list, it prints a message indicating that.
 * @param lists Pointer to the list of patients.
 * @param current_time The current time in minutes.
 */
void	call_patient_to_triage(t_lists *lists, int current_time)
{
	t_patient *patiente_to_triage = NULL;

	printf("\n ---- Call patient to Triage ---- \n");
	
	if (lists->arrive == NULL)
	{
		printf("No patients registered to call to triage.\n");
		return;
	}

	patiente_to_triage = pop_top(&lists->arrive);
	patiente_to_triage->triage_time = current_time;
	insert(&lists->triage, patiente_to_triage);
	printf("Patient %d: %s selected for triage\n", patiente_to_triage->id, patiente_to_triage->name);
}

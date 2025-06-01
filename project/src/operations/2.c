#include "../../inc/project.h"

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

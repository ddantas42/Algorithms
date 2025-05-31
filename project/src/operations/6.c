#include "../../inc/project.h"

void 	visualize_patients_waiting_triage(t_lists *lists)
{
	if (lists->arrive == NULL)
	{
		printf("\tNo patients waiting for triage.\n");
		return;
	}

	printf("Patients waiting for triage:\n");
	print_list(lists->arrive);
}
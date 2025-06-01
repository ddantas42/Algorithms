#include "../../inc/project.h"

void	register_new_patient(t_lists *lists, int current_time)
{
	static int patient_id = 0; // Static variable to keep track of patient IDs
	t_patient *new_patient = (t_patient *)malloc(sizeof(t_patient));
	if (!new_patient)
	{
		printf("Failed to allocate memory for new patient");
		return;
	}

	printf("\n ---- Registering new patient ---- \n");

	new_patient->id = patient_id++;	
	printf("Enter patient's name: ");
	scanf("%s", new_patient->name);

	new_patient->age = ler_int(PATIENTE_AGE_PROMPT, PATIENT_AGE_ERR, 0, 150, lists);
	new_patient->color = NO_COLOR;
	new_patient->arrive_time = current_time;
	new_patient->triage_time = -1;
	new_patient->attendance_start_time = -1;
	new_patient->waiting_attendance_time = -1;
	new_patient->next = NULL;

	insert(&lists->arrive, new_patient);

	printf("Patient %s registered successfully.\n", new_patient->name);
}

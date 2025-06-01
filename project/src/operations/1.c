#include "../../inc/project.h"

/**
 * Registers a new patient in the system.
 * This function allocates memory for a new patient, prompts the user for their name and age,
 * and initializes the patient's attributes such as ID, color, arrival time, and various timestamps.
 * The new patient is then inserted into the arrival list.
 * @param lists Pointer to the list of patients.
 * @param current_time The current time in minutes, used to set the patient's arrival time.
*/
void	register_new_patient(t_lists *lists, int current_time)
{
	static int patient_id = 0; // Static variable to keep track of patient IDs
	t_patient *new_patient = NULL;

	printf("\n ---- Registering new patient ---- \n");
	
	new_patient = (t_patient *)malloc(sizeof(t_patient));
	if (!new_patient)
	{
		free_lists(lists, "Failed to allocate memory for new patient", 1);
		return;
	}


	new_patient->id = patient_id++;	
	printf("Enter patient's name: ");
	scanf("%s", new_patient->name);

	new_patient->age = ler_int(PATIENTE_AGE_PROMPT, PATIENT_AGE_ERR, 0, 150, lists);
	new_patient->color = NO_COLOR;
	new_patient->arrive_time = current_time;
	new_patient->triage_time = -1;
	new_patient->attendance_start_time = -1;
	new_patient->waiting_attendance_time = -1;
	new_patient->already_attended_time = -1;
	new_patient->next = NULL;

	insert(&lists->arrive, new_patient);

	printf("Patient %s registered successfully.\n", new_patient->name);

	
	if (LEAK_DEBUG)
		printf("DEBUG:\t Allocated patient id=%d, addr=%p\n", new_patient->id, (void*)new_patient);
}

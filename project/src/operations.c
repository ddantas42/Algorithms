#include "../inc/project.h"

void register_new_patient(t_patiente **head)
{
	static int patient_id = 0; // Static variable to keep track of patient IDs
	t_patiente *new_patient = (t_patiente *)malloc(sizeof(t_patiente));
	if (!new_patient)
	{
		perror("Failed to allocate memory for new patient");
		return;
	}

	printf("Enter patient's name: ");
	scanf("%s", new_patient->name);
	printf("Enter patient's age: ");
	scanf("%d", &new_patient->age);
	printf("Enter patient's color (0-4): ");
	scanf("%d", &new_patient->color);

	time_t now = time(NULL);
	new_patient->arrive_time = localtime(&now);
	new_patient->triage_time = NULL;
	new_patient->attendance_start_time = NULL;
	new_patient->next = *head;
	*head = new_patient;

	printf("Patient %s registered successfully.\n", new_patient->name);
}
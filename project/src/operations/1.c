#include "../../inc/project.h"

void	register_new_patient(t_lists *lists, int current_time)
{
	static int patient_id = 0; // Static variable to keep track of patient IDs
	t_patiente *new_patient = (t_patiente *)malloc(sizeof(t_patiente));
	if (!new_patient)
	{
		printf("Failed to allocate memory for new patient");
		return;
	}

	printf("\n ---- Registering new patient ---- \n");

	new_patient->id = patient_id++;	
	printf("Enter patient's name: ");
	scanf("%s", new_patient->name);
	printf("Enter patient's age: ");
	scanf("%d", &new_patient->age);
	printf("Enter patient's color (red = 4 | orange = 3 | yellow = 2 | green = 1 | blue = 0)\nColor: ");
	scanf("%d", &new_patient->color);

	new_patient->arrive_time = current_time;
	new_patient->triage_time = -1;
	new_patient->attendance_start_time = -1;
	new_patient->next = NULL;

	switch (new_patient->color)
	{
		case BLUE: 		insert(&lists->blue, new_patient); 		break;
		case GREEN: 	insert(&lists->green, new_patient); 	break;
		case YELLOW:	insert(&lists->yellow, new_patient); 	break;
		case ORANGE:	insert(&lists->orange, new_patient); 	break;
		case RED: 		insert(&lists->red, new_patient); 		break;

		default:
			printf("Invalid color. Patient not registered.\n");
			free(new_patient);
			return;
	}

	printf("Patient %s registered successfully.\n", new_patient->name);
}
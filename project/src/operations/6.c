#include "../../inc/project.h"

static void	print_list(t_patiente *head)
{
	if (!head)
	{
		printf("\t\tNo patients in this list.\n");
		return;
	}

	t_patiente *current = head;
	char *color_names[] = {"Blue", "Green", "Yellow", "Orange", "Red"};
	while (current)
	{
		printf("\t\tID: %d, Name: %s, Age: %d, Color: %s\n", current->id, current->name, current->age, color_names[current->color]);
		printf("\t\tArrived: %d, Triaged: %d, attended: %d\n", current->arrive_time, current->triage_time, current->attendance_start_time);
		current = current->next;
	}
}

void 	visualize_patients_waiting_triage(t_lists *lists)
{
	printf("Patients waiting for triage:\n");
	
	printf("\tBlue patients:\n");
	print_list(lists->blue);
	
	printf("\tGreen patients:\n");
	print_list(lists->green);
	
	printf("\tYellow patients:\n");
	print_list(lists->yellow);
	
	printf("\tOrange patients:\n");
	print_list(lists->orange);
	
	printf("\tRed patients:\n");
	print_list(lists->red);

	printf("\tPantients in Triage:\n");
	print_list(lists->triage);
	printf("\tPatients waiting for attendance:\n");
	print_list(lists->attendance);
	printf("\tPatients already attended:\n");
	print_list(lists->attended);
}
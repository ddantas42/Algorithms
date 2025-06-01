#include "../../inc/project.h"

# define ATTENDED 0
# define ATTENDANCE 1

void custom_print_attended(t_patient *list, t_lists *lists, int option)
{
	t_patient *current = list;

	if (!current)
	{
		if (option == ATTENDED)
			printf("No Patients attended yet.\n");
		else if (option == ATTENDANCE)
			printf("No patients in attendance yet.\n");
		return;
	}

	if (option == ATTENDED)
		printf("Patients already attended:\n");
	else if (option == ATTENDANCE)
		printf("Patients being attended:\n");

	while (current)
	{
		printf("\tID: %d, Name: %s, Age: %d, Color: %s, Attendance Start Time: %d\n",
			   current->id, current->name, current->age,
			   lists->color_names[current->color], current->attendance_start_time);
		current = current->next;
	}
}


void visualize_patients_already_attended_by_queue(t_lists *lists)
{

	printf("\n ---- Patients Already Attended by Queue ---- \n");

	custom_print_attended(lists->attendance, lists, ATTENDANCE);
	custom_print_attended(lists->attended, lists, ATTENDED);
}
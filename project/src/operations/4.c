#include "../../inc/project.h"

static void print_color_of_list(t_lists *lists, t_patient *attendance_list, int color)
{
	for (t_patient *current = attendance_list; current != NULL; current = current->next)
	{
		if (current->color == color)
		{
			printf("\tPatient ID: %d, Name: %s, Age: %d, Color: %s, Arrive Time: %d:%.2d, attendance started at: %d:%.2d\n",
				current->id, current->name, current->age,
				lists->color_names[current->color],
				TIME(current->arrive_time), TIME(current->attendance_start_time));
		}
	}
}

/**
 * Visualizes the patients currently being treated by queue.
 * This function iterates through the attendance list and prints the details of patients
 * who are currently being treated, grouped by their color.
 * It prints the patient ID, name, age, color, arrival time, and the time they started being treated.
 * If there are no patients being treated, it prints a message indicating that.
 * @param lists Pointer to the list of patients.
 */
void visualize_patients_being_treated_by_queue(t_lists *lists)
{

	printf("\n ---- Patients Being Treated by Queue ---- \n");
	
	if (!lists->attendance)
	{
		printf("No patients being treated\n");
		return ;
	}
	
	for (int i = 0; i < 5; i++)
	{
		printf("\n%s:\n", lists->color_names[i]);
		print_color_of_list(lists, lists->attendance, i);
	}
}
#include "../../inc/project.h"

static void print_color_of_list(t_lists *lists, t_patient *attended_list, int color)
{
	if (attended_list == NULL)
	{
		printf("No patients attended in this color");
		return ;
	}
	for (t_patient *current = attended_list; current != NULL; current = current->next)
	{
		if (current->color == color)
		{
			printf("\tPatient ID: %d, Name: %s, Age: %d, Color: %s, Arrive Time: %d:%.2d, Finished attendance at: %d:%.2d\n",
				current->id, current->name, current->age,
				lists->color_names[current->color],
				TIME(current->arrive_time), TIME(current->already_attended_time));
		}
	}
	
}


void visualize_patients_already_attended_by_queue(t_lists *lists)
{

	printf("\n ---- Patients Already Attended by Queue ---- \n");
	
	if (!lists->attended)
	{
		printf("No patients already attended\n");
		return ;
	}
	
	for (int i = 0; i < 6; i++)
	{
		printf("\n%s:\n", lists->color_names[i]);
		print_color_of_list(lists, lists->attended, i);
	}

}
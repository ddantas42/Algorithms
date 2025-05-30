#include "../inc/project.h"

static void update_triage(t_lists *lists, int current_time, t_patiente ***color_list)
{
	t_patiente *popped = NULL;
	
	if (lists->triage == NULL)
		return ;

	if (current_time - lists->triage->arrive_time >= 10)
	{
		popped = pop_top(&lists->triage);
		popped->waiting_attendance_time = popped->triage_time + 10;
		popped->color = rand() % 5;

		switch (popped->color)
		{
			case BLUE: insert(color_list[BLUE], popped); 	break;
			case GREEN: insert(color_list[GREEN], popped);	 break;
			case YELLOW: insert(color_list[YELLOW], popped); break;
			case ORANGE: insert(color_list[ORANGE], popped); break;
			case RED: insert(color_list[RED], popped);	 break;
		}
		char *color_names[] = {"Blue", "Green", "Yellow", "Orange", "Red"};
		printf("Patient %d (%s) is now waiting for attendance. Given the color %s\n", popped->id, popped->name, color_names[popped->color]);
		update_triage(lists, current_time, color_list);
	}
}

void 	update_patients(t_lists *lists, int current_time)
{
	t_patiente ***color_list = (t_patiente ***)calloc(sizeof(t_patiente **), (4 + 1));

	if (!color_list)
		free_lists(lists, "Malloc error on: ***color_list\n");

	color_list[BLUE] = &lists->blue;
	color_list[GREEN] = &lists->green;
	color_list[YELLOW] = &lists->yellow;
	color_list[ORANGE] = &lists->orange;
	color_list[RED] = &lists->red;
		
	update_triage(lists, current_time, color_list);

	if (color_list)
		free(color_list);
}
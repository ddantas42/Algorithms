#include "../inc/project.h"

/**
 * update_triage - This function updates the triage list by checking if the
 * waiting time of the first patient in the triage exceeds 10 minutes.
 * If it does, the patient is moved to the appropriate color list based on their
 * color and their waiting time is updated.
 * It recursively calls itself to check the next patient in the triage list.
 * @param lists The lists of patients containing the triage and color lists.
 * @param current_time The current time in the simulation.
 * @param color_list A 2D array of pointers to color lists where patients will be moved.
*/
static void update_triage(t_lists *lists, int current_time, t_patient ***color_list)
{
	t_patient *popped = NULL;
	
	if (!lists->triage || current_time - lists->triage->triage_time < TRIAGE_TIME)
		return ;
	popped = pop_top(&lists->triage);
	popped->waiting_attendance_time = popped->triage_time + TRIAGE_TIME;
	popped->color = rand() % 5; // Randomly assign a color to the patient

	switch (popped->color)
	{
		case BLUE: insert(color_list[BLUE], popped); 	break;
		case GREEN: insert(color_list[GREEN], popped);	 break;
		case YELLOW: insert(color_list[YELLOW], popped); break;
		case ORANGE: insert(color_list[ORANGE], popped); break;
		case RED: insert(color_list[RED], popped);	 break;
	}
	printf("Patient %d (%s) is now waiting for attendance. Given the color %s at %d:%.2d\n", popped->id, popped->name, lists->color_names[popped->color], TIME(popped->waiting_attendance_time));
	update_triage(lists, current_time, color_list);
}

/**
 * update_attendance - This function updates the attendance list by checking if the
 * first patient in the attendance list has been there for more than 10 minutes.
 * If they have, they are moved to the attended list and their attended time is updated.
 * It recursively calls itself to check the next patient in the attendance list.
 * @param lists The lists of patients containing the attendance and attended lists.
 * @param current_time The current time in the simulation.
*/
static void update_attendance(t_lists *lists, int current_time)
{
	t_patient *popped = NULL;

	if (!lists->attendance || current_time - lists->attendance->attendance_start_time < ATTENDANCE_TIME)
		return ;
	popped = pop_top(&lists->attendance);
	popped->already_attended_time = popped->attendance_start_time + ATTENDANCE_TIME;
	insert(&lists->attended, popped);
	printf("Patient %d (%s) has been attended at time %d:%.2d\n", popped->id, popped->name, TIME(popped->already_attended_time));
	update_attendance(lists, current_time);
}

/**
 * This function will update the patients in triage and in attendance
 * @param lists The lists of patients
 * @param current_time The current time in the simulation
*/
void 	update_patients(t_lists *lists, int current_time)
{
	t_patient ***color_list = (t_patient ***)calloc(sizeof(t_patient **), (4 + 1));

	if (!color_list)
		free_lists(lists, "Malloc error on: ***color_list\n", 1);

	color_list[BLUE] = &lists->blue;
	color_list[GREEN] = &lists->green;
	color_list[YELLOW] = &lists->yellow;
	color_list[ORANGE] = &lists->orange;
	color_list[RED] = &lists->red;
		
	update_triage(lists, current_time, color_list);

	if (color_list)
		free(color_list);

	update_attendance(lists, current_time);
}
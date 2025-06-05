#include "../../inc/project.h"

/**
 * Selects the patient that will go to triage after red list is empty
 * After getting the non_null_lists, it will select list for the patient to be pulled from
 * With the following chances:
 * If there are 4 lists: List1 10%, List2 15%, List3 25% and List4 50%
 * If there are 3 lists: List1 15%, List2 25% and List3 60%
 * If there are 2 lists: List1 25% and List2 75%
 * If there is 1 list:	 List1 100%
 * List4 has priority over List3, List3 over List2 and List2 over List1
 */
static t_patient *select_patient(t_patient ***non_null_lists, int size)
{
	int 		random_number = 0;
	int			limits[3] = {10, 25, 50}; // basic case when size == 4
	
	if (size == 0)
		return NULL;
	else if (size == 1)
		return pop_top(non_null_lists[0]);
	else if (size == 2)
	{
		limits[0] = 25;
		limits[1] = 100;
	}
	else if (size == 3)
	{
		limits[0] = 15;
		limits[1] = 50;
		limits[2] = 100;
	}

	srand(time(NULL));
	random_number = (rand() % 100) + 1; // 1 to 100

	if (random_number <= limits[0])
		return pop_top(non_null_lists[0]);
	else if (random_number <= limits[1])
		return pop_top(non_null_lists[1]);
	else if (random_number <= limits[2])
		return pop_top(non_null_lists[2]);

	return pop_top(non_null_lists[3]);
}

/**
 * Calls a person to doctor attendance based on colors and time spent
 * A patiente with red color will be immediatly called if there arent any other
 * @param lists Pointer to the list of patients.
 * @param current_time The current time in minutes, used to set the patient's attendance start time.
 */
void	doctor_attendance_on_next_patient(t_lists *lists, int current_time)
{
	t_patient *patiente_to_attendance = NULL;
	t_patient	***non_null_lists = NULL;
	int			size_of_lists = 0;

	printf("\n ---- Call patient to Attendance ---- \n");
	
	if (lists->red == NULL)
	{
		// get non null lists and get total of them
		non_null_lists = get_waiting_for_attendance_lists(lists);
		for (int i = 0; i < 4; i++)
		{
			if (non_null_lists[i] == NULL)
				break; // Slight optimization, no need to check the rest if we already found a NULL
			size_of_lists++;
		}
		
		patiente_to_attendance = select_patient(non_null_lists, size_of_lists);				
		if (non_null_lists)
			free(non_null_lists);
		
	}
	else
		patiente_to_attendance = pop_bottom(&lists->red);

	if (patiente_to_attendance == NULL)
		printf("Couldn't find any patient to go on Attendance\n");
	else 
	{
		printf("Patient %s selected for attendance", patiente_to_attendance->name);
		patiente_to_attendance->attendance_start_time = current_time;
		insert(&lists->attendance, patiente_to_attendance);
	}
}
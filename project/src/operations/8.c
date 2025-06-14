#include "../../inc/project.h"

// Function to calculate the average wait time between registration and the beginning of triage for each queue
// And puts the results in the wait_timer_per_color increases count_per_color arrays.
static void get_times(t_lists *lists, int *wait_timer_per_color, int *count_per_color)
{
	t_patient 	*current = NULL;
	t_patient 	*relevant_lists[] = { lists->attendance, lists->attended, NULL };

	for (size_t i = 0; i < sizeof(relevant_lists) / sizeof(relevant_lists[0]) ; i++)
	{
		current = relevant_lists[i];
		while (current != NULL)
		{
			wait_timer_per_color[current->color] += (current->attendance_start_time - current->triage_time);
			count_per_color[current->color]++;
			current = current->next;
		}
	}
}

// Auxiliar function to print the times formatted in hours and minutes.
static void print_times(t_lists *lists, int *wait_timer_per_color, int *count_per_color)
{
	int avg_time = 0;

	for (int i = 0; i < 6; i++)
	{
		if (count_per_color[i] == 0)
		{
			printf("No patients in %s queue began attendance.\n", lists->color_names[i]);
			continue;
		}
		avg_time = (double)wait_timer_per_color[i] / count_per_color[i];
		printf("Average wait time between beginning of triage and beginning of attendance for %s queue: %d hours and %.2d minutes \n",
			lists->color_names[i], TIME(avg_time));
	}
}

/**
 * Calculates and prints the average wait time between the beginning of triage and the beginning of attendance for each queue.
 * This function iterates through the attendance and attended lists, calculating the total wait time
 * from the beginning of triage to the beginning of attendance for each color.
 * It then computes the average wait time and prints it in hours and minutes.
 * @param lists Pointer to the list of patients.
 */
void	avg_time_beginning_of_triage_and_beginning_of_attendance_per_queue(t_lists *lists)
{

	int	*wait_timer_per_color = (int *)calloc(6 + 1, sizeof(int));
	int	*count_per_color = (int *)calloc(6 + 1, sizeof(int));
	
	if (!wait_timer_per_color || !count_per_color)
	{
		if (wait_timer_per_color)
			free(wait_timer_per_color);
		if (count_per_color)
			free(count_per_color);
		free_lists(lists, "Failed to allocate memory for wait_timer_per_color or count_per_color\n", 1);
	}
	
	printf("\n ---- Average Wait Time Between Beginning of Triage and Beginning of Attendance Per Queue ---- \n");
	
	get_times(lists, wait_timer_per_color, count_per_color);
	print_times(lists, wait_timer_per_color, count_per_color);

	if (wait_timer_per_color)
		free(wait_timer_per_color);
	if (count_per_color)
		free(count_per_color);

}
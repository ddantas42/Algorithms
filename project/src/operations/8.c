#include "../../inc/project.h"

void	avg_time_beginning_of_triage_and_beginning_of_attendance_per_queue(t_lists *lists)
{
	t_patient *current = NULL;
	t_patient *relevant_lists[] = {
		lists->attendance, lists->attended, NULL
	};
	int *wait_timer_per_color = (int *)calloc(6 + 1, sizeof(int));
	int *count_per_color = (int *)calloc(6 + 1, sizeof(int));
	if (!wait_timer_per_color || !count_per_color)
	{
		if (wait_timer_per_color)
			free(wait_timer_per_color);
		if (count_per_color)
			free(wait_timer_per_color);
		free_lists(lists, "Failed to allocate memory for wait_timer_per_color or count_per_color\n", 1);
	}
	

	printf("\n ---- Average Wait Time Between Beginning of Triage and Beginning of Attendance Per Queue ---- \n");

	
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

	for (int i = 0; i < 6; i++)
	{
		if (count_per_color[i] == 0)
		{
			printf("\tNo patients in %s queue began attedance.\n", lists->color_names[i]);
			continue;
		}
		printf("Average wait time between beginning of triage and beginning of attendance for %s queue: %.2f minutes\n",
			lists->color_names[i], (double)wait_timer_per_color[i] / count_per_color[i]);
	}

	if (wait_timer_per_color)
		free(wait_timer_per_color);
	if (count_per_color)
		free(count_per_color);

}
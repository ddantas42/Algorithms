#include "../../inc/project.h"

void	avg_time_register_end_attendnance_per_queue(t_lists *lists)
{
	t_patient 	*current = lists->attended;
	int			*wait_timer_per_color = (int *)calloc(6 + 1, sizeof(int));
	int			*count_per_color = (int *)calloc(6 + 1, sizeof(int));

	if (!wait_timer_per_color || !count_per_color)
	{
		if (wait_timer_per_color)
			free(wait_timer_per_color);
		if (count_per_color)
			free(count_per_color);
		free_lists(lists, "Failed to allocate memory for wait_timer_per_color or count_per_color\n", 1);
	}

	printf("\n ---- Average Wait Time Between Register and Ending of Attendance Per Queue ---- \n");

	while (current != NULL)
	{
		wait_timer_per_color[current->color] += (current->already_attended_time - current->arrive_time);
		count_per_color[current->color]++;
		current = current->next;
	}

	for (int i = 0; i < 6; i++)
	{
		if (count_per_color[i] == 0)
		{
			printf("\tNo patients in %s queue finished attendance.\n", lists->color_names[i]);
			continue;
		}
		printf("Average wait time between register and ending of attendance for %s queue: %.2f minutes\n",
			lists->color_names[i], (double)wait_timer_per_color[i] / count_per_color[i]);
	}

	if (wait_timer_per_color)
		free(wait_timer_per_color);
	if (count_per_color)
		free(count_per_color);
}
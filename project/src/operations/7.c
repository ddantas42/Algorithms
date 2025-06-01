#include "../../inc/project.h"

void	average_wait_time_between_register_and_beginning_triage_per_queue(t_lists *list)
{
	int total_wait_time = 0;
	int count = 0;
	t_patient *lists_after_arrive[] = {
		list->triage,
		list->blue,
		list->green,
		list->yellow,
		list->orange,
		list->red,
		list->attendance,
		list->attended,
		NULL
	}; 
	t_patient *current = NULL;

	printf("\n ---- Average Wait Time Between Register and Beginning of Triage ---- \n");

	for (size_t i = 0; i < sizeof(lists_after_arrive) / sizeof(lists_after_arrive[0]) ; i++)
	{
		current = lists_after_arrive[i];
		while (current != NULL)
		{
			total_wait_time += (current->triage_time - current->arrive_time);
			count++;

			// printf("List: %ld, Count: %d, total_wait_time: %d\n", i, count, total_wait_time);
			current = current->next;
		}
	}

	if (count == 0)
	{
		printf("\tNo patients have been called to triage yet.\n");
		return;
	}

	printf("Average wait time between registration and beginning of triage: %.2f minutes\n", (double)total_wait_time / count);
}
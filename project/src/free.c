#include "../inc/project.h"

free_tree(t_patiente *head)
{
	t_patiente *current = head;
	t_patiente *next;

	while (current != NULL)
	{
		next = current->next;

		if (current->arrive_time != NULL)
			free(current->arrive_time);
		if (current->triage_time != NULL)
			free(current->triage_time);
		if (current->attendance_start_time != NULL)
			free(current->attendance_start_time);
			
		free(current);
		current = next;
	}
}
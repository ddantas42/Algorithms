#include "../inc/project.h"

static void	free_list(t_patiente *head)
{
	if (!head)
		return;
	if (head->next)
		free_list(head->next);
	free(head);
}

void	free_lists(t_lists *list)
{
	if (!list)
		return;

	t_patiente *lists[] = {
		list->blue, list->green, list->yellow, list->orange,
		list->red, list->triage, list->attendance_waiting, list->attendance_waiting, list->attended
	};
		
	for (size_t i = 0; i < 9; ++i)
		free_list(lists[i]);
	free(list);
}

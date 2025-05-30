#include "../inc/project.h"

static void	free_list(t_patiente *head)
{
	if (!head)
		return;
	if (head->next)
		free_list(head->next);
	free(head);
}

void	free_lists(t_lists *list, char *msg)
{
	if (!list)
		return;

	t_patiente *lists[] = {
		list->arrive, 
		list->blue, list->green, list->yellow, list->orange,
		list->red, list->triage, list->attended
	};

	for (size_t i = 0; i < sizeof(lists) / sizeof(lists[0]); ++i)
		free_list(lists[i]);
	free(list);

	if (msg)
		printf("%s\n", msg);

	exit(1);
}

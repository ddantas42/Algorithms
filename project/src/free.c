#include "../inc/project.h"

static void	free_list(t_patient *head)
{
	if (!head)
		return;
	if (head->next)
		free_list(head->next);


	if (LEAK_DEBUG)
		printf("DEBUG:\t \tFreeing patient id=%d, addr=%p\n", head->id, (void*)head);
	
	free(head);
}

/**
 * Frees all lists in the t_lists structure and print a message if provided. Then exists.
 * @param list Pointer to the t_lists structure containing all patient lists.
 * @param msg Optional message to print before exiting.
 * @param exit_status Exit status code to use when exiting the program.
 */
void	free_lists(t_lists *list, char *msg, int exit_status)
{
	if (list)
	{
		if (list->color_names)
		{
			for (int i = 0; i < 6; ++i)
				if (list->color_names[i])
					free(list->color_names[i]);
			free(list->color_names);
		}
		
		t_patient *lists[] = {
			list->arrive, list->triage, 
			list->blue, list->green, list->yellow, list->orange, list->red, 
			list->attendance, list->attended
		};
	
		for (size_t i = 0; i < sizeof(lists) / sizeof(lists[0]); ++i)
		{
			if (lists[i])
			{
				if (LEAK_DEBUG)
					printf("DEBUG:\t Freeing list %zu, head=%p\n", i, (void*)lists[i]);
				free_list(lists[i]);
			}
		}
		free(list);
	}


	if (msg)
		printf("%s\n", msg);

	exit(exit_status);
}

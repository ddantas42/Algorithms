#include "../inc/project.h"

// Inserts a new node at the end of the list.
void	insert(t_patiente **head, t_patiente *new_patient)
{
	if (*head == NULL)
		*head = new_patient;
	else
	{
		t_patiente *current = *head;

		while (current->next != NULL)
			current = current->next;
			
		current->next = new_patient;
	}
	new_patient->next = NULL;
}

// Pops the bottom node from the list.
// Returns the popped node.
t_patiente 	*pop_bottom(t_patiente **head)
{
	if (*head == NULL)
		return NULL;

	t_patiente *current = *head;
	t_patiente *prev = NULL;

	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}

	if (prev != NULL)
		prev->next = NULL;
	else
		*head = NULL;

	return current;
}

t_patiente	*pop_top(t_patiente **head)
{
	t_patiente *top_patient = NULL;
	
	if (*head == NULL)
		return NULL;

	top_patient = *head;
	*head = (*head)->next;
	top_patient->next = NULL;

	return top_patient;
}

/**
 * Get an array of lists ([blue, orange]) that are not null
 * I.e: If only Blue and Green exists, it will return the following array:
 * [blue, green, NULL, NULL, NULL]
 */
t_patiente	***get_waiting_for_triage_lists(t_lists *lists)
{
	t_patiente ***non_null_lists = (t_patiente ***)calloc(sizeof(t_patiente **), (4 + 1));
	int			i = 0;
	if (!non_null_lists)
		free_lists(lists, "Failed to allocate memory for non_null_lists\n");
	
	if (lists->blue != NULL) 	non_null_lists[i++] = &lists->blue;
	if (lists->green != NULL) 	non_null_lists[i++] = &lists->green;
	if (lists->yellow != NULL) 	non_null_lists[i++] = &lists->yellow;
	if (lists->orange != NULL)	non_null_lists[i++] = &lists->orange;

	while (i < 5)
		non_null_lists[i++] = NULL;

	return (non_null_lists);
}
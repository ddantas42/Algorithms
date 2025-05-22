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
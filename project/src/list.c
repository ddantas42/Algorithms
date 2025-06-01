#include "../inc/project.h"

/**
 * Inserts a new patient at the end of the linked list.
 * If the list is empty, it sets the new patient as the head.
 * If the list is not empty, it traverses to the end of the list
 * and appends the new patient there.
 * @param head Pointer to the head of the linked list.
 * @param new_patient Pointer to the new patient to be inserted.
 */
void	insert(t_patient **head, t_patient *new_patient)
{
	if (*head == NULL)
		*head = new_patient;
	else
	{
		t_patient *current = *head;

		while (current->next != NULL)
			current = current->next;
			
		current->next = new_patient;
	}
	new_patient->next = NULL;
}

// Pop the bottom node and returns it.
t_patient 	*pop_bottom(t_patient **head)
{
	if (*head == NULL)
		return NULL;

	t_patient *current = *head;
	t_patient *prev = NULL;

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

// Pop the top node and returns it.
t_patient	*pop_top(t_patient **head)
{
	t_patient *top_patient = NULL;
	
	if (*head == NULL)
		return NULL;

	top_patient = *head;
	*head = (*head)->next;
	top_patient->next = NULL;

	return top_patient;
}

void	print_list(t_lists *lists, t_patient *head)
{
	if (!head)
	{
		printf("\t\tNo patients in this list.\n");
		return;
	}

	t_patient *current = head;
	while (current)
	{
		printf("\t\tID: %d, Name: %s, Age: %d, Color: %s\n", current->id, current->name, current->age, lists->color_names[current->color]);
		printf("\t\tArrived: %d, Triaged: %d, attended: %d\n", current->arrive_time, current->triage_time, current->attendance_start_time);
		current = current->next;
	}
}

/**
 * Get an array of lists ([blue, orange]) that are not null
 * I.e: If only Blue and Green exists, it will return the following array:
 * [blue, green, NULL, NULL, NULL]
 * 
 * This has more uses than it first seems.....
 * 
 * @param lists Pointer to the lists structure containing all patient lists.
 * @return A pointer to an array of pointers to t_patient lists.
 */
t_patient	***get_waiting_for_attendance_lists(t_lists *lists)
{
	t_patient ***non_null_lists = (t_patient ***)calloc(sizeof(t_patient **), (4 + 1));
	int			i = 0;
	
	if (!non_null_lists)
		free_lists(lists, "Failed to allocate memory for non_null_lists\n", 1);
	
	if (lists->blue != NULL) 	non_null_lists[i++] = &lists->blue;
	if (lists->green != NULL) 	non_null_lists[i++] = &lists->green;
	if (lists->yellow != NULL) 	non_null_lists[i++] = &lists->yellow;
	if (lists->orange != NULL)	non_null_lists[i++] = &lists->orange;

	while (i < 5)
		non_null_lists[i++] = NULL;

	return (non_null_lists);
}
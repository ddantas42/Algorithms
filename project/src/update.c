#include "../inc/project.h"

void	update_time(int *current_time)
{
	*current_time += ler_int("\nTime passed (minutes): ", "Invalid time. Please enter a valid time in minutes. (0 - 1440)\n", 0, 1440);

}

static void update_triage(t_patiente *head, int current_time, t_patiente *attedance_waiting)
{
	if (head == NULL)
		return ;

	if (head->next != NULL)
		update_triage(head->next, current_time, attedance_waiting);
	if (current_time - head->triage_time >= 10)
	{
		t_patiente *popped = pop_bottom(&head);
		insert(&attedance_waiting, popped);
	}
}

void 	update_patients(t_lists *lists, int current_time)
{
	update_triage(lists->triage, current_time, lists->attendance_waiting);
}
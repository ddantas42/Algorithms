#include "../../inc/project.h"

static void	print_list(t_patiente *head)
{
	if (!head)
	{
		printf("\t\tNo patients in this list.\n");
		return;
	}

	t_patiente *current = head;
	char *color_names[] = {"Blue", "Green", "Yellow", "Orange", "Red"};
	while (current)
	{
		printf("\t\tID: %d, Name: %s, Age: %d, Color: %s\n", current->id, current->name, current->age, color_names[current->color]);
		printf("\t\tArrived: %d, Triaged: %d, attended: %d\n", current->arrive_time, current->triage_time, current->attendance_start_time);
		current = current->next;
	}
}

void 	visualize_patients_waiting_triage(t_lists *lists)
{
	t_str_list str_list[8] =
	{
		{"\tBlue patients:\n", lists->blue},
		{"\tGreen patients:\n", lists->green},
		{"\tYellow patients:\n", lists->yellow},
		{"\tOrange patients:\n", lists->orange},
		{"\tRed patients:\n", lists->red},
		{"Patients in Triage:\n", lists->triage},
		{"Patients waiting for attendance:\n", lists->attendance_waiting},
		{"Patients already attended:\n", lists->attended}
	};

	printf("Patients waiting for triage:\n");
	for (int i = 0; i < 8; i++)
	{
		if (str_list[i].head == NULL)
			continue;

		printf("%s", str_list[i].str);
		print_list(str_list[i].head);
	}
}
#include "../../inc/project.h"

/**
 * Debug function to print the details of a list of patients.
 * This function iterates through the list of patients and prints their ID, name, age, color,
 * and arrival time in a formatted manner.
 * @param lists Pointer to the list of patients.
 * @param head Pointer to the head of the patient list to be printed.
 */
void 	print_every_list(t_lists *lists)
{
	struct s_str_list {
		char str[40];
		t_patient *head;
	}
	str_list[] = {
		{"Waiting room patients:\n", lists->arrive},
		{"Patients in Triage:\n", lists->triage},
		{"\tBlue patients:\n", lists->blue},
		{"\tGreen patients:\n", lists->green},
		{"\tYellow patients:\n", lists->yellow},
		{"\tOrange patients:\n", lists->orange},
		{"\tRed patients:\n", lists->red},
		{"Patients in Attendance:\n", lists->attendance},
		{"Patients already attended:\n", lists->attended}
	};

	for (size_t i = 0; i < sizeof(str_list) / sizeof(str_list[0]); i++)
	{
		if (str_list[i].head == NULL)
			continue;

		printf("%s", str_list[i].str);
		print_list(lists, str_list[i].head);
	}
}
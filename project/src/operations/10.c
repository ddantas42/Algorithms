#include "../../inc/project.h"

void 	print_every_list(t_lists *lists)
{
	struct s_str_list {
		char str[40];
		t_patiente *head;
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

	for (long unsigned int i = 0; i < sizeof(str_list) / sizeof(str_list[0]); i++)
	{
		if (str_list[i].head == NULL)
			continue;

		printf("%s", str_list[i].str);
		print_list(lists, str_list[i].head);
	}
}
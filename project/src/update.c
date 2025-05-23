#include "../inc/project.h"

void	update_time(int *current_time)
{
	int time_passed = 0;

	printf("\nTime passed (minutes): ");
	scanf("%d", &time_passed);

	*current_time += time_passed;

}

void 	update_patients(t_lists *lists, int current_time)
{
	(void)lists;
	(void)current_time;
}
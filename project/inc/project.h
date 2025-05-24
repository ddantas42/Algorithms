#ifndef PROJECT_H
#define PROJECT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <time.h>
# include <unistd.h>
# include <sys/types.h>
# include <time.h>

/* Non-modifiable Macros */
# define BLUE 0
# define GREEN 1
# define YELLOW 2
# define ORANGE 3
# define RED 4

# define MAIN_MENU "\n\
Current time: [%d:%.2d]\n\
1. Register new patient\n\
2. Call to Triage\n\
3. Doctor attendance on next patient\n\
4. Visualize patients being treated by queue\n\
5. Visualize patients already attended by queue\n\
6. Visualize patients in waiting room for triage\n\
7. Check average wait time per queue between register and beginning of triage\n\
8. Check average wait time per queue between beginning of triage and beginning of attendance\n\
9. Check average wait time per queue between register and ending of attendance\n\
10. Exit\n\
Option: "

typedef struct s_patiente
{
	int 			id;
	char 			name[101];
	int 			age;
	int 			color;
	int  			arrive_time;
	int 			triage_time;
	int 			attendance_start_time;

	struct s_patiente *next;

} t_patiente;


typedef struct s_lists
{
	// Waiting room lists
	t_patiente *blue;
	t_patiente *green;
	t_patiente *yellow;
	t_patiente *orange;
	t_patiente *red;

	// After Waiting room, currently in Triage
	t_patiente *triage;

	// After Triage, currently waiting for attendance
	t_patiente *attendance_waiting;

	// After Waiting for attendance, currently In attendance
	t_patiente *attendance;

	// After attendance, already attended
	t_patiente *attended;
	
} t_lists;

/* List Functions */
void		insert(t_patiente **head, t_patiente *new_patient);
t_patiente 	*pop_bottom(t_patiente **head);
t_patiente	***get_waiting_for_triage_lists(t_lists *lists);

/* Operations Functions */
void	register_new_patient(t_lists *lists, int current_time);
void	call_patient_to_triage(t_lists *lists);
void	visualize_patients_waiting_triage(t_lists *lists);

/* Free Functions */
void	free_lists(t_lists *lists);

/* Update Pantients Functions */
void	update_patients(t_lists *lists, int current_time);
void	update_time(int *current_time);


#endif
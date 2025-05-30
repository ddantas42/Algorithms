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

# include "macros.h"

typedef struct s_patiente
{
	int 			id;
	char 			name[101];
	int 			age;
	int 			color;
	int  			arrive_time;
	int 			triage_time;
	int 			waiting_attendance_time;
	int 			attendance_start_time;

	struct s_patiente *next;

} t_patiente;


typedef struct s_lists
{
	
	// After Register, currently in Waiting room
	t_patiente *arrive;
	
	// After Waiting room, currently in Triage
	t_patiente *triage;
	
	// Waiting room lists to be attended
	t_patiente *blue;
	t_patiente *green;
	t_patiente *yellow;
	t_patiente *orange;
	t_patiente *red;

	// After Waiting for attendance, currently In attendance
	t_patiente *attendance;

	// After attendance, already attended
	t_patiente *attended;
	
} t_lists;

typedef struct s_str_list
{
	char str[40];
	t_patiente *head;
} t_str_list;

/* List Functions */
void		insert(t_patiente **head, t_patiente *new_patient);
t_patiente 	*pop_bottom(t_patiente **head);
t_patiente	*pop_top(t_patiente **head);
t_patiente	***get_waiting_for_triage_lists(t_lists *lists);

/* Operations Functions */
void	register_new_patient(t_lists *lists, int current_time);
void	call_patient_to_triage(t_lists *lists, int current_time);
void	visualize_patients_waiting_triage(t_lists *lists);

/* Free Functions */
void	free_lists(t_lists *lists, char *msg);

/* Update Pantients Functions */
void	update_patients(t_lists *lists, int current_time);

/* Input handle Functions */
int		ler_int(char *prompt, char *err, int limit_down, int limit_up, t_lists *lists);

#endif
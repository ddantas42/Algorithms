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
	int 	id;
	char 	name[101];
	int 	age;
	int 	color;
	int  	arrive_time; // Time when the patient arrived in the waiting room
	int 	triage_time; // Time when the patient was called to triage
	int 	waiting_attendance_time; // Time when the patient was called to wait for attendence
	int 	attendance_start_time; // Time when the patient started being attended
	int		already_attended_time; // Time when the patient was already attended

	struct s_patiente *next;

} t_patient;


typedef struct s_lists
{
	
	// After Register, currently in Waiting room
	t_patient	*arrive;
	
	// After Waiting room, currently in Triage
	t_patient	*triage;
	
	// Waiting room lists to be attended
	t_patient	*blue;
	t_patient	*green;
	t_patient	*yellow;
	t_patient	*orange;
	t_patient	*red;

	// After Waiting for attendance, currently In attendance
	t_patient	*attendance;

	// After attendance, already attended
	t_patient	*attended;

	// Helper array to store color names
	char		**color_names;
	
} t_lists;

/* List Functions */
void		insert(t_patient **head, t_patient *new_patient);
t_patient	*pop_top(t_patient **head);
void		print_list(t_lists *lists, t_patient *head);
t_patient	***get_waiting_for_attendance_lists(t_lists *lists);

/* Operations Functions */
void	register_new_patient(t_lists *lists, int current_time);
void	call_patient_to_triage(t_lists *lists, int current_time);
void	doctor_attendance_on_next_patient(t_lists *lists, int current_time);
void	visualize_patients_being_treated_by_queue(t_lists *lists);
void	visualize_patients_already_attended_by_queue(t_lists *lists);
void 	visualize_patients_waiting_triage(t_lists *lists);
void	avg_time_register_and_beginning_triage_per_queue(t_lists *list);
void	avg_time_beginning_of_triage_and_beginning_of_attendance_per_queue(t_lists *lists);
void	avg_time_register_end_attendnance_per_queue(t_lists *lists);
void 	print_every_list(t_lists *lists);

/* Free Functions */
void	free_lists(t_lists *lists, char *msg, int exit_status);

/* Update Pantients Functions */
void	update_patients(t_lists *lists, int current_time);

/* Input handle Functions */
int		read_int(char *prompt, char *err, int limit_down, int limit_up, t_lists *lists);

#endif
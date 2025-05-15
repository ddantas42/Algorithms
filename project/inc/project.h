#ifndef PROJECT_H
#define PROJECT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <time.h>
# include <unistd.h>
# include <sys/types.h>

/* Non-modifiable Macros */
# define AZUL 0
# define VERDE 1
# define AMARELO 2
# define LARANJA 3
# define VERMELHO 4

# define MAIN_MENU "\
1. Register new patient\n\
2. Call to Triage\n\
3. Doctor attendance on next patient\n\
4. Visualize patients being treated by queue\n\
5. Visualize patients already attended by queue\n\
6. Check average wait time per queue between register and beginning of triage\
7. Check average wait time per queue between beginning of triage and beginning of attendance\n\
8. Check average wait time per queue between register and ending of attendance\n\
9. Exit\n\
Option: "

typedef struct s_patiente
{
	int 			id;
	char 			name[101];
	int 			age;
	int 			color;
	struct tm 		*arrive_time;
	struct tm 		*triage_time;
	struct tm 		*attendance_start_time;

	struct s_patiente *next;
} t_patiente;

typedef


void register_new_patient(t_patiente **head);

#endif
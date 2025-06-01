#ifndef MACROS_H
# define MACROS_H


/* Non-modifiable Macros */
# define BLUE 0
# define GREEN 1
# define YELLOW 2
# define ORANGE 3
# define RED 4
# define NO_COLOR 5

# define MAIN_MENU "\n\
Current time: [%d:%.2d] (%d)\n\
0. Pass time\n\
1. Register new patient\n\
2. Call to Triage\n\
3. Doctor attendance on next patient\n\
4. Visualize patients being treated by queue\n\
5. Visualize patients already attended by queue\n\
6. Visualize patients in waiting room for triage\n\
7. Check average wait time per queue between register and beginning of triage\n\
8. Check average wait time per queue between beginning of triage and beginning of attendance\n\
9. Check average wait time per queue between register and ending of attendance\n\
10. View every list of patients\n\
11. Exit\n\
"
/* Modifiable Macros */

# define TRIAGE_TIME 10 // Time taken in triage in minutes
# define ATTENDANCE_TIME 30 // Time taken in attendance in minutes

# define EXIT_ON_EOF 1 // If set to 1, the program will exit if EOF is reached (Ctrl+D on Linux, Ctrl+Z on Windows)

/* Prompts and Errors */
# define MENU_PROMPT "Option: "
# define MENU_ERR "Invalid option. Please try again.\n"

# define PATIENTE_AGE_PROMPT "Enter patient's age: "
# define PATIENT_AGE_ERR "Invalid age. Please enter a valid age between 0 and 150.\n"

# define TIME_PROMPT "\nEnter time in minutes: "
# define TIME_ERR "Invalid time. Please enter a valid time in minutes (0 - 1440).\n"

#endif
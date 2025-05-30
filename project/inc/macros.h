#ifndef MACROS_H
# define MACROS_H


/* Non-modifiable Macros */
# define BLUE 0
# define GREEN 1
# define YELLOW 2
# define ORANGE 3
# define RED 4

# define MAIN_MENU "\n\
Current time: [%d:%.2d]\n\
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
10. Exit\n\
"

/* Main Menu */
# define MENU_PROMPT "Option: "
# define MENU_ERR "Invalid option. Please try again.\n"

/* Register Patient */
# define PATIENTE_AGE "Enter patient's age: "
# define PATIENTE_COLOR "Enter patient's color (red = 4 | orange = 3 | yellow = 2 | green = 1 | blue = 0)\nColor: "

#endif
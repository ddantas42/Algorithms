#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>

int my_scanf() {
    char buffer[100];
    char *endptr;
    long val;

    // Read a line from stdin
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        // EOF or error reading input
        return -1;  // use -1 or another code to indicate EOF/error
    }

    // Convert string to long int with error checking
    val = strtol(buffer, &endptr, 10);

    // Check if no digits were found
    if (endptr == buffer) {
        // No conversion performed
        fprintf(stderr, "Error: Invalid integer input.\n");
        return -2; // indicate invalid input
    }

    // Check for leftover non-whitespace characters after the number
    while (*endptr != '\0') {
        if (!isspace((unsigned char)*endptr)) {
            fprintf(stderr, "Error: Extra characters after number.\n");
            return -2; // invalid input
        }
        endptr++;
    }

    // Check for overflow/underflow if needed (optional)
    if (val > INT_MAX || val < INT_MIN) {
        fprintf(stderr, "Error: Integer out of range.\n");
        return -2;
    }

    return (int)val;
}


int main() {
    int x;

	while (1) {
		printf("Enter an integer: ");
		x = my_scanf();
		
		if (x == -1) {
        printf("EOF or input error detected.\n");
    } else if (x == -2) {
		printf("Invalid input detected.\n");
    } else {
		printf("You typed: %d\n", x);
    }
}
    return 0;
}

SRCPATH = src/
SRC_FILES = main.c algos.c array_aux.c
SRC = $(addprefix $(SRCPATH), $(SRC_FILES))

OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

EXECUTABLE = algos

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJ) $(EXECUTABLE)

re: clean all
	
.PHONY: all clean re
SRC_FILES = main.c mala.c
SRC = $(SRC_FILES)

OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

EXECUTABLE = mala

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJ) $(EXECUTABLE)

re: clean all
	
.PHONY: all clean re
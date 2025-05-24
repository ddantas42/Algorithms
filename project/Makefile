MAINPATH = src/
MAIN_FILES = main.c free.c list.c update.c

OPERATION_FILES = 1.c 2.c 3.c 4.c 5.c 6.c 7.c 8.c 9.c 10.c 
OPERATIONPATH = src/operations/

SRC = $(addprefix $(MAINPATH), $(MAIN_FILES)) $(addprefix $(OPERATIONPATH), $(OPERATION_FILES))

OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -pedantic 

EXECUTABLE = queue_system

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJ) $(EXECUTABLE)

re: clean all
	
.PHONY: all clean re
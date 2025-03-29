SRC = main.c algos.c array_aux.c
OBJ = $(SRC:.c=.o)
CC = gcc

EXECUTABLE = algos

all: $(EXECUTABLE)
$(EXECUTABLE): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -c $< -o $@
	
clean:
	rm -f $(OBJ) $(EXECUTABLE)

re: clean all
	
.PHONY: all clean re
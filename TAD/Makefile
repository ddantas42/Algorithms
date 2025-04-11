SRC = ponto.c main.c
OBJ = $(SRC:.c=.o)
EXECUTABLE = ponto
CC = gcc
CFLAGS = -lm


all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c
	$(CC) -c $<

clean:
	rm -f $(OBJ) $(EXECUTABLE)

re: clean all


.PHONY: all clean re
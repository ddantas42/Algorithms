
SRCPATH = src/

SRCFILES = ponto.c circulo.c lista.c
OBJFILES = $(SRCFILES:.c=.o)

EXECUTABLE = tad
CC = gcc
CFLAGS = -lm

MAINFILE = main/main_circulo.c

SRC = $(addprefix $(SRCPATH), $(SRCFILES)) $(MAINFILE)
OBJ = $(SRC:.c=.o)

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c
	$(CC) -c $< $(CFLAGS) -o $@

clean:
	rm -f $(OBJ) $(EXECUTABLE)

re: clean all


.PHONY: all clean re
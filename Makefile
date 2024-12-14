CC = gcc
CFLAGS = -Wall -Wextra -std=c99
OBJ = main.o maze_generator.o maze_solver.o utils.o

all: maze

maze: $(OBJ)
	$(CC) -o maze $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o maze

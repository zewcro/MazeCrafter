#ifndef MAZE_GENERATOR_H
#define MAZE_GENERATOR_H

typedef struct {
    int width;
    int height;
    char **grid;
} Maze;

typedef struct {
    int x, y;
} Position;

Maze generateMaze(int width, int height);
void carvePath(Maze *maze, Position current);
void shuffle(Position *array, int size);
int isInBounds(Maze *maze, Position pos);

#endif

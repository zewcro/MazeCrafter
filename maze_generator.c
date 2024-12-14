#include "maze_generator.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


Maze generateMaze(int width, int height) {
    if (width % 2 == 0) width++;  
    if (height % 2 == 0) height++;

    Maze maze;
    maze.width = width;
    maze.height = height;

    maze.grid = (char **)malloc(height * sizeof(char *));
    if (!maze.grid) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < height; i++) {
        maze.grid[i] = (char *)malloc(width * sizeof(char));
        if (!maze.grid[i]) {
            fprintf(stderr, "Memory allocation failed!\n");
            exit(EXIT_FAILURE);
        }
        for (int j = 0; j < width; j++) {
            maze.grid[i][j] = '#'; 
        }
    }

    Position start = {1, 1};
    carvePath(&maze, start);

    maze.grid[1][1] = 'S';
    maze.grid[height - 2][width - 2] = 'E';

    return maze;
}

void carvePath(Maze *maze, Position current) {
    printf("Carving at: (%d, %d)\n", current.x, current.y);

    Position moves[] = {{0, 2}, {2, 0}, {0, -2}, {-2, 0}};
    shuffle(moves, 4);

    for (int i = 0; i < 4; i++) {
        Position next = {current.x + moves[i].x, current.y + moves[i].y};
        if (isInBounds(maze, next) && maze->grid[next.y][next.x] == '#') {
            maze->grid[current.y + moves[i].y / 2][current.x + moves[i].x / 2] = ' '; 
            maze->grid[next.y][next.x] = ' '; 
            carvePath(maze, next); 
        }
    }
}

void shuffle(Position *array, int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Position temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

int isInBounds(Maze *maze, Position pos) {
    int result = pos.x > 0 && pos.y > 0 && pos.x < maze->width - 1 && pos.y < maze->height - 1;
    if (!result) {
        printf("Out of bounds: (%d, %d)\n", pos.x, pos.y);
    }
    return result;
}
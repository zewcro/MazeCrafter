#include "maze_solver.h"
#include <stdio.h>

bool solveMaze(Maze *maze) {
    Position start = {1, 1};
    return dfsSolve(maze, start);
}

bool dfsSolve(Maze *maze, Position current) {
    printf("Visiting: (%d, %d)\n", current.x, current.y);

    if (current.x < 0 || current.y < 0 || current.x >= maze->width || current.y >= maze->height) {
        printf("Out of bounds: (%d, %d)\n", current.x, current.y);
        return false;
    }

    if (maze->grid[current.y][current.x] == 'E') {
        printf("Exit found at: (%d, %d)\n", current.x, current.y);
        return true;
    }

    if (maze->grid[current.y][current.x] != ' ' && maze->grid[current.y][current.x] != 'S') return false;

    maze->grid[current.y][current.x] = '.'; 

    Position moves[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for (int i = 0; i < 4; i++) {
        Position next = {current.x + moves[i].x, current.y + moves[i].y};
        if (dfsSolve(maze, next)) return true;
    }

    maze->grid[current.y][current.x] = ' '; 
    return false;
}
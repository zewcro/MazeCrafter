#include "maze_solver.h"

bool solveMaze(Maze *maze) {
    Position start = {1, 1};
    return dfsSolve(maze, start);
}

bool dfsSolve(Maze *maze, Position current) {
    if (maze->grid[current.y][current.x] == 'E') return true;

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

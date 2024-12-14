#ifndef MAZE_SOLVER_H
#define MAZE_SOLVER_H

#include "maze_generator.h"
#include <stdbool.h>

bool solveMaze(Maze *maze);
bool dfsSolve(Maze *maze, Position current);

#endif 

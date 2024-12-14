#include <stdio.h>
#include "maze_solver.h"
#include "maze_generator.h"
#include "utils.h"

int main() {
    Maze maze;
    int choice;

    printf("1. Generate Maze\n");
    printf("2. Solve Maze\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        maze = generateMaze(21, 21);
        printMaze(&maze);
    } else if (choice == 2) {
        maze = generateMaze(21, 21); 
        if (solveMaze(&maze)) {
            printf("Solution found:\n");
        } else {
            printf("No solution exists!\n");
        }
        printMaze(&maze);
    }

    freeMaze(&maze);
    return 0;
}

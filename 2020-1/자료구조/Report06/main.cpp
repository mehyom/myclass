#include "Location2D.h"
#include "maze.h"

void main() {
	Maze maze;
	maze.load((char*)"maze1.txt");
	maze.print();
	maze.searchExit();
	maze.print();

	maze.reset();

	maze.load((char*)"maze2.txt");
	maze.print();
	maze.searchExit();
	maze.print();
}
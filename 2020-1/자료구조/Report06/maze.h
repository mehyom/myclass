#pragma once
#include "Location2D.h"
using namespace std;

class Maze
{
	int width;
	int height;
	Location2D exitLoc;
	int** map;

	int** allocMap();
public:
	Maze() { init(0, 0); }
	~Maze() { reset(); }
	void init(int w, int h);
	void reset();
	void load(char* fname);
	void print();
	void searchExit();
	bool isValidLoc(int r, int c);
};

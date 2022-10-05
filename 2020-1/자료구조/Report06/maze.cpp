#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>
#include "maze.h"
using namespace std;


int** Maze::allocMap() {
	if (width <= 0 || height <= 0) return NULL;
	int** newMap = new int* [height];
	for (int i = 0; i < height; i++)
		newMap[i] = new int[width];
	return newMap;
}

void Maze::init(int w, int h) {
	width = w;
	height = h;
	map = allocMap();
}

void Maze::reset() {
	if (map != NULL) {
		for (int i = 0; i < height; i++)
			delete[] map[i];
		delete[] map;
	}
}

void Maze::load(char* fname) {
	int w, h;
	ifstream f(fname);
	if (!f) cout << "파일을 찾을 수 없습니다!" << endl;
	else {
		f >> w >> h;
		init(w, h);
		cout << w << " " << h << endl;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				f >> map[i][j];
	}
}

void Maze::print() {
	cout << "MAP " << endl;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
			cout << setw(2) << map[i][j];
		cout << endl;
	}
}

bool Maze::isValidLoc(int r, int c) {
	if (r < 0 || c < 0 || r >= height || c >= width) return false;

	return map[r][c] == 1 || map[r][c] == 9;
}

void Maze::searchExit() {
	stack<Location2D> locStack;
	Location2D entry(2, 0);
	locStack.push(entry);

	while (locStack.empty() == false) {
		Location2D here = locStack.top();
		locStack.pop();
		printf("(%d,%d) ", here.row, here.col);

		int r = here.row, c = here.col;
		if (map[r][c] == 9) {
			printf(" SUCCESS!\n\n");
			return;
		}
		else {
			map[r][c] = 5;
			if (isValidLoc(r - 1, c)) locStack.push(Location2D(r - 1, c));
			if (isValidLoc(r + 1, c)) locStack.push(Location2D(r + 1, c));
			if (isValidLoc(r, c - 1)) locStack.push(Location2D(r, c - 1));
			if (isValidLoc(r, c + 1)) locStack.push(Location2D(r, c + 1));
		}
	}
}
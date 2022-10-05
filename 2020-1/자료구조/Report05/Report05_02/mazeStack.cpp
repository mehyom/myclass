#define _CRT_SECURE_NO_WARNINGS
#include "Location2D.h"
#include <stdio.h>
#include <stack>
using namespace std;

#define MAZE_SIZE 6
char map[MAZE_SIZE][MAZE_SIZE] = {
	{'1', '1', '1', '1', '1', '1'},
	{'e', '0', '1', '0', '0', '1'},
	{'1', '0', '0', '0', '1', '1'},
	{'1', '0', '1', '0', '1', '1'},
	{'1', '0', '1', '0', '0', 'x'},
	{'1', '1', '1', '1', '1', '1'}
};

bool isValidLoc(int r, int c)
{
	if (r < 0 || c < 0 || r >= MAZE_SIZE || c >= MAZE_SIZE) return false;
	else return map[r][c] == '0' || map[r][c] == 'x';
}

char convertSymbol(char symbol) {
	switch (symbol) {
	case '.': return 'Y';
	case '0': return 'X';
	case '1': return '0';
	case 'x': return 'Y';
	default:  return symbol;
	}
}
const char* convertSymbol2(char symbol) {
	static char buf[100];
	switch (symbol) {
	case '0': sprintf(buf, "%c  ", 'X'); break;
	case '1': sprintf(buf, "%c  ", '0'); break;
	case 'x': sprintf(buf, "%c  ", 'x'); break;
	default:  sprintf(buf, "%-3d", symbol); break;
	}
	return buf;
}
void displayStack(stack<Location2D>& stack)
{
	std::stack<Location2D> tmp;

	while (!stack.empty()) {
		auto top = stack.top();
		printf("%d  %d\n", top.col, top.row);
		stack.pop();
		tmp.push(top);
	}
	while (!tmp.empty()) {
		auto top = tmp.top();
		tmp.pop();
		stack.push(top);
	}
}

void main() {
	stack<Location2D> locStack;
	Location2D entry(1, 0);
	locStack.push(entry);
	int repeat = 0;
	int visitSeq = 0;
	int map2[MAZE_SIZE][MAZE_SIZE];
	
	for (int i = 0; i < MAZE_SIZE; i++)
		for (int j = 0; j < MAZE_SIZE; j++)
			map2[i][j] = map[i][j];

	while (locStack.empty() == false) {
		printf("--------------------\n");

		repeat++;
		printf("[%d]\n", repeat);

		Location2D here = locStack.top();
		locStack.pop();

		int r = here.row, c = here.col;

		printf("POP (%d , %d)\n*****[stack]\n", r, c);
		displayStack(locStack);
		printf("*****(%d elements)\n", locStack.size());
		printf("\nVISIT (%d , %d)\n\n", here.row, here.col);
		
		if (map[r][c] == 'x') {
			printf(" ¹Ì·Î Å½»ö ¼º°ø!!\n\n");
#if 0
			for (int i = 0; i < MAZE_SIZE; i++) {
				for (int j = 0; j < MAZE_SIZE; j++) {
					printf("%c ", convertSymbol(map[i][j]));
				}
				printf("\n");
			}
#else
			for (int i = 0; i < MAZE_SIZE; i++) {
				for (int j = 0; j < MAZE_SIZE; j++) {
					printf("%s", convertSymbol2(map2[i][j]));
				}
				printf("\n");
			}
#endif
			return;
		}
		else {
			map[r][c] = '.';
			map2[r][c] = ++visitSeq;
			if (isValidLoc(r, c - 1)) locStack.push(Location2D(r, c - 1)); //ÁÂ
			if (isValidLoc(r, c + 1)) locStack.push(Location2D(r, c + 1)); //¿ì
			if (isValidLoc(r - 1, c)) locStack.push(Location2D(r - 1, c)); //»ó
			if (isValidLoc(r + 1, c)) locStack.push(Location2D(r + 1, c)); //ÇÏ
		}

		for (int i = 0; i < MAZE_SIZE; i++) {
			for (int j = 0; j < MAZE_SIZE; j++)
				printf("%c ", map[i][j]);
			printf("\n");
		}

		printf("PUSH\n*****[stack]\n");
		displayStack(locStack);
		printf("*****(%d elements)\n", locStack.size());
		printf("--------------------\n");
	}
	printf("¹Ì·Î Å½»ö ½ÇÆÐ\n\n");
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <deque>
#include "Location2D.h"
using namespace std;

#define MAZE_ROW_SIZE 6
#define MAZE_COL_SIZE 7
char map[MAZE_ROW_SIZE][MAZE_COL_SIZE] = {
	{'1', '1', '1', '1', '1', '1', '1'},
	{'e', '0', '1', '0', '0', '1', '1'},
	{'1', '0', '0', '0', '1', '1', '1'},
	{'1', '0', '1', '0', '1', '0', '1'},
	{'1', '0', '1', '0', '0', '0', 'x'},
	{'1', '1', '1', '1', '1', '1', '1'}
};

bool isValidLoc(int r, int c)
{
	if (r < 0 || c < 0 || r >= MAZE_ROW_SIZE || c >= MAZE_COL_SIZE) return false;
	else return map[r][c] == '0' || map[r][c] == 'x';
}

void Qdisplay(deque<Location2D>& q)
{
	printf("[q]  ");
	for (deque<Location2D>::iterator iter = q.begin();
		iter != q.end();
		++iter) {
		const Location2D& loc = *iter;
		printf(" (%d, %d) ", loc.col, loc.row);
	}
	printf("\n");
}

void ENQUEUE(deque<Location2D>& Q, const Location2D& E) {
	Q.push_back(E); 
	printf("*****enqueue (%d,%d)\n", E.row, E.col); 
}
Location2D&  DEQUEUE(deque<Location2D>& Q) {
	Location2D here = Q.front(); 
	Q.pop_front(); 
	printf("*****dequeue (%d , %d)\n", here.row, here.col);
	printf("VISIT (%d,%d)\n\n", here.row, here.col);
	return here;
}
void main() {
	deque<Location2D> locDeque; 
	Location2D entry(1, 0); 
	int visitSeq = 'a';
	map[entry.row][entry.col] = visitSeq++;
	ENQUEUE(locDeque, entry);
	while (locDeque.empty() == false) {    
		const Location2D& here = DEQUEUE(locDeque);
		int r = here.row, c = here.col;
		if (map[r][c] == 'x') { 
			printf(" 미로 탐색 성공!!\n\n"); 

			printf("\nMAP DISPLAY\n\n");
			for (int i = 0; i < MAZE_ROW_SIZE; i++) {
				for (int j = 0; j < MAZE_COL_SIZE; j++)
					printf("%c ", map[i][j]);
				printf("\n");
			}
			return; 
		} else {      
			map[r][c] = map[r][c] >='a' ? map[r][c] : visitSeq++;
			if (isValidLoc(r - 1, c - 1)) ENQUEUE(locDeque, Location2D(r - 1, c - 1));
			if (isValidLoc(r - 1, c - 0)) ENQUEUE(locDeque, Location2D(r - 1, c - 0)); 
			if (isValidLoc(r - 1, c + 1)) ENQUEUE(locDeque, Location2D(r - 1, c + 1));
			if (isValidLoc(r - 0, c - 1)) ENQUEUE(locDeque, Location2D(r - 0, c - 1));
			if (isValidLoc(r - 0, c + 1)) ENQUEUE(locDeque, Location2D(r - 0, c + 1));
			if (isValidLoc(r + 1, c - 1)) ENQUEUE(locDeque, Location2D(r + 1, c - 1));
			if (isValidLoc(r + 1, c - 0)) ENQUEUE(locDeque, Location2D(r + 1, c - 0));
			if (isValidLoc(r + 1, c + 1)) ENQUEUE(locDeque, Location2D(r + 1, c + 1));
		}
		Qdisplay(locDeque);
	} 
	printf("미로탐색실패\n");
}

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#define HEIGHT 8
#define WIDTH 10

typedef unsigned char pixcel_t;

int labelComponent(pixcel_t** img, const int row, const int col, int x, int y, int label) {
	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT) return label;

	if (img[y][x] == '.') { // image colorÀÌ¸é 
		img[y][x] = label++; // blob color·Î »öÄ¥ 
		label = labelComponent(img, row, col, x + 1, y, label);
		label = labelComponent(img, row, col, x, y + 1, label);
		label = labelComponent(img, row, col, x - 1, y, label);
		label = labelComponent(img, row, col, x, y - 1, label);
	}
	return label;
}
void blobColoring(pixcel_t** img, const int row, const int col) {
	int label = 0;

	for (int x = col - 1; x >= 0; x--)
		for (int y = row - 1; y >= 0; y--)
			if (img[y][x] == '.')
				label = labelComponent(img, row, col, x, y, label);
}

void printImage(pixcel_t** img, const int row, const int col, FILE* fp) {
	for (int y = 0; y < row; y++) {
		for (int x = 0; x < col; x++) {
			if (img[y][x] == '9' || img[y][x] == '.')
				fprintf(fp, "%c ", img[y][x]);
			else
				fprintf(fp, "%c ", '0' + img[y][x] % 9);
		}
		fprintf(fp, "\n");
	}
	fprintf(fp, "\n");
}

pixcel_t** input(int& row, int& col) {
	FILE* in = fopen("a.txt", "r");
	if (in == NULL) {
		perror("a.txt file open error");
		return NULL;
	}
	char line[100];
	fgets(line, sizeof(line), in);
	sscanf(line, "%d %d\n", &row, &col);

	pixcel_t** block = new pixcel_t * [row];
	for (int i = 0; i < row; i++) {
		char* linePtr = fgets(line, sizeof(line), in);
		//linePtr[strlen(linePtr) - 1] = '\0';
		pixcel_t* rec = new pixcel_t[col];
		for (int j = 0; j < col && *linePtr != '\0'; ++linePtr) {
			if (*linePtr == '.' || *linePtr == '9') {
				rec[j++] = *linePtr;
			}
		}
		block[i] = rec;
	}
	fclose(in);
	return block;
}

void main() {
	int row = 0;
	int col = 0;
	pixcel_t** image = input(row, col);
	if (image == NULL) {
		return;
	}
	FILE* out = fopen("b.txt", "w");
	if (out == NULL) {
		perror("b.txt file open error");
		return;
	}
	printf("<Original image>\n");
	printImage(image, row, col, stdout);
	blobColoring(image, row, col);
	printf("<Labelled image>\n");
	printImage(image, row, col, stdout);
	printImage(image, row, col, out);
	fclose(out);
}
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include "Rectangle.h"

int main()
{
	int numOfRect = 0;
	Rectangle input;

	scanf("%d", &numOfRect);
	Rectangle* array = new Rectangle[numOfRect];

	for (int i = 0; i < numOfRect; i++) {
		array[i].input();
	}
	for (int i = 0; i < numOfRect; i++) {
		array[i].output();
	}
	delete[] array;
}
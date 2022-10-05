#define _CRT_SECURE_NO_WARNINGS 
#include <cstdio>
#include <cstdlib>
#include "Report03.h"

int* inputdata(int size) {
	int* array = new int[size];
	for (int i = 0; i < size; i++) {
		scanf("%d", &array[i]);
	}
	return array;
}
int main()
{
	int num = 0;
	scanf("%d", &num);

	int* array = inputdata(num);

	Report03 stack;
	
	for (int i = 0; i < num; i++) {
		if (array[i] == 0) {
			if (!stack.isEmpty())
				stack.pop();
		}
		else {
			if (!stack.isFull())
				stack.push(array[i]);
		}
	}
	delete[] array;

	// sum
	int sum = 0;
	while (!stack.isEmpty()) {
		sum += stack.pop();
	}
	printf("%d", sum);
}
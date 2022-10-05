#pragma once 
#include <stdio.h>
#include <stdlib.h>
#include "Student.h"

inline void error(const char* str) {
	fprintf(stderr, "%s\n", str);
	exit(1);
}

const char* EMSG_EMPTY = "공백 상태 에러\n";
const char* EMSG_FULL = "포화 상태 에러\n";

#define MAX_QUEUE_SIZE 100

class StudentQueue
{
	int front; 
	int rear;

	Student data[MAX_QUEUE_SIZE];

public:
	StudentQueue() { front = rear = 0; }
	bool isEmpty() { return front == rear; }
	bool isFull() { return (rear + 1) % MAX_QUEUE_SIZE == front; }

	void enqueue(Student& val) {
		if (isFull() == false) {
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = val;
		}
	}

	Student& dequeue() {
		if (isEmpty()) error(EMSG_EMPTY);
		front = (front + 1) % MAX_QUEUE_SIZE;
		return data[front];
	}

	void display(const char* sex) {
		printf("Waiting %ss DISPLAY: ", sex);
		int maxi = getSize();
		for (int i = 0; i < maxi; i++)
			printf("%s  ", data[front + 1 + i % MAX_QUEUE_SIZE].name);
		printf("\n");
	}

	int getSize() {
		if (front > rear) {
			return MAX_QUEUE_SIZE - (front - rear);
		}
		else if (front < rear) {
			return rear - front;
		}
		else {
			return 0;
		}
	}
};

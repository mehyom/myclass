#pragma once 
#include <stdio.h>
#include <stdlib.h>
#include "Customer.h"

inline void error(const char* str) {
	fprintf(stderr, "%s\n", str);
	exit(1);
}

const char* EMSG_EMPTY = "공백 상태 에러\n";
const char* EMSG_FULL = "포화 상태 에러\n";

#define MAX_QUEUE_SIZE 100

class CustomerQueue
{
	int front;
	int rear;

	Customer data[MAX_QUEUE_SIZE];

public:
	CustomerQueue() { front = rear = 0; }
	bool isEmpty() { return front == rear; }
	bool isFull() { return (rear + 1) % MAX_QUEUE_SIZE == front; }

	void enqueue(Customer& val) {
		if (isFull() == false) {
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = val;
		}
	}

	Customer& dequeue() {
		if (isEmpty()) error(EMSG_EMPTY);
		else {
			front = (front + 1) % MAX_QUEUE_SIZE;
			return data[front];
		}
	}

	void display(int queNo) {
		printf("Q%d DISPLAY: ", queNo);
		int maxi = getSize(); 
		for (int i = 0; i < maxi; i++)
			printf("%4d", data[front + 1+ i % MAX_QUEUE_SIZE].id);
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
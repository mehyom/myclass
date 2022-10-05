#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "BinaryNode.h"

inline void error(const char* str) {
	fprintf(stderr, "%s\n", str);
	exit(1);
}

const char* EMSG_EMPTY = "공백 상태 에러\n";
const char* EMSG_FULL = "포화 상태 에러\n";

#define MAX_QUEUE_SIZE 100

class CircularQueue {

protected: 
	int front; 
	int rear; 
	BinaryNode* data[MAX_QUEUE_SIZE];

public: 
	CircularQueue(){ front = rear = 0; } 
	bool isEmpty() { return front == rear; } 
	bool isFull() { return (rear + 1) % MAX_QUEUE_SIZE == front; }

	void enqueue(BinaryNode* val) {
		if (isFull() == false) {
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = val;
		}
	}

	BinaryNode* dequeue() {
		if (isEmpty()) error(EMSG_EMPTY);
		else {
			front = (front + 1) % MAX_QUEUE_SIZE;
			return data[front];
		}
	}
};
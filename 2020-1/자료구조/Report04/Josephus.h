#pragma once
#define MAX_QUEUE_SIZE 100

inline void error(const char* message) {
	printf("%s\n", message);
	exit(1);
}

const int MAX_STACK_SIZE = 20;
const char* EMSG_QUEUE_EMPTY = "큐 공백 에러\n";
const char* EMSG_QUEUE_FULL = "큐 포화 에러\n";

class Josephus
{
protected:
	int front;
	int rear;
	int data[MAX_QUEUE_SIZE];

public:
	Josephus() { front = rear = 0; }
	bool isEmpty() { return front == rear; }
	bool isFull() { return (rear + 1) % MAX_QUEUE_SIZE == front; }

	void enqueue(int val) {
		if (isFull())
			error(EMSG_QUEUE_FULL);
		else {
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = val;
		}
	}

	int dequeue() {
		if (isEmpty())
			error(EMSG_QUEUE_EMPTY);
		else {
			front = (front + 1) % MAX_QUEUE_SIZE;
			return data[front];
		}
	}

	int peek() {
		if (isEmpty())
			error(EMSG_QUEUE_EMPTY);
		else
			return data[(front + 1) % MAX_QUEUE_SIZE];
	}

	void display() {
		printf("큐 내용: ");
		int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
		for (int i = front + 1; i <= maxi; i++)
			printf("[%2d]", data[i % MAX_QUEUE_SIZE]);
		printf("\n");
	}
};


#pragma once

inline void error(const char* message) {
	printf("%s\n", message);
	exit(1);
}

const int MAX_STACK_SIZE = 20;
const char* EMSG_STACK_EMPTY = "스택 공백 에러";
const char* EMSG_STACK_FULL = "스택 포화 에러";

class Report03
{
private:
	int top;
	int data[MAX_STACK_SIZE];

public:
	Report03() { top = -1; }
	~Report03(){}
	bool isEmpty() { return top == -1; }
	bool isFull() { return top == MAX_STACK_SIZE - 1; }

	void push(){
		int e = 0;
		scanf("%d", &e);
		push(e);
	}

	void push(int e) {
		if (isFull()) error(EMSG_STACK_FULL);
		data[++top] = e;
	}

	int pop() {
		if (isEmpty()) error(EMSG_STACK_EMPTY);
		return data[top--];
	}

	int peek() {
		if (isEmpty()) error(EMSG_STACK_EMPTY);
		return data[top];
	}

	void display() {
		printf("[스택 항목의 수 = %2d] ==> ", top + 1);
		for (int i = 0; i < top; i++)
			printf("<%2d>", data[i]);
		printf("\n");
	}
};


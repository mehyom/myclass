#pragma once
#include "node.h"

class StudentQueue {
	Node* front;
	Node* rear;
public:
	StudentQueue() : front(NULL), rear(NULL) { }
	~StudentQueue() { while (!isEmpty()) delete dequeueFront(); }
	bool isEmpty() { return front == NULL; }
	
	void enqueueRear(Node* n) {
		if (isEmpty()) front = rear = n;
		else {
			rear->setLink(n);
			rear = n;
		}
	}

	Node* dequeueFront() {
		if (isEmpty()) return NULL;
		Node* temp = front;
		front = front->getLink();
		if (front == NULL) rear = NULL;
		return temp;
	}

	void enqueueFront(Node* n) {
		if (isEmpty()) front = rear = n;
		else {
			n->setLink(front->getLink());
			front = n;
		}
	}

	Node* dequeueRear() {
		if (isEmpty()) return NULL;
		Node* temp = rear;
		rear = findBeforeRear();
		if (rear != NULL)
			rear->setLink(NULL);
		else
			front = NULL;
		return temp;
	}
	Node* findBeforeRear() {
		Node* temp = front;
		for (; temp!= NULL && temp->getLink() != rear; temp = temp->getLink())
			;
		return temp;
	}
	Node* peek() { return front; }

	void display() {
		printf("[전체 학생 정보] :\n");
		for (Node* p = front; p != NULL; p = p->getLink())
			p->display();
		printf("\n");
	}
};
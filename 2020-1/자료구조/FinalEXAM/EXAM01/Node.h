#pragma once
#include <stdio.h>

class Node {
	int val;
public:
	Node* prev;
	Node* next;

	Node(int val = 0) : val(val), prev(NULL), next(NULL) {}
	Node* getPrev() { return prev; }
	Node* getNext() { return next; }
	int getData() { return val; }
	void setPrev(Node* p) { prev = p; }
	void setNext(Node* n) { next = n; }
	void display() { printf("%d ", val); }
	void displayCurrent() { printf("#%d# ", val); }
	bool hasData(int _val) { return this->val == _val; }
	void insertNext(Node* n) {
		if (n != NULL) {
			n->prev = this;
			n->next = next;
			if (next != NULL) next->prev = n;
			next = n;
		}
	}
	void insertPrev(Node* n) {
		if (n != NULL) {
			n->next = this;
			n->prev = this->prev;
			if (this->prev != NULL) this->prev->next = n;
			prev = n;
		}
	}
	Node* remove() {
		if (prev != NULL) prev->next = next;
		if (next != NULL) next->prev = prev;
		return this;
	}

	void exchange(Node* b) {
		Node* a = this;
		if (a->next != NULL && a->next != b)
			a->next->prev = b;
		if (a->prev != NULL && a->prev != b)
			a->prev->next = b;
		if (b->next != NULL && b->next != a)
			b->next->prev = a;
		if (b->prev != NULL && b->prev != a)
			b->prev->next = a;
		Node* tmp = b->next;
		b->next = a->next;
		a->next = tmp;
		tmp = b->prev;
		b->prev = a->prev;
		a->prev = b->prev;
	}
};

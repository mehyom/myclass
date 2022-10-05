#pragma once
#include "Node.h"

class DblLinkedList {
	Node org;
public:
	DblLinkedList() : org(0) { }
	~DblLinkedList() { clear(); }

	void clear() { while (!isEmpty()) delete remove(0); }
	Node* getHead() { return org.getNext(); }
	Node* getTail() {
		Node* tail = getHead();
		for (Node* p = getHead(); p != NULL; p = p->getNext()) {
			tail = p;
		}
		return tail->prev;
	}
	bool isEmpty() { return getHead() == NULL; }

	Node* getEntry(int pos) {
		Node* n = &org;
		for (int i = -1; i < pos; i++, n = n->getNext())
			if (n == NULL) break;
		return n;
	}

	void insert(int pos, Node* n) {
		Node* prev = getEntry(pos - 1);
		if (prev != NULL)
			prev->insertNext(n);
	}

	void insertPrev(int pos, Node* n) {
		Node* prev = getEntry(pos - 1);
		Node* here = NULL;
		if (prev != NULL) {
			here = getEntry(pos - 2);
			if (here != NULL)
				here->insertNext(n);
			else here = n;
		}
		else {
			prev = n;
		}
	}

	Node* remove(int pos) {
		Node* n = getEntry(pos);
		return n->remove();
	}

	int find(Node* n) {
		int pos = 0;
		int val = n->getData();
		for (Node* p = getHead(); p != NULL; p = p->getNext()) {
			pos++;
			if (p->hasData(val))
				return pos;
		}
		return NULL;
	}

	Node* find(int val) {
		for (Node* p = getHead(); p != NULL; p = p->getNext())
			if (p->hasData(val))
				return p;
		return NULL;
	}


	void replace(int pos, Node* n) {
		Node* prev = getEntry(pos - 1);
		if (prev != NULL) {
			delete prev->getNext()->remove();
			prev->insertNext(n);
		}
	}


	int size() {
		int count = 0; for (Node* p = getHead(); p != NULL; p = p->getNext())
			count++;
		return count;
	}

	void display(Node* n) {
		for (Node* p = getHead(); p != NULL; p = p->getNext())
			if (p == n) {
				p->displayCurrent();
			}
			else {
				p->display();
			}
		printf("\n");
	}

	void display() {
		for (Node* p = getHead(); p != NULL; p = p->getNext())
			p->display();
		printf("\n");
	}

};

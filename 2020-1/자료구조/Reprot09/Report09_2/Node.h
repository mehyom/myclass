#pragma once
#include <stdio.h>

class Node {
	const char* name;
public:
	Node* prev;
	Node* next;

	Node(const char* val = 0) : name(val), prev(NULL), next(NULL) {}
	Node* getPrev() { return prev; }
	Node* getNext() { return next; }
	const char* getData() { return name; }
	void setPrev(Node* p) { prev = p; }
	void setNext(Node* n) { next = n; }
	void display() { printf(" <%s>", name); }
	void displayCurrent() { printf(" <#%s#>", name); }
	bool hasData(const char* val) { return name == val; }
	void insertNext(Node* n) {
		if (n != NULL) {
			n->prev = this;
			n->next = next;
			if (next != NULL) next->prev = n;
			next = n;
		}
	}
	Node* remove() { 
		if (prev != NULL) prev->next = next; 
		if (next != NULL) next->prev = prev; 
		return this; 
	}
};
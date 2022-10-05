#pragma once
#include <stdio.h>

class Node {
	Node* link;
	int data;
public:
	Node(int val = 0) : data(val), link(NULL) { } 
	Node* getLink() { return link; } 
	int getData() { return data; }
	void setLink(Node* next) { link = next; } 
	void display() { printf(" <%2d>", data); } 
	bool hasData(int val) { return data == val; } 
	void insertNext(Node* n) { 
		if (n != NULL) { 
			n->link = link;   
			link = n; 
		} 
	} 
	Node* removeNext() {
		Node* removed = link;
		if (removed != NULL) link = removed->link; 
		return removed; 
	} 
};

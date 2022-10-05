#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h> 
#include <stdio.h> 
#include "DbLinkedList.h"

void operationA(DblLinkedList& dlist, int data1, int data2) {

	Node* node1 = dlist.find(data1);
	if (!node1) {
		printf("not found %d node\n", data1);
		return;
	}
	Node* node2 = dlist.find(data2);
	if (!node2) {
		printf("not found %d node\n", data2);
		return;
	}

	// remove node1
	// insert after node2
	Node* node1Rm = node1->remove();
	node2->insertNext(node1Rm);
}
void operationB(DblLinkedList& dlist, int data1, int data2) {
	Node* node1 = dlist.find(data1);
	if (!node1) {
		printf("not found %d node\n", data1);
		return;
	}
	Node* node2 = dlist.find(data2);
	if (!node2) {
		printf("not found %d node\n", data2);
		return;
	}
	// remove node1
	// insert before node2
	node2->insertPrev(node1->remove());
}
void operationC(DblLinkedList& dlist, int data1, int data2) {
	Node* node1 = dlist.find(data1);
	if (!node1) {
		printf("not found %d node\n", data1);
		return;
	}
	Node* node2 = dlist.find(data2);
	if (!node2) {
		printf("not found %d node\n", data2);
		return;
	}

	// remove node1
	// insert after node2
	node2->exchange(node1);
}

int main() {
	DblLinkedList dlist; // 货肺款 府胶飘 按眉 积己

	int nodeCount = 0;
	int opCount = 0;
	char op;
	int data1, data2;
	scanf("%d %d\n", &nodeCount, &opCount);

	// make node List
	for (int i = 0; i < nodeCount; i++) {
		dlist.insert(dlist.size(), new Node(i + 1));
	}

	for (int i = 0; i < opCount; i++) {
		char line[80];
		fgets(line, sizeof(line), stdin);
		sscanf(line, "%c %d %d", &op, &data1, &data2);

		if (data1 == data2) {
			printf("not allow same node %d %d\n", data1, data2);
		}
		switch (op) {
		case 'A':
			operationA(dlist, data1, data2);
			break;
		case 'B':
			operationB(dlist, data1, data2);
			break;
		case 'C':
			operationC(dlist, data1, data2);
			break;
		default:
			break;
		}
		dlist.display();
	}
}
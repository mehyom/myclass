#pragma once
#include "Node.h"
#include <deque>

class LinkedList {
	Node org;  // ��� ��� 
public:
	LinkedList() : org(0) { } // ������ 
	~LinkedList() { clear(); } // �Ҹ���

	Node* getHead() { return org.getLink(); }
	bool isEmpty() { return getHead() == NULL; } //Head ��尡 null�̸�

	void clear() {
		while (!isEmpty())
			delete remove(0);
	}

	// pos��° �׸��� ��ȯ�� 
	Node* getEntry(int pos) { 
		Node* n = &org; 
		for(int i=-1 ; i<pos ; i++, n=n->getLink()) //0th ���� 
			if( n == NULL ) break; // nth ��带 ã�� ���� ����Ʈ�� ������ 
		return n; 
	}

	// ����Ʈ�� � ��ġ�� �׸� ���� 
	void insert(int pos, Node *n) { 
		Node* prev = getEntry(pos-1); 
		if( prev != NULL ) 
			prev->insertNext( n ); 
	}

	// ����Ʈ�� � ��ġ�� �׸� ���� 
	Node* remove(int pos) { 
		Node* prev = getEntry(pos-1); //removeNext() �̹Ƿ� before �ʿ� 
		return prev->removeNext();    //class Node�� �ִ� removeNext() ȣ�� 
	}

	// ����Ʈ�� � ��ġ�� �׸� ��ü 
	void replace(int pos, Node* n) { 
		Node* prev = getEntry(pos - 1); 
		if (prev != NULL) { 
			prev->removeNext(); 
			prev->insertNext(n); 
		} 
	}

	// ȭ�鿡 ���� ���� ��� 
	void display() { 
		printf( "[��ü �׸� �� = %2d] : ", size()); 
		for( Node *p = getHead() ; p != NULL ; p=p->getLink() ) 
			p->display(); printf("\n"); 
	}

	//���� ����Ʈ�� ��� ���� ��ȯ 
	int size() {
		int count = 0;
		for (Node* p = getHead(); p != NULL; p = p->getLink())
			count++; 
		return count;
	}

	//Ư���� ���� ���� ����� ������ ���
	int count(int num) {
		int count = 0;
		for (Node* p = getHead(); p != NULL; p = p->getLink())
			if (p->getData() == num)
				count++;
		return count;
	}

	//��� ����� ������ �ٲپ���
	void reverse() {
		Node* current = org.getLink();
		Node* prev = NULL;
		Node* next = NULL;
		Node* tail = NULL;
		/* 
		//solution1
		int pos = 0;
		for (tail = remove(0); tail != NULL; tail = remove(pos)) {
			insert(0, tail);
			++pos;
		}
		*/
		//solution2
		while (current != NULL) {
			next = current->getLink();
			current->setLink(prev);
			prev = current;
			org.setLink(current);
			current = next;
		}	
	}
};
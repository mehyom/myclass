#pragma once
#include "Node.h"

class DblLinkedList {
	Node org; // �����
public:
	DblLinkedList() : org(0) { } // ������ 
	~DblLinkedList() { clear(); } // �Ҹ���

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

	Node* getEntry(int pos) { // pos ��° ��� ��ȯ 
		Node* n = &org; // ����� 
		for (int i = -1; i < pos; i++, n = n->getNext()) // i����, ��������ϸ� 
			if (n == NULL) break; // pos��ġ�� ã�´�. 
		return n;
	}

	void insert(int pos, Node* n) {
		Node* prev = getEntry(pos - 1); //n-1��° ��带 ã�Ƽ� 
		if( prev != NULL ) 
			prev->insertNext( n ); //n-1��° ��� ������ n�߰� 
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
		Node* n = getEntry(pos);  //pos��° ��� n ã�Ƽ� 
		return n->remove();        //��� n ���� 
	}

	int find(Node *n) { 
		int pos = 0;
		const char* val = n->getData();
		for (Node* p = getHead(); p != NULL; p = p->getNext()) {
			pos++;
			if (p->hasData(val))
				return pos;
		}
		return NULL; 
	}

	Node* find(const char* val) { //�����Ͱ� val�� ��带 ã�Ƽ� ��ȯ 
		for( Node *p = getHead() ; p != NULL ; p=p->getNext() ) 
			if( p->hasData( val ) ) 
				return p; 
		return NULL; 
	}


	void replace(int pos, Node* n) { //��ġ pos�� �ִ� ��带 n���� ��ü 
		Node* prev = getEntry(pos-1); 
		if( prev != NULL ) {
			delete prev->getNext()->remove( ); 
			prev->insertNext( n ); 
		} 
	}

		int size() { //����Ʈ�� �� ��� ���� ��ȯ 
			int count = 0; for( Node *p = getHead() ; p != NULL ; p=p->getNext() ) 
				count++; //����Ʈ�� �� ��带 ���󰡸鼭 count���� 
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
				p->display(); //����Ʈ�� �� ��带 ���󰡸鼭 ������ 
			printf("\n");
		}

};
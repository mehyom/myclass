#pragma once
#include "Node.h"

class DblLinkedList {
	Node org; // 헤드노드
public:
	DblLinkedList() : org(0) { } // 생성자 
	~DblLinkedList() { clear(); } // 소멸자

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

	Node* getEntry(int pos) { // pos 번째 노드 반환 
		Node* n = &org; // 헤드노드 
		for (int i = -1; i < pos; i++, n = n->getNext()) // i증가, 노드증가하며 
			if (n == NULL) break; // pos위치를 찾는다. 
		return n;
	}

	void insert(int pos, Node* n) {
		Node* prev = getEntry(pos - 1); //n-1번째 노드를 찾아서 
		if( prev != NULL ) 
			prev->insertNext( n ); //n-1번째 노드 다음에 n추가 
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
		Node* n = getEntry(pos);  //pos번째 노드 n 찾아서 
		return n->remove();        //노드 n 제거 
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

	Node* find(const char* val) { //데이터가 val인 노드를 찾아서 반환 
		for( Node *p = getHead() ; p != NULL ; p=p->getNext() ) 
			if( p->hasData( val ) ) 
				return p; 
		return NULL; 
	}


	void replace(int pos, Node* n) { //위치 pos에 있는 노드를 n으로 대체 
		Node* prev = getEntry(pos-1); 
		if( prev != NULL ) {
			delete prev->getNext()->remove( ); 
			prev->insertNext( n ); 
		} 
	}

		int size() { //리스트의 총 노드 개수 반환 
			int count = 0; for( Node *p = getHead() ; p != NULL ; p=p->getNext() ) 
				count++; //리스트의 각 노드를 따라가면서 count증가 
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
				p->display(); //리스트의 각 노드를 따라가면서 노드출력 
			printf("\n");
		}

};
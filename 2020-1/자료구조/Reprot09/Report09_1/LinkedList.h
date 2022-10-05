#pragma once
#include "Node.h"
#include <deque>

class LinkedList {
	Node org;  // 헤드 노드 
public:
	LinkedList() : org(0) { } // 생성자 
	~LinkedList() { clear(); } // 소멸자

	Node* getHead() { return org.getLink(); }
	bool isEmpty() { return getHead() == NULL; } //Head 노드가 null이면

	void clear() {
		while (!isEmpty())
			delete remove(0);
	}

	// pos번째 항목을 반환함 
	Node* getEntry(int pos) { 
		Node* n = &org; 
		for(int i=-1 ; i<pos ; i++, n=n->getLink()) //0th 부터 
			if( n == NULL ) break; // nth 노드를 찾기 전에 리스트가 끝나면 
		return n; 
	}

	// 리스트의 어떤 위치에 항목 삽입 
	void insert(int pos, Node *n) { 
		Node* prev = getEntry(pos-1); 
		if( prev != NULL ) 
			prev->insertNext( n ); 
	}

	// 리스트의 어떤 위치의 항목 삭제 
	Node* remove(int pos) { 
		Node* prev = getEntry(pos-1); //removeNext() 이므로 before 필요 
		return prev->removeNext();    //class Node에 있는 removeNext() 호출 
	}

	// 리스트의 어떤 위치에 항목 대체 
	void replace(int pos, Node* n) { 
		Node* prev = getEntry(pos - 1); 
		if (prev != NULL) { 
			prev->removeNext(); 
			prev->insertNext(n); 
		} 
	}

	// 화면에 보기 좋게 출력 
	void display() { 
		printf( "[전체 항목 수 = %2d] : ", size()); 
		for( Node *p = getHead() ; p != NULL ; p=p->getLink() ) 
			p->display(); printf("\n"); 
	}

	//연결 리스트의 노드 개수 반환 
	int size() {
		int count = 0;
		for (Node* p = getHead(); p != NULL; p = p->getLink())
			count++; 
		return count;
	}

	//특정한 값을 갖는 노드의 개수를 계산
	int count(int num) {
		int count = 0;
		for (Node* p = getHead(); p != NULL; p = p->getLink())
			if (p->getData() == num)
				count++;
		return count;
	}

	//모든 노드의 순서를 바꾸어줌
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
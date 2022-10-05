#include <stdlib.h> 
#include <stdio.h> 
#include "DbLinkedList.h"

int main() {
	char ch; DblLinkedList dlist; // 새로운 리스트 객체 생성

	Node* head = new Node((char*)"에잇(아이유)"); 
	Node* current = head; dlist.insert(dlist.size(), head); 
	dlist.insert(dlist.size(), new Node((char*)"아로하(조정석)")); 
	dlist.insert(dlist.size(), new Node((char*)"살짝 설렜어(오마이걸)")); 
	dlist.insert(dlist.size(), new Node((char*)"Happy(태연)")); 
	dlist.insert(dlist.size(), new Node((char*)"아무노래(지코)"));
	current = head; 
	dlist.display(current);

	do {
		printf("\n명령어를 입력하세요(<, >, s, e, i, a, q) : ) ");
		ch = getchar();
		if (ch == '<')
			current = current->getPrev();
		else if (ch == '>')
			current = current->getNext();
		else if (ch == 'i') { // current 다음에 추가 
			dlist.insert(dlist.find(current), new Node((char*)"덤더럼(에이핑크)"));
		}
		else if (ch == 'a') { // current 이전에 추가 
			dlist.insertPrev(dlist.find(current), new Node((char*)"덤더럼(에이핑크)"));
		}
		else if (ch == 's') {
			current = dlist.getHead();
		}
		else if (ch == 'e') {
			current = dlist.getTail();
			current = current->getNext();
		}
		dlist.display(current);
		ch = getchar();
	} while (ch != 'q');
}

#include <stdlib.h> 
#include <stdio.h> 
#include "DbLinkedList.h"

int main() {
	char ch; DblLinkedList dlist; // ���ο� ����Ʈ ��ü ����

	Node* head = new Node((char*)"����(������)"); 
	Node* current = head; dlist.insert(dlist.size(), head); 
	dlist.insert(dlist.size(), new Node((char*)"�Ʒ���(������)")); 
	dlist.insert(dlist.size(), new Node((char*)"��¦ ������(�����̰�)")); 
	dlist.insert(dlist.size(), new Node((char*)"Happy(�¿�)")); 
	dlist.insert(dlist.size(), new Node((char*)"�ƹ��뷡(����)"));
	current = head; 
	dlist.display(current);

	do {
		printf("\n��ɾ �Է��ϼ���(<, >, s, e, i, a, q) : ) ");
		ch = getchar();
		if (ch == '<')
			current = current->getPrev();
		else if (ch == '>')
			current = current->getNext();
		else if (ch == 'i') { // current ������ �߰� 
			dlist.insert(dlist.find(current), new Node((char*)"������(������ũ)"));
		}
		else if (ch == 'a') { // current ������ �߰� 
			dlist.insertPrev(dlist.find(current), new Node((char*)"������(������ũ)"));
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

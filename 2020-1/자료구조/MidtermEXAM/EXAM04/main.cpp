#define _CRT_SECURE_NO_WARNINGS
#include "studentQ.h"
#include <iostream>

using namespace std;

void main() {
	StudentQueue que;
	char name[50], dept[50];
	strcpy(name, "홍길동");
	strcpy(dept, "컴퓨터공학과");
	que.enqueueRear(new Node(2015130007, name, dept));
	strcpy(name, "이순신");
	strcpy(dept, "기계공학과");
	que.enqueueRear(new Node(2015130100, name, dept));
	que.display();
	
	cout << "enqueueFront" << endl;
	strcpy(name, "황희");
	strcpy(dept, "법학과");
	que.enqueueFront(new Node(2015130135, name, dept));
	que.display();
	
	cout << "dequeue" << endl;
	delete que.dequeueFront();
	que.display();
	
	cout << "dequeueRear" << endl;
	delete que.dequeueRear();
	que.display();
	
	cout << "dequeueRear" << endl;
	delete que.dequeueRear();
	que.display();

	cout << "enqueueFront" << endl;
	strcpy(name, "박수근");
	strcpy(dept, "영화학과");
	que.enqueueFront(new Node(2015130147, name, dept));
	que.display();

	cout << "dequeueRear" << endl;
	que.dequeueRear();
	que.display();
}
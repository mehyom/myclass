#define _CRT_SECURE_NO_WARNINGS
#include "studentQ.h"
#include <iostream>

using namespace std;

void main() {
	StudentQueue que;
	char name[50], dept[50];
	strcpy(name, "ȫ�浿");
	strcpy(dept, "��ǻ�Ͱ��а�");
	que.enqueueRear(new Node(2015130007, name, dept));
	strcpy(name, "�̼���");
	strcpy(dept, "�����а�");
	que.enqueueRear(new Node(2015130100, name, dept));
	que.display();
	
	cout << "enqueueFront" << endl;
	strcpy(name, "Ȳ��");
	strcpy(dept, "���а�");
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
	strcpy(name, "�ڼ���");
	strcpy(dept, "��ȭ�а�");
	que.enqueueFront(new Node(2015130147, name, dept));
	que.display();

	cout << "dequeueRear" << endl;
	que.dequeueRear();
	que.display();
}
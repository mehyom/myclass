#pragma once
#include <stdio.h>
#include <string.h>
#define MAX_STRING 100

class Student {
	int id;
	char name[MAX_STRING];
	char dept[MAX_STRING];
public:
	Student(int i, char* nam, char* dep) {
		set( i, nam, dep );
	}
	
	void set(int i, char* nam, char* dep) {
		id = i; strcpy( name, nam );
		strcpy( dept, dep );
	}
	
	void display() {
		printf(" 학번:%-15d 성명:%-10s 학과:%-20s\n", id, name, dept);
	}
};

class Node : public Student { 
	Node* link; 
public: Node( int id, char* name, char* dept)
	: Student(id, name, dept) { link = NULL; }
~Node(void) { }
Node* getLink() { return link; }
void setLink( Node *p ) { link = p; }
};
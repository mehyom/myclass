#pragma once
#include <stdio.h>
#include "Reservation.h"

class BinaryNode
{
public:
	Reservation* data;
	BinaryNode* left;
	BinaryNode* right;

	BinaryNode(Reservation* val = NULL, BinaryNode* l = NULL, BinaryNode* r = NULL)
		: data(val), left(l), right(r) { }
	~BinaryNode() { if (data) delete data; }

	void setData(Reservation* val) { data = val; }
	void setLeft(BinaryNode* l) { left = l; }
	void setRight(BinaryNode* r) { right = r; }
	Reservation* getData() { return data; }
	BinaryNode* getLeft() { return left; }
	BinaryNode* getRight() { return right; }
	bool isLeaf() { return left == NULL && right == NULL; }
	void display() {
		printf(" ����� %s�� ����� %s�� %d�п� ���� �����Դϴ�\n", 
			data->getPilot().c_str(), data->getPlane().c_str(),
			data->getLandTime());
	}
};
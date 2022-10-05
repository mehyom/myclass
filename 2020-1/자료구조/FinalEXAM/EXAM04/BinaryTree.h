#pragma once
#include <iostream>
#include "BinaryNode.h"
using namespace std;

enum CompareType {
	CompareTypeLandingTime,
	CompareTypePlaneName,
	CompareTypePilotName,
	CompareTypeLandingAvaliableTime1,
	CompareTypeLandingAvaliableTime2
};
class BinaryTree {
	int k;
protected:
	BinaryNode* root;
	CompareType compareMethod; // 0 : 시간, 1: 비행기명, 2:파일럿, 3, 4: k분 비교
	int dataCompare(Reservation* a, Reservation* b) {
		switch (compareMethod) {
		case CompareTypeLandingTime:
			return a->getLandTime() - b->getLandTime();
		case CompareTypePlaneName:
			return a->getPlane().compare(b->getPlane());
		case CompareTypePilotName:
			return a->getPilot().compare(b->getPilot());
		case CompareTypeLandingAvaliableTime1:
		{int result = a->getLandTime() - b->getLandTime();
		if (result < k + 1 && 0 < result) {
			return 0;
		}
		return result;
		}
		case CompareTypeLandingAvaliableTime2:
		{int result = a->getLandTime() - b->getLandTime();
		if (abs(result) < k + 1 && result < 0) {
			return 0;
		}
		return result;
		}
		default:
			printf("알 수 없는 비교연산자 %d\n", compareMethod);
			return -9999;
		}
	}

	void setCompareMethod(const CompareType method) {
		compareMethod = method;
	}
public:
	void setDetaK(const int k) {
		this->k = k;
	}

	BinaryTree() : compareMethod(CompareTypeLandingTime), root(NULL) { }
	~BinaryTree() { }

	void setRoot(BinaryNode* node) { root = node; }
	BinaryNode* getRoot() { return root; }
	bool isEmpty() { return root == NULL; }
	bool isFull() { return isEmpty() ? true : isFull(root); }

	bool isFull(BinaryNode* node) {
		if (node == NULL) return true;
		if (node->left == NULL && node->right == NULL) return true;
		if (node->left != NULL && node->right != NULL)
			return isFull(node->left) and isFull(node->right);
		else return false;
	}
	void displayTree(BinaryNode* node) {
		if (node != NULL) {
			if (node->getLeft() != NULL) displayTree(node->getLeft());
			node->display();
			if (node->getRight() != NULL) displayTree(node->getRight());
		}
	}
	void displayTree() { printf("\n"); displayTree(root); }
};
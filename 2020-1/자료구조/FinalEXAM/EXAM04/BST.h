#pragma once 
#include "BinaryTree.h"

class BinSrchTree : public BinaryTree
{
public:
	BinSrchTree(void) { }
	~BinSrchTree(void) { }

	BinaryNode* search(Reservation* key, CompareType compareType) {
		setCompareMethod(compareType);
		BinaryNode* node = search(root, key); 
		return node;
	}

	Reservation* inorderSearch(Reservation* key, CompareType compareType) {
		if (getRoot()->getData() == key)
			return key;
		setCompareMethod(compareType);
		return inorderSearch(getRoot(), key);
	}

	void insert(BinaryNode* n) {
		if (n == NULL) return;
		setCompareMethod(CompareTypeLandingTime);
		if (isEmpty()) root = n;
		else insert(root, n);
	}

	void remove(Reservation* key) {
		if (isEmpty()) return;
		setCompareMethod(CompareTypeLandingTime);

		BinaryNode* parent = NULL;  
		BinaryNode* node = root;    
		int result;
		while (node != NULL && (result = dataCompare(key, node->getData())) != 0 ) {
			parent = node;          
			node = (result <0) ? node->getLeft() : node->getRight();
		}                          
		if (node == NULL) {      
			return;
		}
		else remove(parent, node); 
	}
protected:
	BinaryNode* search(BinaryNode* n, Reservation* key) {
		if (n == NULL) return NULL;
		int result = dataCompare(key, n->getData());
		if (result == 0) return n;
		else if (result < 0) return search(n->getLeft(), key);
		else return search(n->getRight(), key);
	}
	void insert(BinaryNode* r, BinaryNode* n) {
		int result = dataCompare(n->getData(), r->getData());
		if (result == 0) return;
		else if (result < 0) {
			if (r->getLeft() == NULL) r->setLeft(n);
			else insert(r->getLeft(), n);
		}
		else {
			if (r->getRight() == NULL) r->setRight(n);
			else insert(r->getRight(), n);
		}
	}

	Reservation* inorderSearch(BinaryNode* node, Reservation* key) {
		Reservation* result = NULL;
		if (node != NULL) {
			if (0 == dataCompare(key, node->getData())) {
				// 찾음.....
				result = node->getData();
			}
			else {
				if (node->getLeft() != NULL)
					result = inorderSearch(node->getLeft(), key);
				if (result == NULL && node->getRight() != NULL)
					result = inorderSearch(node->getRight(), key);
			}
		}
		return result;
	}
	void remove(BinaryNode* parent, BinaryNode* node) {

		// case 1 : 삭제노드가 단말인 경우 
		if (node->isLeaf()) {
			if (parent == NULL) root = NULL;
			else {
				if (parent->getLeft() == node)
					parent->setLeft(NULL);
				else
					parent->setRight(NULL);
			}
		}

		// case 2 : 삭제노드가 1개의 서브트리를 갖는 경우 
		else if (node->getLeft() == NULL || node->getRight() == NULL) {
			BinaryNode* child = (node->getLeft() != NULL)
				? node->getLeft() : node->getRight();
			if (node == root)
				root = child;
			else {
				if (parent->getLeft() == node)
					parent->setLeft(child);
				else
					parent->setRight(child);
			}
		}

		// case 3 : 삭제노드가 2개의 서브트리를 갖는 경우 
		else {
			BinaryNode* succp = node;
			BinaryNode* succRight = node->getRight();
			BinaryNode* succLeft = node->getLeft();

			while (succRight->getLeft() != NULL) {
				succp = succRight;
				succRight = succRight->getLeft();
			}

			while (succLeft->getRight() != NULL) {
				succp = succLeft;
				succLeft = succLeft->getRight();
			}

			if (succp - succLeft > succRight - succp) {
				if (succp->getLeft() == succRight)
					succp->setLeft(succRight->getRight());
				else
					succp->setRight(succRight->getRight());

				node->setData(succRight->getData());
				node = succRight;
			}
			else {
				if (succp->getRight() == succLeft)
					succp->setRight(succLeft->getLeft());
				else
					succp->setLeft(succLeft->getLeft());

				node->setData(succLeft->getData());
				node = succLeft;
			}
		}
		delete node;
	}
};
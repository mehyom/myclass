#pragma once 
#include "BinaryTree.h"

class BinSrchTree : public BinaryTree
{
public:
	BinSrchTree(void) { }
	~BinSrchTree(void) { }

	BinaryNode* search(int key) {
		BinaryNode* node = search(root, key);  //!!! parent class����:root=> protected 
		if (node != NULL)
			printf("Ž�� ���� : Ű���� %d�� ��� = 0x%x\n", node->getData(), node );
		else
			printf("Ž�� ���� : Ű���� %d�� ��� ����\n", key ); 
		return node;
	}

	BinaryNode* search(BinaryNode* n, int key) {
		if (n == NULL) return NULL;
		if (key == n->getData()) return n;
		else if (key < n->getData()) return search(n->getLeft(), key);
		else return search(n->getRight(), key);
	}

	void insert(BinaryNode* n) {
		if (n == NULL) return;
		if (isEmpty()) root = n;
		else insert(root, n);
	}

	void insert(BinaryNode* r, BinaryNode* n) {
		if (n->getData() == r->getData()) return;
		else if (n->getData() < r->getData()) {
			if (r->getLeft() == NULL) r->setLeft(n);
			else insert(r->getLeft(), n);
		}
		else {
			if (r->getRight() == NULL) r->setRight(n);
			else insert(r->getRight(), n);
		}
	}

	void remove(int key) {
		if (isEmpty()) return;

		BinaryNode* parent = NULL;   // ���� �湮�ϴ� ����� �θ� ��� 
		BinaryNode* node = root;     // ���� �湮�ϴ� ��� : root���� ����

		while (node != NULL && node->getData() != key) {
			parent = node;           // parent ������Ʈ : node�� parent�� �ǰ� 
			node = (key < node->getData()) ? node->getLeft() : node->getRight();
		}                            // node ������Ʈ: node�� �ڽĳ��� 
		if (node == NULL) {           // �ܸ����� �����Ͽ��µ� key�� �� ã�� ��� 
			printf(" Error: key is not in the tree!\n");
			return;
		}
		else remove(parent, node); // key�� ã�� ���
	}

	void remove(BinaryNode* parent, BinaryNode* node) {

		// case 1 : ������尡 �ܸ��� ��� 
		if (node->isLeaf()) {
			if (parent == NULL) root = NULL;
			else {
				if (parent->getLeft() == node)
					parent->setLeft(NULL);
				else
					parent->setRight(NULL);
			}
		}

		// case 2 : ������尡 1���� ����Ʈ���� ���� ��� 
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

		// case 3 : ������尡 2���� ����Ʈ���� ���� ��� 
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
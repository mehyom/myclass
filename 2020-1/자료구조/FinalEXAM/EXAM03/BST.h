#pragma once 
#include "BinaryTree.h"

class BinSrchTree : public BinaryTree
{
public:
	BinSrchTree(void) { }
	~BinSrchTree(void) { }

	BinaryNode* search(int key) {
		BinaryNode* node = search(root, key);  //!!! parent class변수:root=> protected 
		if (node != NULL)
			printf("탐색 성공 : 키값이 %d인 노드 = 0x%x\n", node->getData(), node );
		else
			printf("탐색 실패 : 키값이 %d인 노드 없음\n", key ); 
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

		BinaryNode* parent = NULL;   // 현재 방문하는 노드의 부모 노드 
		BinaryNode* node = root;     // 현재 방문하는 노드 : root에서 시작

		while (node != NULL && node->getData() != key) {
			parent = node;           // parent 업데이트 : node가 parent가 되고 
			node = (key < node->getData()) ? node->getLeft() : node->getRight();
		}                            // node 업데이트: node의 자식노드로 
		if (node == NULL) {           // 단말까지 도달하였는데 key를 못 찾은 경우 
			printf(" Error: key is not in the tree!\n");
			return;
		}
		else remove(parent, node); // key를 찾은 경우
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
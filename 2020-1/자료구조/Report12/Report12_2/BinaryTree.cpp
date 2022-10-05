#include <iostream>
#include "CircularQ.h"
#include "BinaryTree.h"

using namespace std;

bool BinaryTree::isEmpty() { return root == NULL; }
bool BinaryTree::isFull() { return isEmpty() ? true : isFull(root); }

bool BinaryTree::isFull(BinaryNode* node) {
	if (node == NULL) return true;
	if (node->left == NULL && node->right == NULL) return true;
	if (node->left != NULL && node->right != NULL)
		return isFull(node->left) and isFull(node->right);
	else return false;
}

int BinaryTree::getCount() { return isEmpty() ? 0 : getCount(root); }
int BinaryTree::getLeafCount() { return isEmpty() ? 0 : getLeafCount(root); }
int BinaryTree::getHeight() { return isEmpty() ? 0 : getHeight(root); }

int BinaryTree::getCount(BinaryNode* node) {
	if (node == NULL) return 0;
	return 1 + getCount(node->getLeft())
		+ getCount(node->getRight());
}

int BinaryTree::getLeafCount(BinaryNode* node) {
	if (node == NULL) return 0;
	if (node->isLeaf()) return 1;
	else return getLeafCount(node->getLeft())
		+ getLeafCount(node->getRight());
}

int BinaryTree::getHeight(BinaryNode* node) {
	if (node == NULL) return 0;
	int hLeft = getHeight(node->getLeft());
	int hRight = getHeight(node->getRight());
	return (hLeft > hRight) ? 1 + hLeft : 1 + hRight;
}

int BinaryTree::calcLevel(int n) {
	return isEmpty() ? 0 : calcLevel(root, n, 1);
}

int BinaryTree::calcLevel(BinaryNode* node, int n, int level) {
	if (node == NULL) return 0;
	if (node->data == n) return level;
	int ll = calcLevel(node->left, n, level + 1);
	if (ll != 0) return ll;
	ll = calcLevel(node->right, n, level + 1);
	return ll;
}

bool BinaryTree::isBalanced() { return isEmpty() ? true : isBalanced(root); }
int BinaryTree::pathLength() { return isEmpty() ? 0 : pathLength(root, 0, 0); }
void BinaryTree::reverse() { if (isEmpty())  printf("EMPTY"); else reverse(root); }

bool BinaryTree::isBalanced(BinaryNode* node) {
	if (node == NULL) return true;
	int lh = getHeight(node->left);
	int rh = getHeight(node->right);
	if (abs(lh - rh) <= 1 && isBalanced(node->left) && isBalanced(node->right))
		return true;
	else return false;
}

int BinaryTree::pathLength(BinaryNode* node, int pl, int tpl) {
	if (node == NULL) return 0;
	tpl += pl + pathLength(node->left, pl + 1, tpl) + pathLength(node->right, pl + 1, tpl);
	return tpl;
}

void BinaryTree::reverse(BinaryNode* node) {
	BinaryNode* temp = node->right;
	node->right = node->left;
	node->left = temp;
	if (node->left != NULL) reverse(node->left);
	if (node->right != NULL) reverse(node->right);
}

void BinaryTree::display() {
	printf(" 노드의 개수 = %d\n", getCount());
	printf(" 단말의 개수 = %d\n", getLeafCount());
	printf(" 트리의 높이 = %d\n", getHeight());
	printf("Is a full tree?");
	if (isFull()) printf(" yes!\n");
	else printf(" no!\n");
	printf("Is a balanced tree?");
	if (isBalanced()) printf(" yes!\n");
	else printf(" no!\n");
	printf("pathLevel = %d\n", pathLength());
}

void BinaryTree::displayTree(BinaryNode* node) {
	while (node != NULL) {
		printf(" %c", node->getData());
		node = node->getLeft();
	}
	printf("\n");
}

void BinaryTree::inorder(BinaryNode* node) {
	if (node != NULL) {
		if (node->getLeft() != NULL) inorder(node->getLeft());
		printf("%c", node->getData());
		if (node->getRight() != NULL) inorder(node->getRight());
	}
}

void BinaryTree::preorder(BinaryNode* node) {
	if (node != NULL) {
		printf("%c", node->getData());
		if (node->getLeft() != NULL) preorder(node->getLeft());
		if (node->getRight() != NULL) preorder(node->getRight());
	}
}

void BinaryTree::postorder(BinaryNode* node) {
	if (node != NULL) {
		if (node->getLeft() != NULL) postorder(node->getLeft());
		if (node->getRight() != NULL) postorder(node->getRight());
		printf("%c", node->getData());
	}
}

void BinaryTree::levelorder() {
	printf("\n");
	if (!isEmpty()) {
		CircularQueue q;
		q.enqueue(root);
		while (!q.isEmpty()) {
			BinaryNode* n = q.dequeue();
			if (n != NULL) {
				printf("%c ", n->getData());
				q.enqueue(n->getLeft());
				q.enqueue(n->getRight());
			}
		}
	}
	printf("\n");
}
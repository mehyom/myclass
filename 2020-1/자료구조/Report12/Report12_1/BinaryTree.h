#pragma once 
#include "BinaryNode.h"

class BinaryTree {
	BinaryNode* root;

public:
	BinaryTree() : root(NULL) { }
	~BinaryTree() { }

	void setRoot(BinaryNode* node) { root = node; }
	BinaryNode* getRoot() { return root; }
	bool isEmpty();
	bool isFull();
	bool isFull(BinaryNode* node);

	int getCount();
	int getLeafCount();
	int getHeight();

	int getCount(BinaryNode* node);
	int getLeafCount(BinaryNode* node);
	int getHeight(BinaryNode* node);

	int calcLevel(int n);
	int calcLevel(BinaryNode* node, int n, int level);

	bool isBalanced();
	int pathLength();
	void reverse();

	bool isBalanced(BinaryNode* node);
	int pathLength(BinaryNode* node, int pl, int tpl);
	void reverse(BinaryNode* node);

	void display();
	void displayTree(BinaryNode* node);

	//Tree Traversal
	void inorder() { printf("\n"); inorder(root); } 
	void preorder() { printf("\n"); preorder(root); } 
	void postorder() { printf("\n"); postorder(root); } 
	void levelorder();

private: 
	// Tree Traversal 
	void inorder(BinaryNode* node); 
	void preorder(BinaryNode* node); 
	void postorder(BinaryNode* node);
};
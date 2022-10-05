#include <iostream> 
#include "BinaryTree.h" 

using namespace std;

void main() {
	BinaryTree treeP;
	BinaryNode* d = new BinaryNode('D', NULL, NULL);
	BinaryNode* e = new BinaryNode('E', NULL, NULL);
	BinaryNode* b = new BinaryNode('B', d, e);
	BinaryNode* f = new BinaryNode('F', NULL, NULL);
	BinaryNode* g = new BinaryNode('G', NULL, NULL);
	BinaryNode* c = new BinaryNode('C', f, g);
	BinaryNode* a = new BinaryNode('A', b, c);
	treeP.setRoot(a);

	BinaryTree treeQ;
	BinaryNode* i_ = new BinaryNode('I', NULL, NULL);
	BinaryNode* d_ = new BinaryNode('D', NULL, i_);
	BinaryNode* b_ = new BinaryNode('B', d_, NULL);
	BinaryNode* f_ = new BinaryNode('F', NULL, NULL);
	BinaryNode* g_ = new BinaryNode('G', NULL, NULL);
	BinaryNode* c_ = new BinaryNode('C', f_, g_);
	BinaryNode* a_ = new BinaryNode('A', b_, c_);
	treeQ.setRoot(a_);

	printf("<TREE DISPLAY>\n");
	printf("***treeP***\n");
	treeP.display();
	printf("---------------------------------------\n");
	printf("<TREE DISPLAY>\n");
	printf("***treeQ***\n");
	treeQ.display();
	printf("---------------------------------------\n");
	printf("<TREE REVERSE>\n");
	printf("***treeP***\n");
	printf("BEFORE :");
	treeP.displayTree(treeP.getRoot());
	treeP.reverse();
	printf("AFTER :");
	treeP.displayTree(treeP.getRoot());
	printf("---------------------------------------\n");
	printf("<TREE REVERSE>\n");
	printf("***treeQ***\n");
	printf("BEFORE :");
	treeQ.displayTree(treeQ.getRoot());
	treeQ.reverse();
	printf("AFTER :");
	treeQ.displayTree(treeQ.getRoot());
	printf("---------------------------------------\n");
}
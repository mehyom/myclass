#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include "BinaryTree.h" 

using namespace std;

typedef BinaryTree* PtrBinaryTree;

BinaryNode* findTreeNode(BinaryNode* rootNode, char root)
{
	if (rootNode == NULL)
		return NULL;
	if (rootNode->data == root) {
		return rootNode;
	}
	else {
		BinaryNode* result = findTreeNode(rootNode->getLeft(), root); 
		if (result == NULL)
			result = findTreeNode(rootNode->getRight(), root);
		return result;
	}
}

void main() {
	int totalLines = 0;
	scanf("%d\n", &totalLines);
	BinaryTree tree;
	for (int i = 0; i < totalLines; i++) {
		char root, left, right;
		char line[100];
		fgets(line, 100, stdin);
		sscanf(line, "%c %c %c", &root, &left, &right);
		BinaryNode* pLeft = left != '.' ? new BinaryNode(left, NULL, NULL) : NULL;
		BinaryNode* pRight = right != '.' ? new BinaryNode(right, NULL, NULL) : NULL;
		if (tree.getRoot() == NULL) {
			tree.setRoot(new BinaryNode(root, pLeft, pRight));
		}
		else {
			BinaryNode* matchTreeNode = findTreeNode(tree.getRoot(), root);
			if (matchTreeNode == NULL) {
				fprintf(stderr, "not found node %c\n", root);
				exit(0);
			}
			matchTreeNode->setLeft(pLeft);
			matchTreeNode->setRight(pRight);
		}
	}
	tree.preorder();
	tree.inorder();
	tree.postorder();

}
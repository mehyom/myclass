#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include "BST.h" 
using namespace std;

void main() {
	BinSrchTree tree;

	// ���� ���� �׽�Ʈ 
	printf("[���Կ���] : 35 18 7 26 12 3 68 22 30 99 \n"); 
	tree.insert(new BinaryNode(35)); 
	tree.insert(new BinaryNode(18)); 
	tree.insert(new BinaryNode(7)); 
	tree.insert(new BinaryNode(26)); 
	tree.insert(new BinaryNode(12)); 
	tree.insert(new BinaryNode(3)); 
	tree.insert(new BinaryNode(68)); 
	tree.insert(new BinaryNode(22)); 
	tree.insert(new BinaryNode(30)); 
	tree.insert(new BinaryNode(99));
	tree.inorder(); tree.preorder(); 
	tree.postorder(); 
	tree.levelorder();
	printf("\n<BST ���� ��� >\n"); 
	printf(" ����� ���� = %d\n", tree.getCount()); 
	printf(" �ܸ��� ���� = %d\n", tree.getLeafCount()); 
	printf(" Ʈ���� ���� = %d\n", tree.getHeight());

	printf("\n <Ž������> \n"); 
	tree.search(26); 
	tree.search(25);

	system("pause");
}
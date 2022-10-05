#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include "BST.h" 
using namespace std;

void main() {
	BinSrchTree tree;

	// 삽입 연산 테스트 
	printf("[삽입연산] : 35 18 7 26 12 3 68 22 30 99 \n"); 
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
	printf("\n<BST 정보 출력 >\n"); 
	printf(" 노드의 개수 = %d\n", tree.getCount()); 
	printf(" 단말의 개수 = %d\n", tree.getLeafCount()); 
	printf(" 트리의 높이 = %d\n", tree.getHeight());

	printf("\n <탐색연산> \n"); 
	tree.search(26); 
	tree.search(25);

	system("pause");
}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include "BST.h" 
using namespace std;

void main() {
	BinSrchTree tree;
	int n;
	char op;
	int data;
	scanf("%d\n", &n);

	for (int i = 0; i < n; i++) {
		char line[80];
		fgets(line, sizeof(line), stdin);
		sscanf(line, "%c %d", &op, &data);

		switch (op) {
		case 'I':
			tree.insert(new BinaryNode(data));
			break;
		case 'D':
			tree.remove(data);
			break;
		default:
			break;
		}
	}
	tree.preorder();
}
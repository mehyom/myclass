#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include "BST.h" 
using namespace std;

void main() {
	BinSrchTree tree;
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		tree.insert(new BinaryNode(a));
	}

	int m;
	scanf("%d", &m);

	for (int j = 0; j < m; j++) {
		int tmp;
		scanf("%d", &tmp);
		tree.search(tmp);
	}
}
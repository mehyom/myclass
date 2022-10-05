#include "LinkedList.h"

void main() {
	LinkedList list;

	list.insert(0, new Node(10));
	list.insert(0, new Node(20));
	list.insert(1, new Node(30));
	list.insert(list.size(), new Node(40));
	list.insert(2, new Node(50));

	list.display();
	printf("\nRESULT OF REVERSE\n");
	list.reverse();
	list.display();

	list.insert(0, new Node(10));
	list.display();

	printf("\ncount 10: ");
	printf("%d\n", list.count(10));
	printf("\ncount 20: ");
	printf("%d\n", list.count(20));
}

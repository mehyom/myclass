#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include "Josephus.h"

class Remover {
	Josephus josep;
	int n;
	int k;

public:
	Remover(int _n, int _k) : josep(), n(_n), k(_k) {
		for (int i = 0; i < n; i++)
			josep.enqueue(i + 1);
	}

	int getNextVal() {
		for (int i = 0; i < k - 1; i++) {
			josep.enqueue(josep.dequeue());
		}
		return josep.dequeue();
	}
};

int main() {
	int n = 0;
	int k = 0;

	scanf("%d", &n);
	scanf("%d", &k);

	Remover obj(n, k);

	printf("\n<");
	for (int i = 0; i < n; i++)
		printf("%d%s", obj.getNextVal(), i==n-1 ? ">" : ", ");
	printf("\n");
}
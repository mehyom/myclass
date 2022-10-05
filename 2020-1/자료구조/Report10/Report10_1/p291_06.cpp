#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

float sumfunc(float n) {
	if (n <= 0) return 0;
	else {
		return ((1 / n) + sumfunc(n - 1));
	}
}

void main() {
	float num;
	scanf("%f", &num);
	printf("my sum is %.2f", sumfunc(num));
}
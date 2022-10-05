#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include "Goods.h"

int main()
{
	int numOfGoods = 0;
	Goods input;

	scanf("%d", &numOfGoods);
	Goods* goods = new Goods[numOfGoods];

	for (int i = 0; i < numOfGoods; i++) {
		goods[i].input();
	}
	for (int i = 0; i < numOfGoods; i++) {
		goods[i].output();
	}
	delete[] goods;
}
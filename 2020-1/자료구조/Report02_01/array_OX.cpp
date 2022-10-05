#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#define MAX 80

int countOX(char* checkList, int len) 
{
	int weightArray[MAX];
	// 1차변환 O->1 else 0
	for (int i = 0; i < len; i++)
		weightArray[i] = checkList[i] == 'O' ? 1 : 0;

	// 2차변환 weighted
	for (int i = 1; i < len; i++)
		if (weightArray[i] == 1)
			if (0 != weightArray[i-1]) 
				weightArray[i] = weightArray[i-1] + 1;

	// 3차 함계
	int sum = 0;
	for (int i = 0; i < len; i++)
		sum += weightArray[i];

	return sum;
}

int main()
{
	int numOfCase = 0;

	scanf("%d", &numOfCase);

	char checkList[MAX];
	for (int i = 0; i < numOfCase; i++) {
		scanf("%s", checkList);
		int sum = countOX(checkList, strlen(checkList));
		printf("%d\n", sum);
	}
}
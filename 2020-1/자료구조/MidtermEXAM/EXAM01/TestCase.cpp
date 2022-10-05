#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include "TestCase.h"

TestCase::TestCase(char* command, int elementsSize, char* inputLine)
{
	this->commands = command;
	q = new std::deque<int>();
	int i = 0;
	for (char* token = strtok(inputLine, ",");
		token != NULL && i < elementsSize;
		token = strtok(NULL, ","), i++) {
		q->push_back(atoi(token));
	}
}
TestCase::~TestCase()
{
	delete q;
	free(commands);
}

TestCase* TestCase::inputData()
{
	static char inputLine[100000 + 1];
	int elementsSize = 0;

	// RDAD
	scanf("%s", inputLine);
	char* command = _strdup(inputLine);

	// size
	scanf("%d", &elementsSize);
	if (elementsSize > 1000000) error();

	// [1,2,3,4]
	scanf("%s", inputLine);
	inputLine[strlen(inputLine) - 1] = '\0';

	TestCase* tc = new TestCase(command, elementsSize, inputLine + 1);
	return tc;
}

std::deque<int>* TestCase::reverse() {
	std::deque<int>::reverse_iterator rit = q->rbegin();
	std::deque<int>* reverseQ = new std::deque<int>();

	for (rit = q->rbegin(); rit != q->rend(); ++rit)
		reverseQ->push_back(*rit);
	delete q;
	q = reverseQ;
	return reverseQ;
}
void TestCase::print() {
	for (std::deque<int>::iterator it = q->begin(); it != q->end(); ++it) {
		if (*it > 100) {
			printf("error");
			break;
		}
		printf("%s%d", it != q->begin() ? "," : "[", *it);
	}
	printf("]\n");
}
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "TestCase.h"

bool execute(TestCase* tc)
{
	char* cmd = tc->getCommands();
	std::deque<int>* q = tc->getData();

	int* result = NULL;
	while (*cmd != '\0') {
		switch (*cmd) {
		case 'R': q = tc->reverse();   break;
		case 'A': q->push_front(0);  break;
		case 'D': if (q->empty()) return false;
			q->pop_front(); break;
		default: return false;
		}
		cmd++;
	}
	return true;
}

int main()
{
	int totalTestCaseCount = 0;
	scanf("%d", &totalTestCaseCount);
	if (totalTestCaseCount > 100) error();

	int sum = 0;
	for (int i = 0; i < totalTestCaseCount; i++) {
		TestCase* tc = TestCase::inputData();
		sum += strlen(tc->getCommands()) + tc->getData()->size();
		if (sum > 700000) error();
		if (execute(tc)) {
			tc->print();
		}
		else {
			printf("error\n");
		}
	}
}
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <deque>
#include <string>

inline void error() {
	printf("error");
	exit(1);
}

class TestCase
{
private:
	char* commands;
	std::deque<int>* q;
	TestCase(char* command, int elementsSize, char* inputLine);
	~TestCase();
public:
	static TestCase* inputData();

	char* getCommands() {
		return commands;
	}

	std::deque<int>* getData() {
		return q;
	}

	std::deque<int>* reverse();
	void print();
};


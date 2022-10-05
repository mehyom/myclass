#define _CRT_SECURE_NO_WARNINGS
#include <stack>
#include <deque>
#include <stdio.h>
#include <string.h>
using namespace std;

const char* openStr = "{[(";
const char* closeStr = "}])";
const int weights[] = { 4,3,2 };

int indexOf(const char* str, char ch) {
    int index = 0;
    while (*str++ != ch) ++index;
    return index;
}
bool isClose(char ch) {
    return strchr(closeStr, ch) != NULL;
}
bool isOpen(char ch) {
    return strchr(openStr, ch) != NULL;
}
bool isMatch(char openToken, char closeToken) {
    return indexOf(openStr, openToken) == indexOf(closeStr, closeToken);
}
int getWeightByOpen(char ch) {
    return weights[indexOf(openStr, ch)];
}
int getWeightByClose(char ch) {
    return weights[indexOf(closeStr, ch)];
}

class Exam02 {
private:
    stack<char> s;
    deque<char> expr;
protected:
    int evalStack() {
        int sum = 0;

        while (!expr.empty()) {
            char token = expr.front();
            expr.pop_front();
            if (isOpen(token)) {
                s.push(token);
                sum += evalStack();
            }
            else if (isClose(token)) {
                if (s.empty()) {
                    printf("invalid : stack empty. token %c\n", token);
                    return -1;
                }
                if (!isMatch(s.top(), token)) {
                    printf("invalid : stack size %d, isMatch(%c, %c) is %d == 1\n",
                        s.size(), s.top(), token, isMatch(s.top(), token));
                    return -1;
                }
                s.pop();
                return sum == 0 ? getWeightByClose(token) : sum * getWeightByClose(token);
            }
            else {
                printf("invalid : unknown token %c\n", token);
                return -1;
            }
        }
        return s.empty() ? sum : -1;
    }

public:
    int evalStack(const char* input) {
        while (!s.empty())  s.pop();
        while (!expr.empty())  expr.pop_back();

        for (const char* pos = input; *pos != '\0'; pos++)
            expr.push_back(*pos);

        return evalStack();
    }
};

int main(int argc, char* argv[]) {
    int sz = 0;
    scanf("%d", &sz);
    char** inputArray = new char* [sz];
    
    for (int i = 0; i < sz; i++) {
        char* input = new char[30 + 1];
        scanf("%s", input);
        inputArray[i] = input;
    }

    Exam02 exam02;
    for (int i = 0; i < sz; i++) {
        printf("%d\n", exam02.evalStack(inputArray[i]));
    }
    for (int i = 0; i < sz; i++)
        delete[] inputArray[i];
    delete[] inputArray;

    return 0;
}
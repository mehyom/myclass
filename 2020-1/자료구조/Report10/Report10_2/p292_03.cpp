#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

const string reverse(const string& a);

int main()
{
    string str;
    cout << " 문자열을 입력해주세요" << endl;
    getline(cin, str);
    cout << reverse(str);
    return 0;
}

const string reverse(const string& str)
{
    int num = str.size();
    if (num <= 1) {
        return str;
    }
    else {
        return str.substr(num - 1) + reverse(str.substr(0, num - 1));
    }
}
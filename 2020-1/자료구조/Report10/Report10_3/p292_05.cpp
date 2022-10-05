#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int x[100];

void display(int* arr, int left, int right)
{
    for (int i = left; i < right; i++)
        if (x[i])
            cout << "X";
        else
            cout << "-";
    cout << endl;
}

void star(int org, int row, int left, int right)
{
    if (row == 0) { return; }
    for (int i = 0; i < right; i++)
        x[i] = 0;
    int X = right/2 + 1;
    int next = X;
    for (int i = 0; i < org - row; i++)
        X /= 2;
    for (int i = 1; i < org - row; i++)
        next /= 2;
    x[X] = 1;
    while (X + next < right)
    {
        X += next;
        x[X] = 1;
    }

    display(x, left, right);
    star(org, --row, left, right);
}


void main() {
	int row;
	int left;
	int right;

	cout << "input Row: ";
	scanf("%d", &row);
    int org = row;
	cout << "input Left: ";
	scanf("%d", &left);
	cout << "input Rigt: ";
	scanf("%d", &right);
	cout << endl;

	star(org, row, left, right);
}
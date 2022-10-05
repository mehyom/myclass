#include <cstdio>
#include <stdio.h>
#include <string.h>

struct Person {
	char name[80];
	int age;
	float salary;
};

void inputPerson(Person* person)
{
	scanf("%s", person->name);
	scanf("%d", &person->age);
	scanf("%f", &person->salary);
}

void outputPerson(Person* person)
{
	printf("%s\n", person->name);
	printf("%d\n", person->age);
	printf("%f\n", person->salary);
}

int main()
{
	int numOfPerson = 0;
	Person input;
	Person sum = { "", 0, 0.0 };

	scanf("%d", &numOfPerson);

	for (int i = 0; i < numOfPerson; i++) {
		inputPerson(&input);
		strcat(sum.name, input.name);
		sum.age += input.age;
		sum.salary += input.salary;
	}
	outputPerson(&sum);
}
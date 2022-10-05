#pragma once
#include "StudentQueue.h"
#include <deque>

using namespace std;

struct Couple {
	Student girl;
	Student boy;

	Couple(Student _girl, Student _boy)
		:girl(_girl), boy(_boy) {}
	~Couple() {}
};

class CoupleArray {
	std::deque<Couple> data;
public:
	void push(const Couple& val) {
		data.push_back(val);
	}
	void display() {
		for (auto it = data.begin(); it != data.end(); it++) {
			const Couple& couple = *it;
			printf("���л� %s�� ���л� %s Ŀ��\n", couple.girl.name, couple.boy.name);
		}
	}
};

#define SUPPLY_COUNT 10
class Staff {
public:
	StudentQueue& queG;
	StudentQueue& queB;
	int nMeeting;

	Student* student;
	Staff(StudentQueue& queGirl, StudentQueue& queBoy) :
		queG(queGirl),
		queB(queBoy),
		nMeeting(0),
		student(NULL){
	}

	void processing(int clock, CoupleArray* c) {
		if (queG.isEmpty() || queB.isEmpty()) printf("���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�.\n\n");
		else {
			Student girl = queG.dequeue();
			Student boy = queB.dequeue();
			printf("Ŀ���� ź���߽��ϴ�! ���л� %s�� ���л� %s\n\n", girl.name, boy.name);
			nMeeting++;
			Couple mycouple(girl, boy);
			c->push(mycouple);
		}
	}
};

class Meeting
{
	StudentQueue girl;
	StudentQueue boy;
	Staff staff;

	int totalWaitTime;
	int nMeeting;

	int totalStudent;
	int nStudent = 0;
	double probArrival;

	double Random() { return rand() / (double)RAND_MAX; }
	bool IsNewStudent() { return Random() < probArrival; }


	int studentSex() {
		return rand() % 2;
	}
	const char* studentSex(int sex) {
		static char sexes[2][10] = { "girl","boy" };
		return sexes[sex];
	}
	const char* studentName(int sex) {
		static char names[2][SUPPLY_COUNT][32] = { 
			{ "����", "����", "�̳�", "�Ҷ�", "����", "����", "����", "��", "����", "����" },
			{ "����", "�ع�", "����", "����", "�ؼ�", "�α�", "����", "����", "���", "����" } };
		return names[sex][rand() % SUPPLY_COUNT];
	}

	void InsertStudent(int arrivalTime) {
		int sex = studentSex();
		const char* name = studentName(sex);
		Student a(arrivalTime, studentSex(sex), studentName(sex));
		if (sex == 0) {
			girl.enqueue(a);
			printf("*****���л� %s ���*****\n", a.name);
		}
		else {
			boy.enqueue(a);
			printf("*****���л� %s ���*****\n", a.name);
		}
		nStudent++;
	}

public:
	Meeting() :
		staff(girl, boy),
		totalWaitTime(0), nMeeting(0) {
	}

	void readSimulationParameters() {
		printf("�ùķ��̼� �� �ִ� �ο� (��:100[��]) = ");
		scanf("%d", &totalStudent);
		printf("�����ð��� �����ϴ� �л� �� (��:0.5[�л�/���� �ð�]) = ");
		scanf("%lf", &probArrival);

		printf("\n====================================================\n\n");
	}

	void run(CoupleArray* c) {
		int clock = 0;
		int serviceTime = -1;

		while (nStudent < totalStudent + 1) {
			clock++;
			printf("===================================================\n");
			printf("[����ð� = %d]\n", clock);
			if (IsNewStudent()) InsertStudent(clock);
			girl.display("Girl");
			boy.display("Boy");

			staff.processing(clock, c);
			totalWaitTime += girl.getSize();
			totalWaitTime += boy.getSize();
		}
		nMeeting = staff.nMeeting;
	}


	void printStat(CoupleArray* c) {
		printf("=============================\n");
		printf("�����մϴ�! �� %dĿ���� ź���߽��ϴ�\n", nMeeting);
		c->display();
		printf("�л� ��� ��� �ð��� %-5.2f���Դϴ�\n",
			(double)totalWaitTime / totalStudent);
	}
};


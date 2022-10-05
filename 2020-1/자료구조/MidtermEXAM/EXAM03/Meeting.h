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
			printf("여학생 %s와 남학생 %s 커플\n", couple.girl.name, couple.boy.name);
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
		if (queG.isEmpty() || queB.isEmpty()) printf("아직 대상자가 없습니다. 기다려주십시오.\n\n");
		else {
			Student girl = queG.dequeue();
			Student boy = queB.dequeue();
			printf("커플이 탄생했습니다! 여학생 %s와 남학생 %s\n\n", girl.name, boy.name);
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
			{ "은아", "현아", "미나", "소라", "혜정", "미정", "선아", "희영", "신혜", "소정" },
			{ "준희", "준범", "선욱", "종수", "준수", "민규", "선만", "형석", "경용", "범수" } };
		return names[sex][rand() % SUPPLY_COUNT];
	}

	void InsertStudent(int arrivalTime) {
		int sex = studentSex();
		const char* name = studentName(sex);
		Student a(arrivalTime, studentSex(sex), studentName(sex));
		if (sex == 0) {
			girl.enqueue(a);
			printf("*****여학생 %s 등록*****\n", a.name);
		}
		else {
			boy.enqueue(a);
			printf("*****남학생 %s 등록*****\n", a.name);
		}
		nStudent++;
	}

public:
	Meeting() :
		staff(girl, boy),
		totalWaitTime(0), nMeeting(0) {
	}

	void readSimulationParameters() {
		printf("시뮬레이션 할 최대 인원 (예:100[명]) = ");
		scanf("%d", &totalStudent);
		printf("단위시간에 도착하는 학생 수 (예:0.5[학생/단위 시간]) = ");
		scanf("%lf", &probArrival);

		printf("\n====================================================\n\n");
	}

	void run(CoupleArray* c) {
		int clock = 0;
		int serviceTime = -1;

		while (nStudent < totalStudent + 1) {
			clock++;
			printf("===================================================\n");
			printf("[현재시각 = %d]\n", clock);
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
		printf("축하합니다! 총 %d커플이 탄생했습니다\n", nMeeting);
		c->display();
		printf("학생 평균 대기 시간은 %-5.2f분입니다\n",
			(double)totalWaitTime / totalStudent);
	}
};


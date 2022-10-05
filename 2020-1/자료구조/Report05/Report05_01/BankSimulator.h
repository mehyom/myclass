#pragma once
#include "CustomerQueue.h"

using namespace std;

class Teller {
public:
	CustomerQueue& que;
	int serviceTime;
	int tellerNo;
	int nServedCustomers;
	int totalWaitTime;
	Customer* customer;
	Teller(int _tellerNo, CustomerQueue& _que) :
		que(_que),
		serviceTime(-1), 
		tellerNo(_tellerNo),
		nServedCustomers(0),
		totalWaitTime(0),
		customer(NULL)
	{}

	void processing(int clock) {
		if (serviceTime > 0) {
			serviceTime--;
			printf("�� %d ���� �� (���񽺽ð� %d)...............\n", customer->id, customer->tService);

		}  else {
			if (que.isEmpty()) return;
			customer = &que.dequeue();
			nServedCustomers++;
			totalWaitTime += clock - customer->tArrival;
			printf("�� %d ���� ���� (���ð�:%d��) at Service %d\n",
				customer->id, clock - customer->tArrival, tellerNo);
			serviceTime = customer->tService - 1;
		}
	}
};

class BankSimulator
{
	CustomerQueue que1;
	CustomerQueue que2;
	Teller t1;
	Teller t2;
	int nCustomers;
	int totalWaitTime;
	int nServedCustomers;

	int nSimulation;
	double probArrival;
	int tMaxService;

#if 0
	double Random() { return rand() / (double)RAND_MAX; }
	bool IsNewCustomer() { return Random() < probArrival; }
	int RandServiceTime() { return (int)(tMaxService * Random()) + 1; }
#endif

	bool IsNewCustomer() { return 1; }
	int RandServiceTime() { return 5; }

	void InsertCustomer(int arrivalTime) {
		Customer a(++nCustomers, arrivalTime, RandServiceTime());
		printf("*****�� %d �湮 (���� �ð�: %d��)*****\n", a.id, a.tService);

		int queCompResult = que1.getSize() - que2.getSize();
		if (queCompResult >0)
			que2.enqueue(a);
		else if (queCompResult < 0)
			que1.enqueue(a);
		else {
			if (t1.serviceTime > t2.serviceTime) 
				que2.enqueue(a);
			else 
				que1.enqueue(a);
		}
	}

public:
	BankSimulator() :
		t1(1, que1), t2(2, que2), 
		nCustomers(0), totalWaitTime(0), nServedCustomers(0){
	}

	void readSimulationParameters() {
		printf("�ùķ��̼� �� �ִ� �ð� (��:10) = ");
		scanf("%d", &nSimulation);
		printf("�����ð��� �����ϴ� �� �� (��:0.5) = ");
		scanf("%lf", &probArrival);
		printf("�� ���� ���� �ִ� ���� �ð� (��:5) = ");
		scanf("%d", &tMaxService);

		printf("====================================================\n");
	}

	void run() {
		int clock = 0;
		int serviceTime = -1;

		while (clock < nSimulation) {
			clock++;
			printf("------------------------------------------------------\n");
			printf("[����ð� = %d]\n", clock);
			if (IsNewCustomer()) InsertCustomer(clock);
			que1.display(1);
			que2.display(2);

			t1.processing(clock);
			t2.processing(clock);

		}
		nServedCustomers = t1.nServedCustomers + t2.nServedCustomers;
		totalWaitTime = t1.totalWaitTime + t2.totalWaitTime;
	}


	void printStat() {
		printf("=============================\n");
		printf("���� ���� ���� = %d\n", nServedCustomers);
		printf("��ü ��� �ð� = %d��\n", totalWaitTime);
		printf("���� �� ��մ��ð� = %-5.2f��\n",
			(double)totalWaitTime / nServedCustomers);
		printf("���� ��� �� �� = %d\n",
			nCustomers - nServedCustomers);
	}
};
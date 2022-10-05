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
			printf("고객 %d 서비스 중 (서비스시간 %d)...............\n", customer->id, customer->tService);

		}  else {
			if (que.isEmpty()) return;
			customer = &que.dequeue();
			nServedCustomers++;
			totalWaitTime += clock - customer->tArrival;
			printf("고객 %d 서비스 시작 (대기시간:%d분) at Service %d\n",
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
		printf("*****고객 %d 방문 (서비스 시간: %d분)*****\n", a.id, a.tService);

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
		printf("시뮬레이션 할 최대 시간 (예:10) = ");
		scanf("%d", &nSimulation);
		printf("단위시간에 도착하는 고객 수 (예:0.5) = ");
		scanf("%lf", &probArrival);
		printf("한 고객에 대한 최대 서비스 시간 (예:5) = ");
		scanf("%d", &tMaxService);

		printf("====================================================\n");
	}

	void run() {
		int clock = 0;
		int serviceTime = -1;

		while (clock < nSimulation) {
			clock++;
			printf("------------------------------------------------------\n");
			printf("[현재시각 = %d]\n", clock);
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
		printf("서비스 받은 고객수 = %d\n", nServedCustomers);
		printf("전체 대기 시간 = %d분\n", totalWaitTime);
		printf("서비스 고객 평균대기시간 = %-5.2f분\n",
			(double)totalWaitTime / nServedCustomers);
		printf("현재 대기 고객 수 = %d\n",
			nCustomers - nServedCustomers);
	}
};
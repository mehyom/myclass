#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include "BankSimulator.h"

int main()
{
	srand((unsigned int)time(NULL));
	BankSimulator sim;
	sim.readSimulationParameters();
	sim.run();
	sim.printStat();
}
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include "Meeting.h"

int main()
{
	CoupleArray coupleArray;
	srand((unsigned int)time(NULL));
	Meeting sim;
	sim.readSimulationParameters();
	sim.run(&coupleArray);
	sim.printStat(&coupleArray);
}
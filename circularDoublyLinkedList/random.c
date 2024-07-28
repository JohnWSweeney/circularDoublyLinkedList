#include "random.h"

void seedRand()
{
	srand(time(NULL));
}

int getRandNum(int min, int max)
{
	return rand() % (max + 1 - min) + min;
}
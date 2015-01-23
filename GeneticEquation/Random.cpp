#include "Random.h"


CRandom::CRandom()
{
	gen = std::mt19937(rd());
}


CRandom::~CRandom()
{
}

int CRandom::iNextInt(int i_min, int i_max)
{
	std::uniform_int_distribution<int> dist(i_min, i_max);
	return dist(gen);
}
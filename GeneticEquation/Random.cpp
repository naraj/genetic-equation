#include "Random.h"


CRandom::CRandom() : gen(rd())
{
}


CRandom::~CRandom()
{
}

int CRandom::iNextInt(int i_min, int i_max) const
{
	std::uniform_int_distribution<int> dist(i_min, i_max);
	return dist(gen);
}

int CRandom::iNextInt(int i_max) const
{
	std::uniform_int_distribution<int> dist(0, i_max);
	return dist(gen);
}

bool CRandom::bChance(int i_chance) const
{
	std::uniform_int_distribution<int> dist(1, i_chance);
	return dist(gen) == 1;
}

double CRandom::dNextDouble() const
{
	std::uniform_real_distribution<double> dist(0, 1);
	return dist(gen);
}
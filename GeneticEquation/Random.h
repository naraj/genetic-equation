#pragma once
#include <random>

class CRandom
{
	std::random_device rd;
	std::mt19937 gen;
public:
	CRandom();
	~CRandom();
	int iNextInt(int i_min, int i_max);
	int iNextInt(int i_max);
	bool bChance(int i_chance);
	double dNextDouble();
};


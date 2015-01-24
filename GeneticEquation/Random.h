#pragma once
#include <random>

class CRandom
{
	std::random_device rd;
	mutable std::mt19937_64 gen;
public:
	CRandom();
	~CRandom();
	int iNextInt(int i_min, int i_max) const;
	int iNextInt(int i_max) const;
	bool bChance(int i_chance) const;
	double dNextDouble() const;
};


#pragma once
#include <vector>
#include "Organism.h"

class CAlgorithm
{
	int i_number_of_chromosomes;
	int i_replace_by_generation;

	std::vector<COrganism*> v_chromosomes;

public:
	CAlgorithm(int i_number_of_chromosomes, int i_replace_by_generation);
	~CAlgorithm();
};


#include "Algorithm.h"


CAlgorithm::CAlgorithm(int i_number_of_chromosomes, int i_replace_by_generation)
{
	// there should be at least 2 chromosomes in population
	if (i_number_of_chromosomes < 2)
		this->i_number_of_chromosomes = 2;

	if (i_replace_by_generation < 1)
		this->i_replace_by_generation = 1;

	// reserve space for population
	v_chromosomes.resize(i_number_of_chromosomes);
}

CAlgorithm::~CAlgorithm()
{
	for (int i = 0; i < v_chromosomes.size(); i++)
		delete v_chromosomes[i];
}

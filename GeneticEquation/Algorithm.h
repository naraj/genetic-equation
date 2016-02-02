#pragma once
#include <vector>
#include "Organism.h"
#include "OrganismObserver.h"

class CAlgorithm
{
	int i_number_of_chromosomes;
	int i_replace_by_generation;
	
	typedef std::unique_ptr < COrganism > orgPtr;

	std::vector<orgPtr> v_chromosomes;

	const CProblem& cProblem;
	const CRandom* c_random;
	const double D_MIN_ERROR =  0.000000000001;
	double d_current_best_error;

	COrganismObserver* p_c_organism_observer;

public:
	CAlgorithm(int i_number_of_chromosomes, int i_replace_by_generation, const CProblem& cProblem, COrganismObserver*);
	~CAlgorithm();
	void vStart();
	const COrganism* pcGetBestChromosome();
};


#include "Algorithm.h"
#include <algorithm>


CAlgorithm::CAlgorithm(int i_number_of_chromosomes, int i_replace_by_generation, const CProblem& cProblem, COrganismObserver* c_organism_observer) : cProblem(cProblem), p_c_organism_observer(c_organism_observer)
{
	// there should be at least 2 chromosomes in population
	if (i_number_of_chromosomes < 2)
		this->i_number_of_chromosomes = 2;

	if (i_replace_by_generation < 1)
		this->i_replace_by_generation = 1;
	else if (i_replace_by_generation > i_number_of_chromosomes - 1)
		this->i_replace_by_generation = i_number_of_chromosomes - 1;
	// reserve space for population
	v_chromosomes.resize(i_number_of_chromosomes);

	c_random = new CRandom();
	d_current_best_error = std::numeric_limits<double>::max();
}

CAlgorithm::~CAlgorithm()
{
	for (size_t i = 0; i < v_chromosomes.size(); ++i)
		delete v_chromosomes[i];

	delete c_random;

	delete p_c_organism_observer;
}

void CAlgorithm::vStart()
{
	for (size_t i = 0; i < v_chromosomes.size(); ++i)
		v_chromosomes[i] = new COrganism(cProblem);

	auto b_is_done = false;
	long long l_generations = 0;

	while (!b_is_done)
	{
		++l_generations;
		for (size_t i = 0; i < v_chromosomes.size(); ++i)
			v_chromosomes.at(i)->vTick();

		std::sort(v_chromosomes.begin(), v_chromosomes.end(), [](COrganism* c1, COrganism* c2)
		{
			return c1->dGetCurrError() < c2->dGetCurrError();
		});

		COrganism* pc_best = pcGetBestChromosome();
		if (pc_best->dGetCurrError() < d_current_best_error)
		{
			d_current_best_error = pc_best->dGetCurrError();
			if (p_c_organism_observer)
				p_c_organism_observer->vUpdate(l_generations, pc_best);
		}

		if (pc_best->dGetCurrError() < D_MIN_ERROR)
			b_is_done = true;
		else
		{
			for (size_t i = v_chromosomes.size() - 1; i >= v_chromosomes.size() - 1 - i_replace_by_generation; --i)
			{
				delete v_chromosomes[i];
			}
			for (size_t i = v_chromosomes.size() - 1; i >= v_chromosomes.size() - 1 - i_replace_by_generation; --i)
			{
				if (c_random->bChance(3))
				{
					v_chromosomes[i] = new COrganism(*pc_best);
				}
				else if (c_random->bChance(3))
				{
					auto i_index = c_random->iNextInt(v_chromosomes.size() - 1 - i_replace_by_generation);
					v_chromosomes[i] = new COrganism(*v_chromosomes.at(i_index));
				}
				else
				{
					auto i_index = c_random->iNextInt(v_chromosomes.size() - 1 - i_replace_by_generation);
					v_chromosomes[i] = pc_best->pcMakeCrossover(*v_chromosomes.at(i_index));
				}
			}

		}
	}

}

COrganism* CAlgorithm::pcGetBestChromosome()
{
	return v_chromosomes.front();
}
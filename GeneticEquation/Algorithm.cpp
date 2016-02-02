#include "Algorithm.h"
#include <algorithm>
#include <iterator>

CAlgorithm::CAlgorithm(int i_number_of_chromosomes, int i_replace_by_generation, const CProblem& cProblem, COrganismObserver* c_organism_observer) : cProblem(cProblem), p_c_organism_observer(c_organism_observer)
{
	// there should be at least 2 chromosomes in population
	if (i_number_of_chromosomes < 2)
		this->i_number_of_chromosomes = 2;
	else
		this->i_number_of_chromosomes = i_number_of_chromosomes;

	if (i_replace_by_generation < 1)
		this->i_replace_by_generation = 1;
	else if (i_replace_by_generation > i_number_of_chromosomes - 1)
		this->i_replace_by_generation = i_number_of_chromosomes - 1;
	else
		this->i_replace_by_generation = i_replace_by_generation;
	// reserve space for population
	v_chromosomes.reserve(i_number_of_chromosomes);

	c_random = new CRandom();
	d_current_best_error = std::numeric_limits<double>::max();
}

CAlgorithm::~CAlgorithm()
{
	/*for (size_t i = 0; i < v_chromosomes.size(); ++i)
		delete v_chromosomes[i];*/

	delete c_random;

	delete p_c_organism_observer;
}

void CAlgorithm::vStart()
{
	for (int i = 0; i < i_number_of_chromosomes; ++i)
		v_chromosomes.push_back( orgPtr(new COrganism(cProblem)));

	auto b_is_done = false;
	long long l_generations = 0;

	while (!b_is_done)
	{
		++l_generations;

		for (orgPtr const & i : v_chromosomes)
			i->vTick();

		std::sort(v_chromosomes.begin(), v_chromosomes.end(), [](orgPtr const& c1, orgPtr const& c2)
		{
			return c1->dGetCurrError() < c2->dGetCurrError();
		});

		const COrganism* pc_best = pcGetBestChromosome();
		if (pc_best->dGetCurrError() < d_current_best_error)
		{
			d_current_best_error = pc_best->dGetCurrError();
			if (p_c_organism_observer)
				p_c_organism_observer->vUpdate(l_generations, pc_best->sToString(), pc_best->dGetCurrError()); // FIXME
		}

		if (pc_best->dGetCurrError() < D_MIN_ERROR)
			b_is_done = true;
		else
		{
			std::vector<orgPtr> v_replacements;
			v_replacements.reserve(i_replace_by_generation);

			for (int i = 0; i < i_replace_by_generation; ++i)
			{
				if (c_random->bChance(3))
				{
					v_replacements.push_back( orgPtr(new COrganism(*pc_best)));
				}
				else if (c_random->bChance(3))
				{
					int i_index = c_random->iNextInt(i_number_of_chromosomes - 1 - i_replace_by_generation);
					v_replacements.push_back( orgPtr(new COrganism(*v_chromosomes.at(i_index))));
				}
				else
				{
					int i_index = c_random->iNextInt(i_number_of_chromosomes - 1 - i_replace_by_generation);
					v_replacements.push_back( orgPtr(pc_best->pcMakeCrossover(*v_chromosomes.at(i_index))));
				}
			}

			std::move(v_replacements.begin(), v_replacements.end(), std::back_inserter(v_chromosomes));

		}
	}

}

const COrganism* CAlgorithm::pcGetBestChromosome()
{
	return v_chromosomes.front().get();
}
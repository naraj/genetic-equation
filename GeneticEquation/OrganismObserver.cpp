#include "OrganismObserver.h"
#include <iostream>


COrganismObserver::COrganismObserver()
{
}


COrganismObserver::~COrganismObserver()
{
}

void COrganismObserver::vUpdate(long long l_generation, const COrganism* pc_new_best_organism)
{
	std::cout << "Generation: " << l_generation << std::endl;
	std::cout << pc_new_best_organism->sToString() << std::endl;
	std::cout << "Current error: " << pc_new_best_organism->dGetCurrError() << std::endl;
}
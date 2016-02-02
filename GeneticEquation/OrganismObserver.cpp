#include "OrganismObserver.h"
#include <iostream>


COrganismObserver::COrganismObserver()
{
}


COrganismObserver::~COrganismObserver()
{
}

void COrganismObserver::vUpdate(long long l_generation, std::string organism_string, double d_error)
{
	std::cout << "Generation: " << l_generation << std::endl;
	std::cout << organism_string << std::endl;
	std::cout << "Current error: " << d_error << std::endl;
}
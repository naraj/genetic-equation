#pragma once
#include <string>

class COrganism;

class COrganismObserver
{
public:
	COrganismObserver();
	~COrganismObserver();

	void vUpdate(long long l_generation, std::string organism_string, double d_error);
};


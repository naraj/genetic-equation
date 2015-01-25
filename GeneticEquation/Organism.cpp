#include "Organism.h"
#include "MathOperator.h"


COrganism::COrganism(CProblem cProblem) : cProblem(cProblem)
{
	cRoot = new CMathOperator();
}

COrganism::~COrganism()
{
	delete cRoot;
}

std::string COrganism::sToString()
{
	return cRoot->sToString();
}
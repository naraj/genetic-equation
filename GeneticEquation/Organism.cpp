#include "Organism.h"
#include "MathOperator.h"


COrganism::COrganism(CNodeFactory* cFactory, CProblem cProblem) : cProblem(cProblem), cFactory(cFactory)
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

void COrganism::vCollapse()
{
	if (CMathOperator* c_math_operator = dynamic_cast<CMathOperator*>(cRoot))
	{
		c_math_operator->vCollapse();
	}
}
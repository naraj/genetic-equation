#include "Organism.h"
#include "MathOperator.h"


COrganism::COrganism(CProblem cProblem) : cProblem(cProblem)
{
	cRoot = new CMathOperator(this);
	cFactory = new CNodeFactory(cProblem.iGetNumberOfArgs());
	cRandom = new CRandom();
}

COrganism::~COrganism()
{
	delete cRoot;
	delete cFactory;
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

CNodeFactory* COrganism::pcGetNodeFactory()
{
	return cFactory;
}

CRandom* COrganism::pcGetRandom()
{
	return cRandom;
}
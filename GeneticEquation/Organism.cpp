#include "Organism.h"
#include "MathOperator.h"


COrganism::COrganism(CProblem cProblem) : cProblem(cProblem)
{
	cRoot = new CMathOperator(this);
	cFactory = new CNodeFactory(cProblem.iGetNumberOfArgs());
	cRandom = new CRandom();
}

COrganism::COrganism(const COrganism& cOther) : cProblem(cOther.cProblem)
{
	this->cRoot = cOther.cRoot->clone();
	this->cFactory = new CNodeFactory(cProblem.iGetNumberOfArgs());
	this->cRandom = new CRandom();
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

COrganism* COrganism::pcMakeCrossover(COrganism& cFather)
{
	COrganism* c_child = new COrganism(*this);
	CMathOperator* c_father_dna = cFather.pcGetRandomOperator()->clone();
	CMathOperator* c_mother_dna = c_child->pcGetRandomOperator();
	*c_mother_dna = *c_father_dna;

	return c_child;
}

CNodeFactory* COrganism::pcGetNodeFactory()
{
	return cFactory;
}

CRandom* COrganism::pcGetRandom()
{
	return cRandom;
}

CMathOperator* COrganism::pcGetRandomOperator()
{
	std::vector<CMathOperator*> nodes;
	vTraverseDNA(*cRoot, nodes);

	return nodes[this->cRandom->iNextInt(nodes.size())];
}

void COrganism::vTraverseDNA(CNode& current_node, std::vector<CMathOperator*>& nodes)
{
	if (CMathOperator* cOp = dynamic_cast<CMathOperator*>(&current_node))
	{
		nodes.push_back(cOp);

		vTraverseDNA(*cOp->pcGetLeft(), nodes);
		vTraverseDNA(*cOp->pcGetRight(), nodes);

	}
}
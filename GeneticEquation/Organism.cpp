#include "Organism.h"
#include "MathOperator.h"
#include "Engine.h"


COrganism::COrganism(CProblem cProblem) : cProblem(cProblem)
{
	cFactory = new CNodeFactory(cProblem.iGetNumberOfArgs());
	cRandom = new CRandom();
	cRoot = new CMathOperator(this);
}

COrganism::COrganism(const COrganism& cOther) : cProblem(cOther.cProblem)
{
	this->cFactory = new CNodeFactory(cProblem.iGetNumberOfArgs());
	this->cRandom = new CRandom();
	this->cRoot = cOther.cRoot->clone();
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

void COrganism::vTick()
{
	CEngine e = CEngine();
	CNode* new_root = cRoot->clone();
	new_root->vMutate();

	double total_new_error = 0;

	std::vector<CCase> v_cases = cProblem.vGetCases();

	for (size_t i = 0; i < v_cases.size(); i++)
	{
		e.vSetMultipleVariables(v_cases[i].vGetArgs());
		double new_result = cRoot->dEval(&e);

		double new_error = std::pow(new_result - v_cases[i].dGetResult(), 2);
		total_new_error += new_error;
	}

	if (total_new_error < d_current_error)
	{
		delete cRoot;
		cRoot = new_root;
		d_current_error = total_new_error;
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

double COrganism::dGetCurrError()
{
	return d_current_error;
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
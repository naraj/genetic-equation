#include "Organism.h"
#include "MathOperator.h"
#include <math.h>


COrganism::COrganism(const CProblem& cProblem) : cProblem(cProblem)
{
	cFactory = new CNodeFactory(cProblem.iGetNumberOfArgs());
	cRandom = new CRandom();
	cRoot = std::unique_ptr<CNode>(new CMathOperator(this));
	d_current_error = std::numeric_limits<double>::max();
}

COrganism::COrganism(const COrganism& cOther) : cProblem(cOther.cProblem)
{
	this->cFactory = new CNodeFactory(cProblem.iGetNumberOfArgs());
	this->cRandom = new CRandom();
	this->cRoot = cOther.cRoot->clone();
	this->cRoot->setPcOrganism(this);
	this->d_current_error = std::numeric_limits<double>::max();
}

COrganism::~COrganism()
{
	delete cFactory;
	delete cRandom;
}

std::string COrganism::sToString() const
{
	return cRoot->sToString();
}

void COrganism::vCollapse()
{
	if (CMathOperator* c_math_operator = dynamic_cast<CMathOperator*>(cRoot.get()))
	{
		c_math_operator->vCollapse();
	}
}

void COrganism::vTick()
{
	std::unique_ptr<CNode> new_root = cRoot->clone();
	new_root->vMutate();


	double total_new_error = 0;

	const auto& v_cases = cProblem.vGetCases();

	for (size_t i = 0; i < v_cases.size(); i++)
	{
		auto new_result = new_root->dEval(&v_cases[i].cGetEngine());

		auto new_error = fabs(new_result - v_cases[i].dGetResult());
		total_new_error += new_error;
	}

	if (total_new_error < d_current_error)
	{
		cRoot = std::move(new_root);
		d_current_error = total_new_error;
	}
	else
	{
		new_root.release();
	}

}

COrganism* COrganism::pcMakeCrossover(const COrganism& cFather) const
{
	COrganism* c_child = new COrganism(*this);
	CMathOperator* c_father_dna = new CMathOperator(*cFather.pcGetRandomOperator());
	CMathOperator* c_mother_dna = c_child->pcGetRandomOperator();
	*c_mother_dna = *c_father_dna;
	delete c_father_dna;
	c_mother_dna->setPcOrganism(c_child);
	return c_child;
}

double COrganism::dGetCurrError() const
{
	return d_current_error;
}

CNodeFactory* COrganism::pcGetNodeFactory() const
{
	return cFactory;
}

CRandom* COrganism::pcGetRandom() const
{
	return cRandom;
}

CMathOperator* COrganism::pcGetRandomOperator() const
{
	std::vector<CMathOperator*> nodes = {};
	vTraverseDNA(cRoot.get(), nodes);

	return nodes[this->cRandom->iNextInt(nodes.size() - 1)];
}

void COrganism::vTraverseDNA(CNode* current_node, std::vector<CMathOperator*>& nodes) const
{
	if (CMathOperator* cOp = dynamic_cast<CMathOperator*>(current_node))
	{
		nodes.push_back(cOp);

		vTraverseDNA(cOp->pcGetLeft(), nodes);
		vTraverseDNA(cOp->pcGetRight(), nodes);

	}
}
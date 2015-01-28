#pragma once
#include "Problem.h"
#include "Node.h"
#include "NodeFactory.h"

class CMathOperator;

class COrganism
{
	const CProblem& cProblem;
	CNode* cRoot;
	CNodeFactory* cFactory;
	CRandom* cRandom;
	double d_current_error;
public:
	COrganism(const CProblem& cProblem);
	COrganism(const COrganism& cOther);
	~COrganism();
	std::string sToString() const;
	void vCollapse();
	void vTick();
	COrganism* pcMakeCrossover(const COrganism& cFather) const;
	double dGetCurrError();

	CNodeFactory* pcGetNodeFactory();
	CRandom* pcGetRandom();
private:
	CMathOperator* pcGetRandomOperator() const;
	void vTraverseDNA(CNode& current_node, std::vector<CMathOperator*>& nodes) const;
};


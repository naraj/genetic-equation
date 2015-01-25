#pragma once
#include "Problem.h"
#include "Node.h"
#include "NodeFactory.h"

class CMathOperator;

class COrganism
{
	CProblem cProblem;
	CNode* cRoot;
	CNodeFactory* cFactory;
	CRandom* cRandom;
public:
	COrganism(CProblem cProblem);
	~COrganism();
	std::string sToString();
	void vCollapse();
	CNodeFactory* pcGetNodeFactory();
	CRandom* pcGetRandom();
private:
	CMathOperator* pcGetRandomOperator();
	void vTraverseDNA(CNode& current_node, std::vector<CMathOperator*>& nodes);
};


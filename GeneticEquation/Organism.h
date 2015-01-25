#pragma once
#include "Problem.h"
#include "Node.h"
#include "NodeFactory.h"

class COrganism
{
	CProblem cProblem;
	CNode* cRoot;
	CNodeFactory* cFactory;
public:
	COrganism(CProblem cProblem);
	~COrganism();
	std::string sToString();
	void vCollapse();
};


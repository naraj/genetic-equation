#pragma once
#include "Problem.h"
#include "Node.h"

class COrganism
{
	CProblem cProblem;
	CNode* cRoot;
public:
	COrganism(CProblem cProblem);
	~COrganism();
	std::string sToString();
	void vCollapse();
};


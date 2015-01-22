#pragma once
#include "Node.h"
#include "Op.h"
class CMathOperator : public CNode
{
	CNode *cLeft, *cRight;
	COp *cOperator;
public:
	CMathOperator();
	~CMathOperator();
};


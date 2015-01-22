#pragma once
#include <string>
#include "AbstrEngine.h"

class CNode
{
public:
	virtual ~CNode(){}
	virtual CNode* create() const = 0;
	virtual CNode* clone() const = 0;
	virtual double dEval(CAbstrEngine &) = 0;
	virtual std::string sToString() = 0;
};


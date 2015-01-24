#pragma once
#include <string>
#include "AbstrEngine.h"

class CRandom;

class CNode
{
public:
	virtual ~CNode(){}
	virtual CNode* create() const = 0;
	virtual CNode* clone() const = 0;
	virtual double dEval(const CAbstrEngine *) = 0;
	virtual std::string sToString() = 0;
	virtual bool bIsStatic() = 0;
	virtual void vMutate(CRandom &) = 0;
};


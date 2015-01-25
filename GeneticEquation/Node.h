#pragma once
#include <string>
#include "AbstrEngine.h"
class COrganism;
class CRandom;

class CNode
{
protected:
	COrganism* c_organism;
public:
	virtual ~CNode(){}
	virtual CNode* create(COrganism*) const = 0;
	virtual CNode* clone() const = 0;
	virtual double dEval(const CAbstrEngine *) = 0;
	virtual std::string sToString() = 0;
	virtual bool bIsStatic() = 0;
	virtual void vMutate(const CRandom &) = 0;
};


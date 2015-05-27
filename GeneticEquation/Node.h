#pragma once

#include <string>

class CAbstrEngine;
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
	virtual CNode* move_clone() = 0;
	virtual double dEval(const CAbstrEngine *) const = 0;
	virtual std::string sToString() const = 0;
	virtual bool bIsStatic() const = 0;
	virtual void vMutate() = 0;
	virtual void setPcOrganism(COrganism* c_organism);
};

inline void CNode::setPcOrganism(COrganism* c_organism)
{
	this->c_organism = c_organism;
}

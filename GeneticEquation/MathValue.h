#pragma once

#include "Node.h"
#include <string>

class CMathValue : public CNode
{
	double d_value;
public:
	CMathValue(COrganism*);
	CMathValue(COrganism*,double d_value);
	std::unique_ptr<CNode> create(COrganism*) const override;
	std::unique_ptr<CNode> clone() const override;
	std::unique_ptr<CNode> move_clone() override;
	double dEval(const CAbstrEngine *) const override;
	std::string sToString() const override;
	bool bIsStatic() const override;
	void vMutate() override;
	double dGetValue();

private:
	void vMutateValue(const CRandom &);
};


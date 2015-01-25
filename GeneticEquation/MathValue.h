#pragma once
#include "Node.h"
class CMathValue : public CNode
{
	double d_value;
public:
	CMathValue(COrganism*);
	CMathValue(COrganism*,double d_value);
	~CMathValue();
	CMathValue* create(COrganism*) const override;
	CMathValue* clone() const override;
	double dEval(const CAbstrEngine *) override;
	std::string sToString() override;
	bool bIsStatic() override;
	void vMutate() override;
	double dGetValue();

private:
	void vMutateValue(const CRandom &);
};


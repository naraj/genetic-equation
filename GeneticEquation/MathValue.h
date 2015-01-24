#pragma once
#include "Node.h"
class CMathValue : public CNode
{
	double d_value;
public:
	CMathValue();
	~CMathValue();
	CMathValue* create() const override;
	CMathValue* clone() const override;
	double dEval(const CAbstrEngine *) override;
	std::string sToString() override;
	bool bIsStatic() override;
	void vMutate(CRandom &) override;
	double dGetValue();

private:
	void vMutateValue(CRandom &);
};


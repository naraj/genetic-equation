#pragma once
#include "Node.h"
class CMathValue : public CNode
{
	double d_value;
public:
	CMathValue();
	CMathValue(double d_value);
	~CMathValue();
	CMathValue* create() const override;
	CMathValue* clone() const override;
	double dEval(const CAbstrEngine *) override;
	std::string sToString() override;
	bool bIsStatic() override;
	void vMutate(const CRandom &) override;
	double dGetValue();

private:
	void vMutateValue(const CRandom &);
};


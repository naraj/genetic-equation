#pragma once
#include "Node.h"
class CMathVariable : public CNode
{
	std::string s_name;
public:
	CMathVariable(std::string s_name);
	CMathVariable(const CMathVariable& cOther);
	CMathVariable* create() const override;
	CMathVariable* clone() const override;
	~CMathVariable();

	double dEval(const CAbstrEngine *) override;
	std::string sToString() override;
	bool bIsStatic() override;
	void vMutate(const CRandom &) override;
};


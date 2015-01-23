#pragma once
#include "Node.h"
#include "Op.h"
class CMathOperator : public CNode
{
	CNode *cLeft, *cRight;
	COp *cOperator;
public:
	CMathOperator();
	CMathOperator(const CMathOperator& cOther);
	CMathOperator& operator= (const CMathOperator&);
	CMathOperator* create() const override;
	CMathOperator* clone() const override;
	~CMathOperator();
	std::string sToString() override;
	double dEval(CAbstrEngine &) override;
	bool bIsStatic() override;
	void vMutate() override;
};


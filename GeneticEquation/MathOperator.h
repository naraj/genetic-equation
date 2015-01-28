#pragma once
#include "Node.h"
#include "Op.h"
class CMathOperator : public CNode
{
	CNode *cLeft, *cRight;
	COp *cOperator;
public:
	CMathOperator(COrganism*);
	CMathOperator(const CMathOperator& cOther);
	CMathOperator& operator= (const CMathOperator&);
	CMathOperator* create(COrganism*) const override;
	CMathOperator* clone() const override;
	~CMathOperator();
	std::string sToString() const override;
	double dEval(const CAbstrEngine *) override;
	bool bIsStatic() override;
	void vMutate() override;
	void vCollapse();
	CNode* pcGetLeft();
	CNode* pcGetRight();
	void setLeft(CNode*);
	void setRight(CNode*);
	void setPcOrganism(COrganism* c_organism) override;
};


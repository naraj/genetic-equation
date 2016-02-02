#pragma once

#include "Node.h"
#include "Op.h"
#include <memory>


#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif  // _DEBUG

class CMathOperator : public CNode
{
	std::unique_ptr<CNode> cLeft, cRight;
	std::unique_ptr<COp> cOperator;
public:

	CMathOperator(COrganism*);
	CMathOperator(const CMathOperator&);
	CMathOperator(CMathOperator&&);
	CMathOperator& operator=(const CMathOperator&);
	CMathOperator& operator=(CMathOperator&&);

	std::unique_ptr<CNode> create(COrganism*) const override;
	std::unique_ptr<CNode> clone() const override;
	std::unique_ptr<CNode> move_clone() override;

	std::string sToString() const override;
	double dEval(const CAbstrEngine *) const override;
	bool bIsStatic() const override;
	void vMutate() override;
	void vCollapse();
	CNode* pcGetLeft() const;
	CNode* pcGetRight() const;
	void setLeft(std::unique_ptr<CNode>);
	void setRight(std::unique_ptr<CNode>);
	void setPcOrganism(COrganism* c_organism) override;
};


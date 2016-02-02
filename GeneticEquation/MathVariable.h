#pragma once
#include "Node.h"
#include <string>

class CMathVariable : public CNode
{
	std::string s_name;
public:
	CMathVariable(COrganism*, std::string s_name);
	std::unique_ptr<CNode> create(COrganism*) const override;
	std::unique_ptr<CNode> clone() const override;
	std::unique_ptr<CNode> move_clone() override;

	double dEval(const CAbstrEngine *) const override;
	std::string sToString() const override;
	bool bIsStatic() const override;
	void vMutate() override;
};


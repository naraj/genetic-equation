#pragma once
#include "Random.h"
#include "Op.h"
#include "MathVariable.h"
#include "MathValue.h"
#include <memory>

class CNodeFactory	
{
	std::unique_ptr<CRandom> c_random;
	std::vector<COp*> v_operators;
	std::vector<CMathVariable*> v_vars;
	std::vector<CMathValue*> v_values;
	std::vector<CNode*> v_nodes;
	int i_number_of_vars;
public:
	CNodeFactory(int i_number_of_vars);
	~CNodeFactory();

	std::unique_ptr<CNode> cGetRandomVariable();
	std::unique_ptr<CNode> cGetRandomValue();
	std::unique_ptr<COp> cGetRandomOperator();
	std::unique_ptr<CNode> cGetRandomNode();
private:
	void vPopulateOperators();
	void vPopulateVariables();
	void vPopulateValues();
};


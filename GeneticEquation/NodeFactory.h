#pragma once
#include "Random.h"
#include "Op.h"
#include "MathVariable.h"
#include "MathValue.h"

class CNodeFactory	
{
	CRandom* c_random;
	std::vector<COp> v_operators;
	std::vector<CMathVariable> v_vars;
	std::vector<CMathValue> v_values;
	int i_number_of_vars;
public:
	CNodeFactory(int i_number_of_vars);
	~CNodeFactory();

	CMathVariable* cGetRandomVariable();
	CMathValue* cGetRandomValue();
	COp* cGetRandomOperator();
private:
	void vPopulateOperators();
	void vPopulateVariables();
	void vPopulateValues();
};

#include "NodeFactory.h"


CNodeFactory::CNodeFactory(int i_number_of_vars) : i_number_of_vars(i_number_of_vars)
{
	c_random = new CRandom();
	vPopulateOperators();
	vPopulateValues();
	vPopulateVariables();
}


CNodeFactory::~CNodeFactory()
{
	delete c_random;
	for (int i = 0; i < v_nodes.size(); i++)
		delete v_nodes[i];
}

CMathVariable* CNodeFactory::cGetRandomVariable()
{
	return v_vars[c_random->iNextInt(v_vars.size() - 1)].clone();
}

CMathValue* CNodeFactory::cGetRandomValue()
{
	return v_values[0].clone();
}

COp* CNodeFactory::cGetRandomOperator()
{
	return v_operators[c_random->iNextInt(v_operators.size() - 1)].create();
}

CNode* CNodeFactory::cGetRandomNode()
{
	return v_nodes[c_random->iNextInt(v_operators.size() - 1)]->clone();
}

void CNodeFactory::vPopulateOperators()
{
	// TODO: populate operators in CNodeFactory
}

void CNodeFactory::vPopulateVariables()
{
	std::string names = "abcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < i_number_of_vars; i++)
	{
		v_vars.push_back(CMathVariable(nullptr, std::string(1, names[names.size() - i_number_of_vars + i])));
		v_nodes.push_back(new CMathVariable(nullptr, std::string(1, names[names.size() - i_number_of_vars + i])));
	}
}

void CNodeFactory::vPopulateValues()
{
	v_values.push_back(CMathValue(nullptr));
	v_nodes.push_back(new CMathValue(nullptr));
}
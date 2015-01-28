#include "NodeFactory.h"
#include "Add.h"
#include "Sub.h"
#include "Mult.h"
#include "Div.h"


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
	for (size_t i = 0; i < v_nodes.size(); i++)
		delete v_nodes[i];
	for (size_t i = 0; i < v_operators.size(); i++)
		delete v_operators[i];
}

CMathVariable* CNodeFactory::cGetRandomVariable()
{
	return v_vars[c_random->iNextInt(v_vars.size() - 1)].clone();
}

CMathValue* CNodeFactory::cGetRandomValue()
{
	return v_values.front()->clone();
}

COp* CNodeFactory::cGetRandomOperator()
{
	return v_operators[c_random->iNextInt(v_operators.size() - 1)]->create();
}

CNode* CNodeFactory::cGetRandomNode()
{
	return v_nodes[c_random->iNextInt(v_nodes.size() - 1)]->clone();
}

void CNodeFactory::vPopulateOperators()
{
	// TODO: populate operators in CNodeFactory
	v_operators.push_back(new CAdd());
	v_operators.push_back(new CSub());
	v_operators.push_back(new CMult());
	v_operators.push_back(new CDiv());
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
	v_values.push_back(new CMathValue(nullptr));
	v_nodes.push_back(new CMathValue(nullptr));
}
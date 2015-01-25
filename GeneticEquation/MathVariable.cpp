#include "MathVariable.h"


CMathVariable::CMathVariable(std::string s_name) : s_name(s_name)
{
}

CMathVariable::CMathVariable(const CMathVariable& cOther)
{
	this->s_name = cOther.s_name;
}

CMathVariable* CMathVariable::create() const
{
	return new CMathVariable("");
}

CMathVariable* CMathVariable::clone() const
{
	return new CMathVariable(*this);
}

CMathVariable::~CMathVariable()
{
}

double CMathVariable::dEval(const CAbstrEngine* cEngine)
{
	return cEngine->dGetVariable(s_name);
}

std::string CMathVariable::sToString()
{
	return s_name;
}

bool CMathVariable::bIsStatic()
{
	return false;
}

void CMathVariable::vMutate(const CRandom&)
{
	// TODO: CMathVariable::vMutate implementation
}
#include "MathVariable.h"
#include "NodeFactory.h"
#include "Organism.h"


CMathVariable::CMathVariable(COrganism* c_organism, std::string s_name) : s_name(s_name)
{
	this->c_organism = c_organism;
}

CMathVariable::CMathVariable(const CMathVariable& cOther)
{
	this->s_name = cOther.s_name;
}

CMathVariable* CMathVariable::create(COrganism* c_organism) const
{
	return new CMathVariable(c_organism, "");
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
	CNodeFactory* p_c_node_factory = this->c_organism->pcGetNodeFactory();
	CMathVariable* p_c_temp = p_c_node_factory->cGetRandomVariable();
	this->s_name = p_c_temp->s_name;
	delete p_c_temp;
}
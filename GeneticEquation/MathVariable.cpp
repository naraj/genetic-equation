#include "MathVariable.h"
#include "NodeFactory.h"
#include "Organism.h"


CMathVariable::CMathVariable(COrganism* c_organism, std::string s_name) : s_name(s_name)
{
	this->c_organism = c_organism;
}


std::unique_ptr<CNode> CMathVariable::create(COrganism* c_organism) const
{
	return std::unique_ptr<CNode>(new CMathVariable(c_organism, ""));
}

std::unique_ptr<CNode> CMathVariable::clone() const
{
	return std::unique_ptr<CNode>(new CMathVariable(*this));
}

std::unique_ptr<CNode> CMathVariable::move_clone()
{
	return std::unique_ptr<CNode>(new CMathVariable(std::move(*this)));
}

double CMathVariable::dEval(const CAbstrEngine* cEngine) const
{
	return cEngine->dGetVariable(s_name);
}

std::string CMathVariable::sToString() const
{
	return s_name;
}

bool CMathVariable::bIsStatic() const
{
	return false;
}

void CMathVariable::vMutate()
{
	CRandom* p_c_random = this->c_organism->pcGetRandom();
	if (p_c_random->bChance(20))
	{
		CNodeFactory* p_c_node_factory = this->c_organism->pcGetNodeFactory();
		std::unique_ptr<CNode> cnode = p_c_node_factory->cGetRandomVariable();
		if (std::unique_ptr<CMathVariable, std::default_delete<CNode> > p_c_temp = static_unique_ptr_cast<CMathVariable, CNode>(std::move(cnode)))
		{
			this->s_name = p_c_temp->s_name;
		}
	}	
}
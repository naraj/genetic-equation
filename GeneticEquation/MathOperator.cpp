#include "MathOperator.h"
#include "MathValue.h"
#include "Random.h"
#include "Organism.h"

CMathOperator::CMathOperator(COrganism* c_organism)
{
	this->c_organism = c_organism;
	cLeft = nullptr;
	cRight = nullptr;
	cOperator = nullptr;
	if (c_organism)
	{
		CNodeFactory* p_c_node_factory = this->c_organism->pcGetNodeFactory();
		cLeft = p_c_node_factory->cGetRandomValue();
		cRight = p_c_node_factory->cGetRandomValue();
		cOperator = p_c_node_factory->cGetRandomOperator();
	}
}

CMathOperator::CMathOperator(const CMathOperator& cOther)
{
	this->cLeft = cOther.cLeft->clone();
	this->cRight = cOther.cRight->clone();
	this->cOperator = cOther.cOperator->create();
	this->c_organism = cOther.c_organism;
}

CMathOperator& CMathOperator::operator=(const CMathOperator& cOther)
{
	if (this != &cOther)
	{
		if (cOther.cLeft)
		{
			delete this->cLeft;
			this->cLeft = cOther.cLeft->clone();
		}
		if (cOther.cRight)
		{
			delete this->cRight;
			this->cRight = cOther.cRight->clone();
		}
		if (cOther.cOperator)
		{
			delete this->cOperator;
			this->cOperator = cOther.cOperator->create();
		}

		this->c_organism = cOther.c_organism;

	}

	return *this;
}

CMathOperator* CMathOperator::create(COrganism* c_organism) const
{
	return new CMathOperator(c_organism);
}

CMathOperator* CMathOperator::clone() const
{
	return new CMathOperator(*this);
}

CMathOperator::~CMathOperator()
{
	delete cLeft;
	delete cRight;
	delete cOperator;
}

std::string CMathOperator::sToString()
{
	return cOperator->sToString(cLeft->sToString(), cRight->sToString());
}

double CMathOperator::dEval(const CAbstrEngine* cEngine)
{
	return cOperator->dEval(cLeft->dEval(cEngine), cRight->dEval(cEngine));
}

bool CMathOperator::bIsStatic()
{
	return cLeft->bIsStatic() && cRight->bIsStatic();
}

void CMathOperator::vMutate()
{
	CRandom * c_random = this->c_organism->pcGetRandom();
	// swap
	if (c_random->bChance(100))
	{
		CNode* c_temp = cLeft;
		cLeft = cRight;
		cRight = c_temp;
	}
	// collapse
	if (c_random->bChance(100))
	{
		vCollapse();
	}

	// delete
	if (c_random->bChance(15))
	{
		if (CMathOperator* c_left = dynamic_cast<CMathOperator*>(cLeft))
		{
			CNode* c_grandchild = c_left->cLeft->clone();
			delete cLeft;
			cLeft = c_grandchild;
		}
	}
	// delete
	if (c_random->bChance(15))
	{
		if (CMathOperator* c_left = dynamic_cast<CMathOperator*>(cLeft))
		{
			CNode* c_grandchild = c_left->cRight->clone();
			delete cLeft;
			cLeft = c_grandchild;
		}
	}
	// delete
	if (c_random->bChance(15))
	{
		if (CMathOperator* c_right = dynamic_cast<CMathOperator*>(cRight))
		{
			CNode* c_grandchild = c_right->cLeft->clone();
			delete cRight;
			cRight = c_grandchild;
		}
	}
	// delete
	if (c_random->bChance(15))
	{
		if (CMathOperator* c_right = dynamic_cast<CMathOperator*>(cRight))
		{
			CNode* c_grandchild = c_right->cRight->clone();
			delete cRight;
			cRight = c_grandchild;
		}
	}

	// TODO more options
}

void CMathOperator::vCollapse()
{
	if (CMathOperator* cOp = dynamic_cast<CMathOperator*> (cLeft))
	{
		cOp->vCollapse();
	}
	if (CMathOperator* cOp = dynamic_cast<CMathOperator*> (cRight))
	{
		cOp->vCollapse();
	}
	if (cLeft->bIsStatic())
	{
		double d_left = cLeft->dEval(nullptr);
		CMathValue* cVal = new CMathValue(this->c_organism, d_left);
		delete cLeft;
		cLeft = cVal;
	}
	if (cRight->bIsStatic())
	{
		double d_right = cRight->dEval(nullptr);
		CMathValue* cVal = new CMathValue(this->c_organism, d_right);
		delete cRight;
		cLeft = cVal;
	}
}
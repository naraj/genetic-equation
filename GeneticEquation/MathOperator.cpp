#include "MathOperator.h"
#include "MathValue.h"
#include "Random.h"

CMathOperator::CMathOperator()
{
	cLeft = nullptr;
	cRight = nullptr;
	cOperator = nullptr;
}

CMathOperator::CMathOperator(const CMathOperator& cOther)
{
	this->cLeft = cOther.cLeft->clone();
	this->cRight = cOther.cRight->clone();
	this->cOperator = cOther.cOperator->create();
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

	}

	return *this;
}

CMathOperator* CMathOperator::create() const
{
	return new CMathOperator();
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

void CMathOperator::vMutate(const CRandom& cRand)
{
	// swap
	if (cRand.bChance(100))
	{
		CNode* c_temp = cLeft;
		cLeft = cRight;
		cRight = c_temp;
	}
	// collapse
	if (cRand.bChance(100))
	{
		vCollapse();
	}

	// delete
	if (cRand.bChance(15))
	{
		if (CMathOperator* c_left = dynamic_cast<CMathOperator*>(cLeft))
		{
			CNode* c_grandchild = c_left->cLeft->clone();
			delete cLeft;
			cLeft = c_grandchild;
		}
	}
	// delete
	if (cRand.bChance(15))
	{
		if (CMathOperator* c_left = dynamic_cast<CMathOperator*>(cLeft))
		{
			CNode* c_grandchild = c_left->cRight->clone();
			delete cLeft;
			cLeft = c_grandchild;
		}
	}
	// delete
	if (cRand.bChance(15))
	{
		if (CMathOperator* c_right = dynamic_cast<CMathOperator*>(cRight))
		{
			CNode* c_grandchild = c_right->cLeft->clone();
			delete cRight;
			cRight = c_grandchild;
		}
	}
	// delete
	if (cRand.bChance(15))
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
		CMathValue* cVal = new CMathValue(d_left);
		delete cLeft;
		cLeft = cVal;
	}
	if (cRight->bIsStatic())
	{
		double d_right = cRight->dEval(nullptr);
		CMathValue* cVal = new CMathValue(d_right);
		delete cRight;
		cLeft = cVal;
	}
}
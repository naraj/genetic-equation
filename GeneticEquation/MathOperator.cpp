#include "MathOperator.h"


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
	*(this->cOperator) = *(cOther.cOperator);
}

CMathOperator& CMathOperator::operator=(const CMathOperator& cOther)
{
	if (this != &cOther)
	{
		delete this->cLeft;
		delete this->cRight;
		delete this->cOperator;
		if (cOther.cLeft)
			this->cLeft = cOther.cLeft->clone();
		if (cOther.cRight)
			this->cRight = cOther.cRight->clone();
		*(this->cOperator) = *(cOther.cOperator);
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

double CMathOperator::dEval(CAbstrEngine& cEngine)
{
	return cOperator->dEval(cLeft->dEval(cEngine), cRight->dEval(cEngine));
}

bool CMathOperator::bIsStatic()
{
	return (cLeft->bIsStatic() && cRight->bIsStatic());
}

void CMathOperator::vMutate(CRandom& cRand)
{

}
#include "MathValue.h"
#include "Random.h"
#include  "Organism.h"

CMathValue::CMathValue(COrganism* c_organism, double d_value) : d_value(d_value)
{
	this->c_organism = c_organism;
}

CMathValue::CMathValue(COrganism* c_organism)
{
	this->c_organism = c_organism;
	d_value = 0.0;
}


CMathValue::~CMathValue()
{
}

CMathValue* CMathValue::create(COrganism* c_organism) const
{
	return new CMathValue(c_organism);
}

CMathValue* CMathValue::clone() const
{
	return new CMathValue(*this);
}

double CMathValue::dEval(const CAbstrEngine*)
{
	return d_value;
}

std::string CMathValue::sToString()
{
	return std::to_string(d_value);
}

bool CMathValue::bIsStatic()
{
	return true;
}

void CMathValue::vMutate()
{
	CRandom * c_random = this->c_organism->pcGetRandom();

	if (c_random->bChance(50))
	{
		vMutateValue(*c_random);
	}
	if (c_random->bChance(100))
	{
		d_value = static_cast<int>(d_value);
	}
}

double CMathValue::dGetValue()
{
	return d_value;
}

void CMathValue::vMutateValue(const CRandom &cRand)
{
	d_value += (cRand.dNextDouble() - 0.5) * 10;
}
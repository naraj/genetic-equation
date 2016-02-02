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


std::unique_ptr<CNode> CMathValue::create(COrganism* c_organism) const
{
	return std::unique_ptr<CMathValue>( new CMathValue(c_organism));
}

std::unique_ptr<CNode> CMathValue::clone() const
{
	return std::unique_ptr<CMathValue>(new CMathValue(*this));
}

std::unique_ptr<CNode> CMathValue::move_clone()
{
	return std::unique_ptr<CMathValue>(new CMathValue(std::move(*this)));
}

double CMathValue::dEval(const CAbstrEngine*) const
{
	return d_value;
}

std::string CMathValue::sToString() const
{
	return std::to_string(d_value);
}

bool CMathValue::bIsStatic() const
{
	return true;
}

void CMathValue::vMutate()
{
	CRandom * c_random = this->c_organism->pcGetRandom();

	if (c_random->bChance(10))
	{
		vMutateValue(*c_random);
	}
	if (c_random->bChance(50))
	{
		int i_digits = c_random->iNextInt(5);
		double d_places = pow(10.0, i_digits);
		d_value = std::round(d_value * d_places) / d_places;
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
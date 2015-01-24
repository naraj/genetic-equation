#include "MathValue.h"
#include "Random.h"

CMathValue::CMathValue()
{
	d_value = 0.0;
}


CMathValue::~CMathValue()
{
}

CMathValue* CMathValue::create() const
{
	return new CMathValue();
}

CMathValue* CMathValue::clone() const
{
	return new CMathValue(*this);
}

double CMathValue::dEval(CAbstrEngine&)
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

void CMathValue::vMutate(CRandom& cRand)
{
	if (cRand.bChance(50))
	{
		vMutateValue(cRand);
	}
	if (cRand.bChance(100))
	{
		d_value = static_cast<int>(d_value);
	}
}

double CMathValue::dGetValue()
{
	return d_value;
}

void CMathValue::vMutateValue(CRandom &cRand)
{
	d_value += (cRand.dNextDouble() - 0.5) * 10;
}
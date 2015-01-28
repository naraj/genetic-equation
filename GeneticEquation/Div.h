#pragma once
#include "Op.h"
class CDiv :
	public COp
{
public:

	CDiv()
	{
	}

	~CDiv()
	{
	}
	COp* create() override;
	double dEval(double d_left, double d_right) override;
	std::string sToString(std::string s_left, std::string s_right) const override;
};

inline COp* CDiv::create()
{
	return new CDiv();
}

inline double CDiv::dEval(double d_left, double d_right)
{
	if (d_right == 0.0)
	{
		return 0; // cheat
	}
	return d_left / d_right;
}

inline std::string CDiv::sToString(std::string s_left, std::string s_right) const
{
	return "(" + s_left + " / " + s_right + ")";
}


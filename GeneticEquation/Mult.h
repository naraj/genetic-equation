#pragma once
#include "Op.h"

class CMult :
	public COp
{
public:

	CMult()
	{
	}

	~CMult()
	{
	}
	COp* create() override;
	double dEval(double d_left, double d_right) override;
	std::string sToString(std::string s_left, std::string s_right) override;
};

inline COp* CMult::create()
{
	return new CMult();
}

inline double CMult::dEval(double d_left, double d_right)
{
	return d_left * d_right;
}

inline std::string CMult::sToString(std::string s_left, std::string s_right)
{
	return "(" + s_left + " * " + s_right + ")";
}


#pragma once
#include "Op.h"
class CAdd :
	public COp
{
public:

	CAdd()
	{}

	~CAdd()
	{}

	COp* create() override;
	double dEval(double d_left, double d_right) override;
	std::string sToString(std::string s_left, std::string s_right) const override;
};

inline COp* CAdd::create()
{
	return new CAdd();
}

inline double CAdd::dEval(double d_left, double d_right)
{
	return d_left + d_right;
}

inline std::string CAdd::sToString(std::string s_left, std::string s_right) const
{
	return "(" + s_left + " + " + s_right + ")";
}
#pragma once
#include "Op.h"
class CSub :
	public COp
{
public:

	CSub()
	{}

	~CSub()
	{}

	COp* create() override;
	double dEval(double d_left, double d_right) override;
	std::string sToString(std::string s_left, std::string s_right) override;
};

inline COp* CSub::create()
{
	return new CSub();
}

inline double CSub::dEval(double d_left, double d_right)
{
	return d_left - d_right;
}

inline std::string CSub::sToString(std::string s_left, std::string s_right)
{
	return "(" + s_left + " - " + s_right + ")";
}


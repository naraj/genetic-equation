#pragma once
#include <string>

class COp
{
public:

	virtual ~COp() {}
	virtual COp* create() = 0;
	virtual double dEval(double d_left, double d_right) = 0;
	virtual std::string sToString(std::string s_left, std::string s_right) const = 0;
};


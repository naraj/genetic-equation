#pragma once
#include <vector>

class CCase
{
	std::vector<double> v_args;
	double d_result;
public:

	CCase(std::vector<double> v_args, double d_result) : v_args(v_args), d_result(d_result)
	{
	}

	~CCase()
	{
	}
	std::vector<double> vGetArgs();
	double dGetResult();
};

inline std::vector<double> CCase::vGetArgs()
{
	return v_args;
}

inline double CCase::dGetResult()
{
	return d_result;
}
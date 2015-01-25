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
};


#pragma once
#include <vector>
#include "Case.h"

class CProblem
{
	std::vector<CCase> v_cases;
	int i_number_of_args;
public:

	CProblem(int i_number_of_args) : i_number_of_args(i_number_of_args)
	{
	}

	~CProblem()
	{
	}

	void vAddCase(CCase c_case)
	{
		v_cases.push_back(c_case);
	}

	const std::vector<CCase>& vGetCases()
	{
		return v_cases;
	}
	
	int iGetNumberOfArgs()
	{
		return i_number_of_args;
	}
};

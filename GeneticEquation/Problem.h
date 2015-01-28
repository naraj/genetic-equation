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

	void vAddCase(const CCase& c_case)
	{
		v_cases.push_back(c_case);
	}

	const std::vector<CCase>& vGetCases() const
	{
		return v_cases;
	}
	
	int iGetNumberOfArgs() const
	{
		return i_number_of_args;
	}
};

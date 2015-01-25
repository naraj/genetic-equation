#pragma once
#include <vector>
#include "Case.h"

class CProblem
{
	std::vector<CCase> v_cases;
public:

	CProblem()
	{
	}

	~CProblem()
	{
	}

	void vAddCase(CCase c_case)
	{
		v_cases.push_back(c_case);
	}

	std::vector<CCase> vGetCases()
	{
		return v_cases;
	}
};

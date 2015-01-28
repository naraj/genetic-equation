#pragma once
#include <vector>
#include "Engine.h"

class CCase
{
	std::vector<double> v_args;
	double d_result;
	CEngine c_engine;
public:

	CCase(std::vector<double> v_args, double d_result) : v_args(v_args), d_result(d_result)
	{
		c_engine = CEngine();
		c_engine.vSetMultipleVariables(v_args);
	}

	~CCase()
	{
	}
	std::vector<double>& vGetArgs();
	double dGetResult() const;
	const CEngine& cGetEngine() const;
};

inline std::vector<double>& CCase::vGetArgs()
{
	return v_args;
}

inline double CCase::dGetResult() const
{
	return d_result;
}

inline const CEngine& CCase::cGetEngine() const
{
	return c_engine;
}
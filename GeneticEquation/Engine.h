#pragma once
#include "AbstrEngine.h"
#include <map>

class CEngine : public CAbstrEngine
{
	mutable std::map<std::string, double > dict;
public:

	CEngine()
	{
	}

	~CEngine()
	{
	}

	double dGetVariable(std::string s_name) const override;
	void vSetVariable(std::string s_name, double d_value) override;
};

inline double CEngine::dGetVariable(const std::string s_name) const
{
	return dict[s_name];
}

inline void CEngine::vSetVariable(std::string s_name, double d_value)
{
	dict[s_name] = d_value;
}
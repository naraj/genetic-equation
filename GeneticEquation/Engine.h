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

	double dGetVariable(const std::string& s_name) const override;
	void vSetVariable(const std::string& s_name, double d_value) override;
	void vSetMultipleVariables(const std::vector<double>& v_args);
};

inline double CEngine::dGetVariable(const std::string& s_name) const
{
	return dict[s_name];
}

inline void CEngine::vSetVariable(const std::string& s_name, double d_value)
{
	dict[s_name] = d_value;
}

inline void CEngine::vSetMultipleVariables(const std::vector<double>& v_args)
{
	std::string names = "abcdefghijklmnopqrstuvwxyz";
	for (size_t i = 0; i < v_args.size(); i++)
	{
		dict[std::string(1, names[names.size() - v_args.size() + i])] = v_args[i];
	}
}
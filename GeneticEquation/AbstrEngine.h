#pragma once
#include <string>

class CAbstrEngine
{
public:

	virtual ~CAbstrEngine(){}

	virtual double dGetVariable(std::string s_name) const = 0;
	virtual void vSetVariable(std::string s_name, double d_value) = 0;
};


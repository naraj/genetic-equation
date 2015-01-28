#pragma once

class CAbstrEngine
{
public:

	virtual ~CAbstrEngine(){}

	virtual double dGetVariable(const std::string& s_name) const = 0;
	virtual void vSetVariable(const std::string& s_name, double d_value) = 0;
};


#pragma once

#include <string>
#include <memory>

class CAbstrEngine;
class COrganism;
class CRandom;

class CNode
{
protected:
	COrganism* c_organism;
public:
	virtual ~CNode(){}
	virtual std::unique_ptr<CNode> create(COrganism*) const = 0;
	virtual std::unique_ptr<CNode> clone() const = 0;
	virtual std::unique_ptr<CNode> move_clone() = 0;
	virtual double dEval(const CAbstrEngine *) const = 0;
	virtual std::string sToString() const = 0;
	virtual bool bIsStatic() const = 0;
	virtual void vMutate() = 0;
	virtual void setPcOrganism(COrganism* c_organism);
	template<typename Derived, typename Base, typename Del>
	std::unique_ptr<Derived, Del>
		static_unique_ptr_cast(std::unique_ptr<Base, Del>&& p);
	template<typename Derived, typename Base, typename Del>
	std::unique_ptr<Derived, Del>
		dynamic_unique_ptr_cast(std::unique_ptr<Base, Del>&& p);
};

inline void CNode::setPcOrganism(COrganism* c_organism)
{
	this->c_organism = c_organism;
}

template<typename Derived, typename Base, typename Del>
std::unique_ptr<Derived, Del>
CNode::static_unique_ptr_cast(std::unique_ptr<Base, Del>&& p)
{
	auto d = static_cast<Derived *>(p.release());
	return std::unique_ptr<Derived, Del>(d, std::move(p.get_deleter()));
}

template<typename Derived, typename Base, typename Del>
std::unique_ptr<Derived, Del>
CNode::dynamic_unique_ptr_cast(std::unique_ptr<Base, Del>&& p)
{
	if (Derived *result = dynamic_cast<Derived *>(p.get())) {
		p.release();
		return std::unique_ptr<Derived, Del>(result, std::move(p.get_deleter()));
	}
	return std::unique_ptr<Derived, Del>(nullptr, p.get_deleter());
}

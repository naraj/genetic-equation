#include "MathOperator.h"
#include "MathValue.h"
#include "Random.h"
#include "Organism.h"
#include <algorithm>

CMathOperator::CMathOperator(COrganism* c_organism)
{
	this->c_organism = c_organism;
	if (c_organism)
	{
		CNodeFactory* p_c_node_factory = this->c_organism->pcGetNodeFactory();
		cLeft = p_c_node_factory->cGetRandomValue();
		cLeft->setPcOrganism(this->c_organism);
		cLeft->vMutate();
		cRight = p_c_node_factory->cGetRandomValue();
		cRight->setPcOrganism(this->c_organism);
		cRight->vMutate();
		cOperator = p_c_node_factory->cGetRandomOperator();
	}
}

CMathOperator::CMathOperator(const CMathOperator& cOther)
{
	cLeft = cOther.cLeft->clone();
	cRight = cOther.cRight->clone();
	cOperator = std::unique_ptr<COp>(cOther.cOperator->create());
	c_organism = cOther.c_organism;
}

CMathOperator::CMathOperator(CMathOperator&& cOther)
{
	cLeft = cOther.cLeft->move_clone();
	cRight = cOther.cRight->move_clone();
	// TODO
	c_organism = std::move(cOther.c_organism);
}

CMathOperator& CMathOperator::operator=(const CMathOperator& cOther)
{
	if (this != &cOther)
	{
		cLeft = cOther.cLeft->clone();
		cRight = cOther.cRight->clone();
		cOperator = std::unique_ptr<COp>(cOther.cOperator->create());
		c_organism = cOther.c_organism;
	}

	return *this;
}

std::unique_ptr<CNode> CMathOperator::create(COrganism* c_organism) const
{
	return std::make_unique<CMathOperator>(c_organism);
}

std::unique_ptr<CNode> CMathOperator::clone() const
{
	return std::make_unique<CMathOperator>(*this);
}

std::unique_ptr<CNode> CMathOperator::move_clone()
{
	return std::make_unique<CMathOperator>(std::move(*this));
}

std::string CMathOperator::sToString() const
{
	return cOperator->sToString(cLeft->sToString(), cRight->sToString());
}

double CMathOperator::dEval(const CAbstrEngine* cEngine) const
{
	return cOperator->dEval(cLeft->dEval(cEngine), cRight->dEval(cEngine));
}

bool CMathOperator::bIsStatic() const
{
	return cLeft->bIsStatic() && cRight->bIsStatic();
}

void CMathOperator::vMutate()
{
	CRandom * c_random = this->c_organism->pcGetRandom();
	// swap
	if (c_random->bChance(100))
	{
		cLeft.swap(cRight);
	}
	// collapse
	if (c_random->bChance(100))
	{
		vCollapse();
	}

	// delete
	if (c_random->bChance(15))
	{
		if (std::unique_ptr<CMathOperator, std::default_delete<CNode> > c_left = dynamic_unique_ptr_cast<CMathOperator, CNode>(std::move(cLeft->clone())))
		{
			std::unique_ptr<CNode> c_grandchild = c_left->cLeft->clone();
			
			cLeft = std::move(c_grandchild);

		}
	}
	// delete
	if (c_random->bChance(15))
	{
		if (std::unique_ptr<CMathOperator, std::default_delete<CNode> > c_left = dynamic_unique_ptr_cast<CMathOperator, CNode>(std::move(cLeft->clone())))
		{
			std::unique_ptr<CNode> c_grandchild = c_left->cRight->clone();

			cLeft = std::move(c_grandchild);
		}
	}
	// delete
	if (c_random->bChance(15))
	{
		if (std::unique_ptr<CMathOperator, std::default_delete<CNode> > c_right = dynamic_unique_ptr_cast<CMathOperator, CNode>(std::move(cRight->clone())))
		{
			std::unique_ptr<CNode> c_grandchild = c_right->cLeft->clone();

			cRight = std::move(c_grandchild);

		}
	}
	// delete
	if (c_random->bChance(15))
	{
		if (std::unique_ptr<CMathOperator, std::default_delete<CNode> > c_right = dynamic_unique_ptr_cast<CMathOperator, CNode>(std::move(cRight->clone())))
		{
			std::unique_ptr<CNode> c_grandchild = c_right->cRight->clone();

			cRight = std::move(c_grandchild);

		}
	}

	// add
	if (c_random->bChance(100))
	{
		std::unique_ptr<CMathOperator> new_op(new CMathOperator(this->c_organism));
		new_op->setLeft(std::move(cLeft));
		cLeft = std::move(new_op);
	}

	// add
	if (c_random->bChance(100))
	{
		std::unique_ptr<CMathOperator> new_op(new CMathOperator(this->c_organism));
		new_op->setLeft(std::move(cRight));
		cRight = std::move(new_op);
	}

	// replace
	if (c_random->bChance(30))
	{
		CNodeFactory* p_c_node_factory = this->c_organism->pcGetNodeFactory();
		std::unique_ptr<CNode> new_node = p_c_node_factory->cGetRandomNode();
		new_node->setPcOrganism(this->c_organism);
		cLeft = std::move(new_node);
	}

	// replace
	if (c_random->bChance(30))
	{
		CNodeFactory* p_c_node_factory = this->c_organism->pcGetNodeFactory();
		std::unique_ptr<CNode> new_node = p_c_node_factory->cGetRandomNode();
		new_node->setPcOrganism(this->c_organism);
		cRight = std::move(new_node);
	}
	cLeft->setPcOrganism(this->c_organism);
	cLeft->vMutate();
	cRight->setPcOrganism(this->c_organism);
	cRight->vMutate();

	if (c_random->bChance(50))
	{
		CNodeFactory* p_c_node_factory = this->c_organism->pcGetNodeFactory();
		std::unique_ptr<COp> new_op = p_c_node_factory->cGetRandomOperator();
		cOperator = std::move(new_op);
	}

}

void CMathOperator::vCollapse()
{
	if (std::unique_ptr<CMathOperator, std::default_delete<CNode> > c_op = dynamic_unique_ptr_cast<CMathOperator, CNode>(std::move(cLeft->clone())))
	{
		c_op->vCollapse();
	}
	if (std::unique_ptr<CMathOperator, std::default_delete<CNode> > c_op = dynamic_unique_ptr_cast<CMathOperator, CNode>(std::move(cRight->clone())))
	{
		c_op->vCollapse();
	}
	if (cLeft->bIsStatic())
	{
		double d_left = cLeft->dEval(nullptr);
		cLeft = std::make_unique<CMathValue>(this->c_organism, d_left);
		
	}
	if (cRight->bIsStatic())
	{
		double d_right = cRight->dEval(nullptr);
		cLeft = std::make_unique<CMathValue>(this->c_organism, d_right);
	}
}

CNode* CMathOperator::pcGetLeft() const
{
	return cLeft.get();
}

CNode* CMathOperator::pcGetRight() const
{
	return cRight.get();
}

void CMathOperator::setLeft(std::unique_ptr<CNode> cLeft)
{
	this->cLeft = std::move(cLeft);
}

void CMathOperator::setRight(std::unique_ptr<CNode> cRight)
{
	this->cRight = std::move(cRight);
}

void CMathOperator::setPcOrganism(COrganism* c_organism)
{
	this->c_organism = c_organism;
	cLeft->setPcOrganism(c_organism);
	cRight->setPcOrganism(c_organism);
}
#pragma once
#include "Unit.h"
#include <string>


class Armorer : public Unit
{
public:
	Armorer(Unit* decorated);

	// Returns the cost for the armorer base class
	virtual int getCost() = 0;
	// Returns the armor value of the base class
	virtual float getArmor() = 0;
	// Returns the damage of the base class
	virtual float getDamage() = 0;

protected:
	// A pointer towards the decorated unit
	Unit* m_decorated;

private:
	float m_health = 100;
};


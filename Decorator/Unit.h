#pragma once
#include <string>
#include <iostream>


class Unit
{
public:
	Unit();
	~Unit();
	// Returns the name of the soldier
	virtual std::string& getName() = 0;
	// Returns the total cost of the soldier
	virtual int getCost() = 0;
	// Returns the current value of the armor
	virtual float getArmor() = 0;
	// Returns the current damage of the soldier
	virtual float getDamage() = 0;
	// Called when the soldier is taking damage
	virtual void takeDamage(float damage);
	// Subrtacts hp based on inputed value from the take damage function
	virtual void setHealth(float value);
	// Returns the current hp of the soldier
	virtual float getHealth();

private:
	float m_health = 100;
};


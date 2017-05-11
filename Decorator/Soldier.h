#pragma once
#include "Unit.h"
#include <string>


class Soldier : public Unit
{
public:
	Soldier();
	~Soldier();

	// Returns the name of the soldier
	std::string& getName() override;
	// Sets the name of the soldier based on the inputed value
	void setName(const std::string& name);
	// Returns the total cost of the soldier
	int getCost() override;
	// Returns the current value of the armor
	float getArmor() override;
	// Returns the current damage of the soldier
	float getDamage() override;
	// Called when the soldier is taking damage
	void takeDamage(float damage) override;
	// Subrtacts hp based on inputed value from the take damage function
	void setHealth(float value) override;
	// Returns the current hp of the soldier
	float getHealth() override;

private:
	std::string m_name = "Default";
	float m_health = 100;

};


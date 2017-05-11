#pragma once
#include "Armorer.h"
#include <string>


class HeavyArmor : public Armorer
{
public:
	HeavyArmor(Unit* decorated);
	~HeavyArmor();

	// Returns the name of the soldier
	std::string& getName() override;
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
	float m_health = 100;
};


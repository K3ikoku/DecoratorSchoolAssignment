#include "HeavyArmor.h"



HeavyArmor::HeavyArmor(Unit* decorated) :
    Armorer(decorated), m_health(100)
{
}


HeavyArmor::~HeavyArmor()
{
}

std::string & HeavyArmor::getName()
{
    // Returns the name of the soldier
    return m_decorated->getName();
}

int HeavyArmor::getCost()
{
    // Adds 25 to the price of the soldier and returns the value
    return m_decorated->getCost() + 25;
}

float HeavyArmor::getArmor()
{
    // Adds 10 to the armor value and returns it
    return m_decorated->getArmor() + 10.0f;
}

float HeavyArmor::getDamage()
{
    // Returns the damage of the soldier
    return m_decorated->getDamage();
}

void HeavyArmor::takeDamage(float damage)
{
    // Calculates the damage left after the armor absorbation has been done
    float m_damage = damage -= getArmor() / 2;
    // Prints out the name of the soldier and the ammount of damage it takes
    std::cout << this->getName() << " took " << damage << " damage." << std::endl;

    setHealth(m_damage);
}

void HeavyArmor::setHealth(float value)
{
    m_health -= value;
}

float HeavyArmor::getHealth()
{
    return m_health;
}

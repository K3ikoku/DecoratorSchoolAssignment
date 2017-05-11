#include "MediumArmor.h"



MediumArmor::MediumArmor(Unit* decorated) :
    Armorer(decorated), m_health(100)
{
}


MediumArmor::~MediumArmor()
{
}

std::string & MediumArmor::getName()
{
    // Returns the name of the soldier
    return m_decorated->getName();
}

int MediumArmor::getCost()
{
    // Adds 15 to the price of the soldier and returns the value
    return m_decorated->getCost() + 15;
}

float MediumArmor::getArmor()
{
    // Adds 6.5 to the armor value and returns it
    return m_decorated->getArmor() + 6.5f;
}

float MediumArmor::getDamage()
{
    // Returns the damage of the soldier
    return m_decorated->getDamage();
}

void MediumArmor::takeDamage(float damage)
{
    // Calculates the damage left after the armor absorbation has been done
    float m_damage = damage -= getArmor() / 2;
    // Prints out the name of the soldier and the ammount of damage it takes
    std::cout << this->getName() << " took " << damage << " damage." << std::endl;

    setHealth(m_damage);
}

void MediumArmor::setHealth(float value)
{
    m_health -= value;
}

float MediumArmor::getHealth()
{
    return m_health;
}

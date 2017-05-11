#include "HeavyAxe.h"



HeavyAxe::HeavyAxe(Unit* decorated):
    Armorer(decorated), m_health(100)
{
}


HeavyAxe::~HeavyAxe()
{
}

std::string & HeavyAxe::getName()
{
    // Returns the name of the soldier
    return m_decorated->getName();
}

int HeavyAxe::getCost()
{
    // Adds 30 to the price of the soldier and returns the value
    return m_decorated->getCost() + 30;
}

float HeavyAxe::getArmor()
{
    // Returns the armor value of the soldier
    return m_decorated->getArmor();
}

float HeavyAxe::getDamage()
{
    // Adds 35 to the damage value and returns it
    return m_decorated->getDamage() + 35.0f;
}


void HeavyAxe::takeDamage(float damage)
{
    // Calculates the damage left after the armor absorbation has been done
    float m_damage = damage -= getArmor() / 2;
    // Prints out the name of the soldier and the ammount of damage it takes
    std::cout << this->getName() << " took " << damage << " damage." << std::endl;

    setHealth(m_damage);
}

void HeavyAxe::setHealth(float value)
{
    m_health -= value;
}

float HeavyAxe::getHealth()
{
    return m_health;
}



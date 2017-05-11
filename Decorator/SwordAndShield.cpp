#include "SwordAndShield.h"



SwordAndShield::SwordAndShield(Unit* decorated) :
    Armorer(decorated), m_health(100)
{
}


SwordAndShield::~SwordAndShield()
{
}

std::string & SwordAndShield::getName()
{
    // Returns the name of the soldier
    return m_decorated->getName();
}

int SwordAndShield::getCost()
{
    // Adds 30 to the price of the soldier and returns the value
    return m_decorated->getCost() + 30;
}

float SwordAndShield::getArmor()
{
    // Adds 7 to the armor value and returns it
    return m_decorated->getArmor() + 7.0f;
}

float SwordAndShield::getDamage()
{
    // Adds 15 to the damage value and returns it
    return m_decorated->getDamage() + 15.0f;
}

void SwordAndShield::takeDamage(float damage)
{
    // Calculates the damage left after the armor absorbation has been done
    float m_damage = damage -= getArmor() / 2;
    // Prints out the name of the soldier and the ammount of damage it takes
    std::cout << this->getName() << " took " << damage << " damage." << std::endl;

    setHealth(m_damage);
}

void SwordAndShield::setHealth(float value)
{
    m_health -= value;
}

float SwordAndShield::getHealth()
{
    return m_health;
}



#include "Crossbow.h"



Crossbow::Crossbow(Unit* decorated) :
    Armorer(decorated), m_health(100)
{
}


Crossbow::~Crossbow()
{
}

std::string & Crossbow::getName()
{
    // Returns the name of the soldier
    return m_decorated->getName();
}

int Crossbow::getCost()
{
    // Adds 20 to the price of the soldier and returns the value
    return m_decorated->getCost() + 20;
}

float Crossbow::getArmor()
{
    // Returns the armor value of the soldier
    return m_decorated->getArmor();
}

float Crossbow::getDamage()
{
    // Adds 17.5 to the damage value and returns it
    return m_decorated->getDamage() + 17.5f;
}

void Crossbow::takeDamage(float damage)
{
    // Calculates the damage left after the armor absorbation has been done
    float m_damage = damage -= getArmor() / 2;
    // Prints out the name of the soldier and the ammount of damage it takes
    std::cout << this->getName() << " took " << damage << " damage." << std::endl;

    setHealth(m_damage);
}

void Crossbow::setHealth(float value)
{
    m_health -= value;
}

float Crossbow::getHealth()
{
    return m_health;
}
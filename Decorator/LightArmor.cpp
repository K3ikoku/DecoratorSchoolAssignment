#include "LightArmor.h"



LightArmor::LightArmor(Unit* decorated) :
    Armorer(decorated), m_health(100)
{
}


LightArmor::~LightArmor()
{
}

std::string& LightArmor::getName()
{
    // Returns the name of the soldier
    return m_decorated->getName();
}

int LightArmor::getCost()
{
    // Adds 8 to the price of the soldier and returns the value
    return m_decorated->getCost() + 8;
}

float LightArmor::getArmor()
{
    // Adds 4 to the armor value and returns it
    return m_decorated->getArmor() + 4.0f;
}

float LightArmor::getDamage()
{
    // Returns the damage of the soldier
    return m_decorated->getDamage();
}


void LightArmor::takeDamage(float damage)
{
    // Calculates the damage left after the armor absorbation has been done
    float m_damage = damage -= getArmor() / 2;
    // Prints out the name of the soldier and the ammount of damage it takes
    std::cout << this->getName() << " took " << damage << " damage." << std::endl;

    setHealth(m_damage);
}

void LightArmor::setHealth(float value)
{
    m_health -= value;
}

float LightArmor::getHealth()
{
    return m_health;
}



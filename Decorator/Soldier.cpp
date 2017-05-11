#include "Soldier.h"



Soldier::Soldier():
    m_health(100)
{
}


Soldier::~Soldier()
{
}

std::string& Soldier::getName()
{
    // Returns the name of the soldier
    return m_name;
}

void Soldier::setName(const std::string& name)
{
    // Sets the name of the soldier to inputed value
    m_name = name;
}

int Soldier::getCost()
{
    // Set the base cost for the soldier to 15 and returns the value
    return 15;
}

float Soldier::getArmor()
{
    // Set the base cost for the soldiers armor to 5 and returns the value
    return 5.0f;
}

float Soldier::getDamage()
{
    // Set the base cost for the soldiers damage to 5 and returns the value
    return 5.0f;
}

void Soldier::takeDamage(float damage)
{
    // Prints out the name of the soldier and the ammount of damage it takes
    float m_damage = damage -= getArmor() / 2;
    // Calculates the damage left after the armor absorbation has been done
    std::cout << this->getName() << " took " << damage << " damage." << std::endl;

    setHealth(m_damage);
}

void Soldier::setHealth(float value)
{
    m_health -= value;
}

float Soldier::getHealth()
{
    return m_health;
}

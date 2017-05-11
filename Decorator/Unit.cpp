#include "Unit.h"



Unit::Unit()
{
}


Unit::~Unit()
{
}



void Unit::takeDamage(float damage)
{

    // Calculates the damage left after the armor absorbation has been done
    float m_damage = damage -= getArmor() / 2;
    // Prints out the name of the soldier and the ammount of damage it takes
    std::cout << this->getName() << " took " << damage << " damage." << std::endl;

    setHealth(m_damage);
}

void Unit::setHealth(float value)
{
    m_health -= value;
}

float Unit::getHealth()
{
    return m_health;
}


#include "Regiment.h"



Regiment::Regiment() :
    m_budget(500)
{
}


Regiment::~Regiment()
{
}

void Regiment::setArmyName(const std::string name)
{
    this->m_armyName = name;
}

std::string & Regiment::getArmyName()
{
    return this->m_armyName;
}

int Regiment::getBudget()
{
    return this->m_budget;
}

void Regiment::setBudget(int value)
{
    this->m_budget -= value;
}

void Regiment::SoldierCreator(const std::string& name, const Regiment::Armor armor, const Regiment::Weapon weapon)
{
    // Creates a new soldier and sets it name to inputed name
    Soldier* soldier = new Soldier();
    soldier->setName(name);
    // Saves the soldier as the latest change and if no other changes are made puts it in the regiment vector
    Unit* m_latestChange = soldier;

    // Sets the armor to the inputed armor and saves it to the latest change of the soldier
    m_armor = Dress(m_latestChange, armor);
    if (m_armor != nullptr)
        m_latestChange = m_armor;
    // Sets the weapon to the inputed weapon and saves it to the latest change of the soldier
    m_weapon = Arm(m_latestChange, weapon);
    if (m_weapon != nullptr)
        m_latestChange = m_weapon;

    // Puts the latest change in the back of the regiment
    m_regiment.push_back(m_latestChange);

    std::cout << m_latestChange->getName() << " has been trained." << std::endl;

    // Subtract the cost of the soldier created to the army budget
    this->setBudget(m_latestChange->getCost());

}

Armorer* Regiment::Dress(Unit* unit, const Regiment::Armor armor)
{
    // Sets all armor variables to null to prevent errors
    LightArmor* lightArmor = nullptr;
    MediumArmor* mediumArmor = nullptr;
    HeavyArmor* heavyArmor = nullptr;

    // Check the inputed armor and returns it to the decorator
    switch (armor)
    {
    case Light:
        lightArmor = new LightArmor(unit);
        return lightArmor;

    case Medium:
        mediumArmor = new MediumArmor(unit);
        return mediumArmor;

    case Heavy:
        heavyArmor = new HeavyArmor(unit);
        return heavyArmor;

    default:
        return nullptr;
    }
}

Armorer * Regiment::Arm(Unit * unit, const Regiment::Weapon weapon)
{
    // Sets all weapon variables to null to prevent errors
    Crossbow* ranged = nullptr;
    SwordAndShield* sword = nullptr;
    HeavyAxe* axe = nullptr;

    // Check the inputed weapon and returns it to the decorator
    switch (weapon)
    {
    case Ranged:
        ranged = new Crossbow(unit);
        return ranged;

    case Sword:
        sword = new SwordAndShield(unit);
        return sword;

    case Axe:
        axe = new HeavyAxe(unit);
        return axe;

    default:
        return nullptr;
    }
}

void Regiment::Attack(Regiment targetRegiment)
{
    // Every unit in the regiment attack a random target in the target regiment
    for (Unit* unit : m_regiment)
    {
        int m_pos = rand() % targetRegiment.m_regiment.size();

        m_enemyToAttack = targetRegiment.m_regiment[m_pos];
        if (m_enemyToAttack == nullptr)
            printf("Enemy is null");
        m_enemyToAttack->takeDamage(unit->getDamage());

        if (m_enemyToAttack->getHealth() <= 0)
            targetRegiment.SoldierDied(m_pos);
    }
}



void Regiment::SoldierDied(int index)
{
    Unit* m_soldier = m_regiment.at(index);
    std::cout << m_soldier->getName() << " has beem slain in battle." << std::endl;

    this->m_regiment.erase(m_regiment.begin() + index);
}

bool Regiment::RegimentDestroyed()
{
    if (m_regiment.size() <= 0)
        return true;

    return false;
}

void Regiment::Clear()
{
    this->m_regiment.clear();
}


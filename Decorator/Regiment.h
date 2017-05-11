#pragma once
#include "Unit.h"
#include "Armorer.h"
#include "Soldier.h"

#include "HeavyArmor.h"
#include "MediumArmor.h"
#include "LightArmor.h"

#include "HeavyAxe.h"
#include "Crossbow.h"
#include "SwordAndShield.h"

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <time.h>


class Regiment
{
public:
    // Enums used for decorating the soldiers
    enum Armor { Light, Medium, Heavy, NullArmor };
    enum Weapon { Ranged, Sword, Axe, NullWeapon };
    Regiment();
    ~Regiment();
    // Sets this armys name to inputed value
    void setArmyName(const std::string name);
    // Returns this armys name
    std::string& getArmyName();

    // Returns this armys budget
    int getBudget();
    // Subtracts this armys budget by inserted ammount
    void setBudget(int value);

    // Creates a soldier and decorates it with desired armor or weapon
    void SoldierCreator(const std::string& name, const Regiment::Armor armor, const Regiment::Weapon weapon);

    // Attacks a random unit within the target regiment.
    void Attack(Regiment targetRegiment);

    // Removes the soldier from the regiment vector
    void SoldierDied(int index);

    bool RegimentDestroyed();

    void Clear();

    // A vector holding the soldiers of the army
    std::vector<Unit*> m_regiment;

private:
    Armorer* m_armor;
    Armorer* m_weapon;
    int m_budget;
    std::string m_armyName = "Default";
    Unit* m_enemyToAttack;

    Armorer* Dress(Unit* unit, const Regiment::Armor armor);
    Armorer* Arm(Unit* unit, const Regiment::Weapon weapon);

};


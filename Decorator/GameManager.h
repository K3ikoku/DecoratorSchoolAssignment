#pragma once
#include "Regiment.h"
#include <stdio.h>
#include <time.h>
#include <iostream>

class GameManager
{
public:
    GameManager();
    ~GameManager();

    void GameLoop();

    void CreatePlayerArmy();
    void CreateEnemyArmy();

    // Starts the character creation loop for desired regiment
    void characterCreationInput(Regiment player);


private:
    Regiment* m_player;
    Regiment* m_enemy;
    std::string m_name;
    Regiment::Armor m_armorType;
    Regiment::Weapon m_weaponType;
    std::string m_continue;

    std::string m_playAgain;
};


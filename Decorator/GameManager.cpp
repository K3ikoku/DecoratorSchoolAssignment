#include "GameManager.h"




GameManager::GameManager() :
    m_continue("y"),
    m_playAgain("y")
{

}


GameManager::~GameManager()
{
}

void GameManager::GameLoop()
{
    //Initiate the game loop
    while (m_playAgain == "y")
    {
        m_player = new Regiment();
        m_enemy = new Regiment();

        printf("The game loop started\n");
        std::cout << "\nPlease enter the name of your army: " << std::endl;
        //Enter the name for your army
        std::cin >> m_name;
        m_enemy->setArmyName("Derp");

        //Start the player character creations loop
        while (m_continue == "y")
        {
            GameManager::characterCreationInput(*m_player);

            std::cout << "\nDo you want to train another soldier? Write y if you do " << std::endl;
            std::cin >> m_continue;
        }



        // Temporary creates soldiers for the enemy army
        m_enemy->SoldierCreator("Mange", m_enemy->Light, m_enemy->Ranged);

        m_enemy->SoldierCreator("Anders", m_enemy->Light, m_enemy->Ranged);

        m_enemy->SoldierCreator("Lars", m_enemy->Light, m_enemy->Ranged);

        while (m_player->RegimentDestroyed() == false || !m_enemy->RegimentDestroyed() == false)
            m_player->Attack(*m_enemy);

        if (m_player->RegimentDestroyed())
            std::cout << "Your army has been destroyed better luck next time" << std::endl;

        else
            std::cout << "Congratulations you defeted your enemy!" << std::endl;


        std::cout << "\nDo you want to play again? y/n:" << std::endl;
        std::cin >> m_playAgain;
        m_player->Clear();
        m_enemy->Clear();
        m_continue = "y";
    }
}


void GameManager::CreatePlayerArmy()
{
}

void GameManager::CreateEnemyArmy()
{
}

void GameManager::characterCreationInput(Regiment player)
{
    // Ask the player for the desired name of the new soldier and print it out
    std::cout << "\nPlease enter the name of the soldier you wish to train\n";
    std::cin >> m_name;
    std::cout << "\nYour soldiers name is: " + m_name << std::endl;

    int m_inputInt = 0;

    // Asks the player for the desired armor for the newly created soldier and adds it to the decorator

    std::cout << "\nPlease enter your desired armor\n" << "Write 1 for light armor, 2 for medium armor, 3 for heavy armor or 4 for no armor" << std::endl;
    std::cin >> m_inputInt;

    while (1 > m_inputInt || 4 < m_inputInt)
    {
        std::cout << "\nYou entered a incorrect value please choose a nr between 1-4" << std::endl;
        std::cin >> m_inputInt;
    }

    switch (m_inputInt)
    {
    case 1:
        m_armorType = m_player->Light;
        std::cout << "\nYou chose light armor" << std::endl;
        break;
    case 2:
        m_armorType = m_player->Medium;
        std::cout << "\nYou chose medium armor" << std::endl;
        break;
    case 3:
        m_armorType = m_player->Heavy;
        std::cout << "\nYou chose heavy armor" << std::endl;
    case 4:
        player.SoldierCreator(m_name, m_player->NullArmor, m_player->NullWeapon);
        break;
    }
    m_inputInt = 0;

    // Asks the player for the desired weapon for the newly created soldier and adds it to the decorator
    std::cout << "\nPlease enter your desired weapon\n" << "Write 1 for ranged weapon, 2 for sword and shield, 3 for heavy axe or 4 for no weapon" << std::endl;
    std::cin >> m_inputInt;

    while (1 > m_inputInt || 4 < m_inputInt)
    {
        std::cout << "\nYou entered a incorrect value please choose a nr between 1-4" << std::endl;
        std::cin >> m_inputInt;
    }

    switch (m_inputInt)
    {
    case 1:
        m_weaponType = m_player->Ranged;
        std::cout << "\nYou chose ranged weapon" << std::endl;
        break;
    case 2:
        m_weaponType = m_player->Sword;
        std::cout << "\nYou chose sword and shield" << std::endl;
        break;
    case 3:
        m_weaponType = m_player->Axe;
        std::cout << "\nYou chose heavy axe" << std::endl;
    case 4:
        player.SoldierCreator(m_name, m_armorType, m_player->NullWeapon);
        break;
    }

    player.SoldierCreator(m_name, m_armorType, m_weaponType);
    std::cout << "\nYou have: " << player.getBudget() << " left";
}


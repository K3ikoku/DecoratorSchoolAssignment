#pragma once
#include "GameManager.h"
#include <time.h>


int main()
{
	//Initiate seed for the random numbers used later
	srand(time(NULL));


	GameManager* game = new GameManager();
	//Start the game loop
	game->GameLoop();

	return 0;
}
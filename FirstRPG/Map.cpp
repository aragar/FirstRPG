#include "Map.h"
#include "Random.h"

#include <iostream>

Map::Map()
{
	// Player starts at origin (0, 0).
	mPlayerXPos = 0;
	mPLayerYPos = 0;
}

int Map::getPlayerXPos()
{
	return mPlayerXPos;
}

int Map::getPlayerYPos()
{
	return mPLayerYPos;
}

void Map::movePlayer()
{
	int selection = 1;
	std::cout << "1) North, 2) East, 3) South, 4) West: ";
	std::cin >> selection;

	// Update coordinates based on selection.
	switch (selection)
	{
	case 1: // North
		++mPLayerYPos;
		break;
	case 2: // East
		++mPlayerXPos;
		break;
	case 3: // South
		--mPLayerYPos;
		break;
	default: // West
		--mPlayerXPos;
		break;
	}
}

Monster* Map::checkRandomEncounter()
{
	int row = Random(0, 20);
	Monster* monster = 0;

	if (row >= 6 && row <= 10)
	{
		Range orcRange = {100, 200};
		monster = new Monster("Orc", 10, 8, 200, orcRange, 1, "Short Sword", 2, 7);

		std::cout << "You encountered an Orc!" << std::endl;
		std::cout << "Prepare for battle!" << std::endl;
		std::cout << std::endl;
	}
	else if (row >= 11 && row <= 15)
	{
		Range goblinRange = {0, 100};
		monster = new Monster("Goblin", 6, 6, 100, goblinRange, 0, "Dagger", 1, 5);

		std::cout << "You encountered a Goblin!" << std::endl;
		std::cout << "Prepare for battle!" << std::endl;
		std::cout << std::endl;
	}
	else if (row >= 16 && row <= 19)
	{
		Range ogreRange = {200, 300};
		monster = new Monster("Ogre", 20, 12, 500, ogreRange, 2, "Club", 3, 8);

		std::cout << "You encountered an Ogre!" << std::endl;
		std::cout << "Prepare for battle!" << std::endl;
		std::cout << std::endl;
	}
	else if (row == 20)
	{
		Range orcLordRange = {300, 500};
		monster = new Monster("Orc Lord", 25, 15, 2000, orcLordRange, 5, "Two Handed Sword", 5, 20);

		std::cout << "You encountered an Orc Lord!!!" << std::endl;
		std::cout << "Prepare for battle!" << std::endl;
		std::cout << std::endl;
	}

	return monster;
}

void Map::printPlayerPos()
{
	std::cout << "Player Position = (" << mPlayerXPos << ", " << mPLayerYPos 
		<< ")" << std::endl << std::endl;
}
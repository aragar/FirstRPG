#include "Map.h"
#include "Player.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
	srand((unsigned int) time(0));

	Map gameMap;
	Player mainPlayer;

	mainPlayer.createClass();

	// Begin adventure.
	bool done = false;
	while (!done)
	{
		// Each loop cycle we output the player position and a selection menu.
		gameMap.printPlayerPos();

		int selection = 1;
		std::cout << "1) Move, 2) Rest, 3) View Stats, 4) Quit: ";
		std::cin >> selection;

		Monster* monster = 0;
		switch (selection)
		{
		case 1: 
			// Move the player.
			gameMap.movePlayer();

			// Check for a random encounter. This function returns a null pointer if no
			// monsters are encountered.
			monster = gameMap.checkRandomEncounter();

			// If 'monster' not null, run combat simulation.
			if (monster != 0)
			{
				// Loop until a 'break' statement.
				while (true)
				{
					// Displaye hitpoints.
					mainPlayer.displayHitPoints();
					monster->displayHitPoints();
					std::cout << std::endl;

					// Player's turn to attach first.
					bool runAway = mainPlayer.attack(*monster);

					if (runAway)
						break;

					if (monster->isDead())
					{
						mainPlayer.victory(monster->getXPReward());
						mainPlayer.levelUp();
						break;
					}

					monster->attack(mainPlayer);

					if (mainPlayer.isDead())
					{
						mainPlayer.gameover();
						done = true;
						break;
					}
				}

				// The pointer to a monster returned from checkRandomEncounter 
				// was allocated with 'new', so we must delete it to avoid
				// memory leaks.
				delete monster;
				monster = 0;
			}

			break;
		case 2:
			mainPlayer.rest();
			break;
		case 3:
			mainPlayer.viewStat();
			break;
		case 4:
			done = true;
			break;
		}
	}
}
#include "GameManager.h"
#include <vector>
#include <string>
#include <iostream>
#include "CommandExecuter.h"
#include "WorldManager.h"
#include "Player.h"

using namespace std;

void GameManager::StartGame()
{
	bool playing = true;
	WorldManager wm;
	wm.InitializeRooms();
	Player player = Player(wm.startRoom, wm.buildingRoom, wm.xyzzyTpRoom, wm.plughTpRoom);
	CommandExecuter ce;

	cout << "Welcome to Colossal cave adventure!!" << endl << endl;
	cout << "Would you like instructions?" << endl;

	string inst;

	while (true)
	{
		cout << ">> ";
		getline(cin, inst);

		if (inst == "y" || inst == "yes")
		{
			cout << "Somewhere nearby is Colossal Cave, where others have found fortunes in treasure and gold, though it is rumored that some who enter are never seen again. Magic is said to work in the cave. I will be your eyes and hands. Direct me with commands of 1 or 2 words." << endl;
			break;
		}
		else if (inst == "n" || inst == "no")
		{
			break;
		}
		else
		{
			cout << "Please answer yes or no" << endl;
		}
	}

	cout << endl;
	player.currentRoom->PrintInfo();

	while (player.isPlaying)
	{
		string input;
		cout << ">> ";
		getline(cin, input);

		if (input != "")
		{
			cout << endl;
			ce.ExecuteCommand(player, input);
		}

		if (player.score == goalScore)
		{
			player.isPlaying = false;
			cout << "Congratulations, you won!" << endl;
		}

	}

	cout << "Thanks for playing!" << endl;
}

#ifndef PLAYER_H
#define PLAYER_H

#include "InventorySystem.h"
#include "Room.h"
#include "Words.h"
#include "MovementSystem.h"
#include "ItemSystem.h"

using namespace Words;

using namespace std;

class Player
{
public:
	InventorySystem inventory;
	Room* currentRoom;
	Room* goalRoom;
	Room* xyzzyRoom;
	Room* plughRoom;
	bool hasLight;
	bool isPlaying;
	int score = 0;
	int deathTurns = 0;

	MovementSystem movementSystem;
	ItemSystem itemSystem;

	Player(Room* currentRoom, Room* goalRoom, Room* xyzzyRoom, Room* plughRoom);
};

#endif
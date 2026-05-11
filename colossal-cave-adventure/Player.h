#ifndef PLAYER_H
#define PLAYER_H

#include "InventorySystem.h"
#include "Room.h"

using namespace std;

class Player
{
public:
	InventorySystem inventory;
	Room currentRoom;
	bool hasLight;

	Player(Room currentRoom);
};

#endif
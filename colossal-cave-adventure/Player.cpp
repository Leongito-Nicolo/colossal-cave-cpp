#include "Player.h"
#include <iostream>

Player::Player(Room currentRoom)
{
	Player::inventory = InventorySystem();
	Player::currentRoom = currentRoom;
	Player::hasLight = false;
}
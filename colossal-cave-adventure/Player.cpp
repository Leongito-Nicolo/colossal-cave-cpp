#include "Player.h"
#include <iostream>

Player::Player(Room* currentRoom, Room* goalRoom, Room* xyzzyRoom, Room* plughRoom)
{
	this->inventory = InventorySystem();
	this->currentRoom = currentRoom;
	this->goalRoom = goalRoom;
	this->xyzzyRoom = xyzzyRoom;
	this->plughRoom = plughRoom;
	this->hasLight = false;
	this->isPlaying = true;
}
#include <vector>
#include <string>
#include <iostream>

#include "Player.h"
#include "Room.h"
#include "CommandParser.h"
#include "GameManager.h"

using namespace std;

int main()
{
	//Item keys = Item(0, "Key", "A set of keys");			//KeyItem
	//Item lantern = Item(1, "Lantern", "A lantern");			//ToolItem
	//Item bottle = Item(2, "Bottle", "A bottle of water");	//PuzzleItem
	//Item food = Item(3, "Food", "Some food");				//ToolItem

	GameManager game;
	game.StartGame();

}
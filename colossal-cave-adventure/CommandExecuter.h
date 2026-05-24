#pragma once
#include "CommandInterpreter.h"
#include "Player.h"

class CommandExecuter
{
	CommandInterpreter interpreter;

public:
	void ExecuteCommand(Player& p, const string& input);	// & reference to the player, without is just a copy
	void Unknown();
};


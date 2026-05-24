#include "Blocker.h"
#include <iostream>

using namespace Words;

Blocker::Blocker(string description, string blockMessage, string openMessage, Obstacle obsType, vector<Direction> directionsBlocked)
{
	this->description = description;
	this->blockMessage = blockMessage;
	this->openMessage = openMessage;
	this->obsType = obsType;
	this->directionsBlocked = directionsBlocked;
	isActive = true;
}

void Blocker::PrintInfo()
{
	if (description != "")
	{
		cout << description << endl;
	}
}

void Blocker::PrintBlockMessage()
{
	cout << "You cannot proceed, " << blockMessage << endl;
}

void Blocker::PrintOpenMessage()
{
	cout << openMessage << endl;
}

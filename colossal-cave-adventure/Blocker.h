#pragma once
#include "Words.h"
#include <string>
#include <vector>

using namespace std;
using namespace Words;

class Blocker
{
public:
	Obstacle obsType;
	string description;
	string blockMessage;
	string openMessage;
	vector<Direction> directionsBlocked;
	bool isActive;

	Blocker(string description, string blockMessage, string openMessage, Obstacle obsType, vector<Direction> directionsBlocked);
	void PrintInfo();
	void PrintBlockMessage();
	void PrintOpenMessage();
};


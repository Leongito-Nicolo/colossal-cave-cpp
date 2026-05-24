#pragma once
#include "Words.h"
using namespace Words;


class Player;
class Room;

class MovementSystem
{
public:
	void MoveTo(Player& p, Direction dir);
	void Teleport(Player& p, Room* room);
	void Enter(Player& p);
	void Exit(Player& p);
};
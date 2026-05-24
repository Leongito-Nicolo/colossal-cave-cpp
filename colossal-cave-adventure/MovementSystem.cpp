#include "MovementSystem.h"
#include "Player.h"
#include <iostream>


void MovementSystem::MoveTo(Player& p, Direction dir)
{
	switch (dir)
	{
	case Direction::NONE:
		cout << "Where are you trying to go?" << endl;
		break;
	default:
		if (p.currentRoom->obstacle != nullptr && p.currentRoom->obstacle->isActive)
		{
			for (auto& blocked : p.currentRoom->obstacle->directionsBlocked)
			{
				if (blocked == dir)
				{
					p.currentRoom->obstacle->PrintBlockMessage();
					return;
				}
			}
		}

		if (p.currentRoom->connections[int(dir)] != nullptr)
		{
			if (p.currentRoom->isDark && !p.hasLight)
			{
				p.deathTurns++;
				if (p.deathTurns == 2)
				{
					cout << "You fell into a pit and broke every bone in your body!" << endl;
					p.isPlaying = false;
					return;
				}
				else
				{
					p.currentRoom = p.currentRoom->connections[int(dir)];
					cout << "It is now pitch dark. If you proceed you will likely fall into a pit." << endl;
					return;
				}
			}

			p.currentRoom = p.currentRoom->connections[int(dir)];
			p.currentRoom->PrintInfo();
		}
		else
		{
			cout << "You can't go that way!" << endl;
		}
		break;
	}
}

void MovementSystem::Teleport(Player& p, Room* room)
{
	if (p.currentRoom == room)
	{
		cout << "POOF!" << endl;
		p.currentRoom = p.goalRoom;
		p.currentRoom->PrintInfo();
	}
	else if (p.currentRoom == p.goalRoom)
	{
		cout << "POOF!" << endl;
		p.currentRoom = room;
		p.currentRoom->PrintInfo();
	}
	else
	{
		cout << "Nothing happens." << endl;
	}
}

void MovementSystem::Enter(Player& p)
{
	Direction dir = p.currentRoom->enterDirection;
	if (dir != Direction::NONE)
	{
		MoveTo(p, dir);
		return;
	}

	cout << "I don't know in from out here. Use compass points to tell where you want to go." << endl;
}

void MovementSystem::Exit(Player& p)
{
	Direction dir = p.currentRoom->exitDirection;
	if (dir != Direction::NONE)
	{
		MoveTo(p, dir);
		return;
	}

	cout << "I don't know in from here. Use compass points to tell where you want to go." << endl;
}

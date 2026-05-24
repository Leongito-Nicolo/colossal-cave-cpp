#include "CommandExecuter.h"


void CommandExecuter::ExecuteCommand(Player& p, const string& input)
{
	Command command = interpreter.InterpretCommand(input);

	Direction dir = Direction::NONE;
	Object obj = Object::NONE;
	Obstacle obs = Obstacle::NONE;

	if (std::holds_alternative<Direction>(command.arg))
		dir = std::get<Direction>(command.arg);
	else if (std::holds_alternative<Object>(command.arg))
		obj = std::get<Object>(command.arg);
	else if (std::holds_alternative<Obstacle>(command.arg))
		obs = std::get<Obstacle>(command.arg);

	if (obs == Obstacle::UNKNOWN)
	{
		dir = Direction::UNKNOWN;
		obj = Object::UNKNOWN;
		obs = Obstacle::UNKNOWN;
	}

	switch (command.action)
	{
	case Action::GO:
		if (dir == Direction::UNKNOWN) break;
		p.movementSystem.MoveTo(p, dir);
		break;
	case Action::TAKE:
		if (obj == Object::UNKNOWN) break;
		p.itemSystem.TakeItem(p, obj);
		break;
	case Action::LEAVE:
		if (obj == Object::UNKNOWN) break;
		p.itemSystem.TossItem(p, obj);
		break;
	case Action::LOOK:
		p.currentRoom->PrintInfo();
		break;
	case Action::INVENTORY:
		p.inventory.ShowInventory();
		break;
	case Action::ENTER:
		if (dir != Direction::NONE && obj != Object::NONE && obs != Obstacle::NONE) break;
		p.movementSystem.Enter(p);
		break;

	case Action::EXIT:
		if (dir != Direction::NONE && obj != Object::NONE && obs != Obstacle::NONE) break;
		p.movementSystem.Exit(p);
		break;

	case Action::OPEN:
		if (obs == Obstacle::UNKNOWN) break;
		p.itemSystem.Unlock(p, obs);
		break;

	case Action::SWING:
		if (obj == Object::UNKNOWN) break;
		p.itemSystem.Swing(p, obj);
		break;

	case Action::KILL:
		if (obj == Object::UNKNOWN) break;
		p.itemSystem.Kill(p, obj);
		break;

	case Action::LIGHT:
		if (obj == Object::UNKNOWN) break;
		p.itemSystem.Light(p, obj);
		break;

	case Action::FREE:
		if (obj == Object::UNKNOWN) break;
		p.itemSystem.Free(p, obj);
		break;

	case Action::POUR:
		if (obj == Object::UNKNOWN) break;
		p.itemSystem.Pour(p, obj);
		break;

	case Action::XYZZY:
		p.movementSystem.Teleport(p, p.xyzzyRoom);
		break;

	case Action::PLUGH:
		p.movementSystem.Teleport(p, p.plughRoom);
		break;

	case Action::QUIT:
		p.isPlaying = false;
		break;
	default:
		Unknown();
		break;
	}
}

void CommandExecuter::Unknown()
{
	cout << "Huh??" << endl;
}


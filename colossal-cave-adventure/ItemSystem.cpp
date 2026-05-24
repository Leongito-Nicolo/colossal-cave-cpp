#include "ItemSystem.h"
#include "Player.h"
#include <iostream>
using namespace std;

bool ItemSystem::UseItemFromInventory(Player& p, Object obj)
{
	Item* item = p.inventory.GetItem(obj);
	if (item == nullptr)
	{
		cout << "How?" << endl;
		return false;
	}

	item->Use(p.currentRoom);
	return true;

}

void ItemSystem::TryAddItem(Player& p, Object obj)
{
	Item* item = p.currentRoom->FindItem(obj);
	if (item != nullptr)
	{

		if (p.inventory.AddToInventory(item))
		{
			p.currentRoom->RemoveItem(item);
			cout << "Ok." << endl;

			if (p.currentRoom == p.goalRoom)
			{
				item->DecreaseObjective(&p);
			}

		}

		return;
	}

	cout << "It's not here." << endl;
}

bool ItemSystem::TryTossItem(Player& p, Object obj)
{
	Item* item = p.inventory.GetItem(obj);
	if (item != nullptr)
	{
		p.currentRoom->AddItem(item);
		p.inventory.RemoveFromInventory(item);
		cout << "Ok." << endl;

		if (p.currentRoom == p.goalRoom)
			item->IncreaseObjective(&p);

		return true;
	}

	cout << "You aren't carrying it." << endl;
	return false;
}

void ItemSystem::TryLight(Player& p, Object obj)
{
	Item* item = p.inventory.GetItem(obj);
	if (item != nullptr)
	{
		p.hasLight = true;
		p.deathTurns = 0;
		cout << "Your lamp is now on!" << endl;
		return;
	}

	cout << "You have no source of light." << endl;
}

void ItemSystem::TakeItem(Player& p, Object obj)
{
	switch (obj)
	{
	case Object::NONE:
		cout << "What are you trying to get?" << endl;
		break;

	case Object::BIRD:
	{
		Item* cage = p.inventory.GetItem(Object::CAGE);
		if (cage == nullptr)
		{
			cout << "You might be able to catch the bird, but you could not carry it." << endl;
			break;
		}
		Item* rod = p.inventory.GetItem(Object::ROD);
		if (rod != nullptr)
		{
			cout << "The bird was unafraid when you entered, but as you approach it becomes disturbed and you cannot catch it." << endl;
			break;
		}
		TryAddItem(p, obj);
		break;
	}

	case Object::WATER:
	{
		Item* cage = p.inventory.GetItem(Object::BOTTLE);
		if (cage == nullptr)
		{
			cout << "How? You don't have a container." << endl;
			break;
		}

		TryAddItem(p, obj);
		break;
	}

	default:
		TryAddItem(p, obj);
		break;
	}
}

void ItemSystem::TossItem(Player& p, Object obj)
{
	switch (obj)
	{
	case Object::NONE:
		cout << "What are you trying to get rid of?" << endl;
		break;

	case Object::LAMP:
		if (TryTossItem(p, obj))
			p.hasLight = false;
		break;

	default:
		TryTossItem(p, obj);
		break;
	}
}

void ItemSystem::Swing(Player& p, Object obj)
{
	switch (obj)
	{
	case Object::ROD:
		UseItemFromInventory(p, Object::ROD);
		break;
	case Object::NONE:
		cout << "What are you trying to swing?" << endl;
		break;
	default:
		cout << "Don't be ridiculous!" << endl;
		break;
	}
}

void ItemSystem::Kill(Player& p, Object obj)
{
	switch (obj)
	{
	case Object::BIRD:
	{
		Item* item = p.currentRoom->FindItem(obj);
		if (item != nullptr)
		{
			cout << "You killed the bird. You happy now? Monster." << endl;
			p.currentRoom->RemoveItem(item);
			delete item;
			break;
		}
		cout << "I see no bird here." << endl;
		break;
	}
	case Object::NONE:
		cout << "Kill what?" << endl;
		break;
	default:
		cout << "Don't be ridiculous!" << endl;
		break;
	}
}

void ItemSystem::Light(Player& p, Object obj)
{
	switch (obj)
	{
	case Object::LAMP:
		TryLight(p, obj);
		break;
	case Object::NONE:
		TryLight(p, Object::LAMP);
		break;
	default:
		cout << "Don't be ridiculous!" << endl;
		break;
	}
}

void ItemSystem::Unlock(Player& p, Obstacle obs)
{
	switch (obs)
	{
	case Obstacle::GATE:
		UseItemFromInventory(p, Object::KEYS);
		break;
	case Obstacle::NONE:
		UseItemFromInventory(p, Object::KEYS);
		break;
	default:
		cout << "Don't be ridiculous!" << endl;
		break;
	}

}

void ItemSystem::Free(Player& p, Object obj)
{
	switch (obj)
	{
	case Object::BIRD:
		UseItemFromInventory(p, Object::BIRD);
		break;
	default:
		cout << "Don't be ridiculous!" << endl;
		break;
	}
}

void ItemSystem::Pour(Player& p, Object obj)
{
	switch (obj)
	{
	case Object::WATER:
	{
		if (UseItemFromInventory(p, Object::WATER))
		{
			Item* item = p.inventory.GetItem(obj);
			p.inventory.RemoveFromInventory(item);
			delete item;
		}
		break;
	}
	default:
		cout << "Don't be ridiculous!" << endl;
		break;
	}
}

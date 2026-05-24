#include "InventorySystem.h"
#include <iostream>

InventorySystem::InventorySystem()
{
	head = nullptr;
	maxItems = 8;
}

bool InventorySystem::AddToInventory(Item* value)
{
	Node* newNode = new Node(value);

	if (CountItems() == maxItems)
	{
		cout << "You can't carry anymore items!" << endl;
		return false;
	}

	if (head == nullptr)
	{
		head = newNode;
	}
	else
	{
		Node* temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = newNode;
	}

	return true;
}

void InventorySystem::RemoveFromInventory(Item* value)
{
	if (head == nullptr)
	{
		return;
	}
	if (head->data == value)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
		return;
	}
	Node* temp = head;
	while (temp->next && temp->next->data != value)
	{
		temp = temp->next;
	}
	if (temp->next)
	{
		Node* nodeToDelete = temp->next;
		temp->next = temp->next->next;
		delete nodeToDelete;
	}
}

Item* InventorySystem::GetItem(Object obj)
{
	Node* temp = head;
	while (temp != nullptr)
	{
		if (temp->data->objType == obj)
		{
			return temp->data;
		}
		temp = temp->next;
	}


	return nullptr;
}

void InventorySystem::ShowInventory()
{
	if (CountItems() == 0)
	{
		cout << "You aren't carrying anything." << endl;
		return;
	}

	Node* temp = head;

	cout << "You are currently holding the following:" << endl;
	while (temp != nullptr)
	{
		cout << temp->data->name << endl;
		temp = temp->next;
	}
}

int InventorySystem::CountItems()
{
	int counter = 0;
	Node* temp = head;
	while (temp != nullptr)
	{
		counter++;
		temp = temp->next;
	}

	return counter;
}

// ---------------------------------------------------------------------------
// Group: 5
// Names: Christian Tampus, William Weatherby, Kori Gray, Amelia Joyner
// Course-Section: CS-355-01
// Assignment: Project #4 IF Your Turn - MAJOR CAPSTONE IF PROJECT
// Date due: 03/16/2025
// Description: This program is the IF (Interactive Fiction) game engine that can parse/handle any .IFD formated game files.
// ---------------------------------------------------------------------------
#include <iostream>
#include "Area.h"
void Area::setDescription (string desc){
    description = desc;
}
void Area::setGoal(bool g){
    goal = g;
}
void Area::setID(bool id){
    instadeath = id;
}
string Area::getDescription(){
    return description;
}
bool Area::getID(){
    return instadeath;
}
bool Area::getGoal(){
    return goal;
}
void Area::displayArea(){
    cout<<description<<endl;
}
/*
// ---------------------------------------------------------------------------
Description: Area::search(), Searches the area's linked list for items, if the length of the linked list is 0, then it should print out that  are no items in the area, if not it prints out the names of the items that are found in the area.
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void Area::search()
{
	if (this->items.length() > 0)
	{
		std::cout << "The following items are in this area:" << std::endl;
		nodeType<Item*>* currentItem = this->items.getFirst();
		while (currentItem != nullptr)
		{
			/*
			// ---------------------------------------------------------------------------
			Project 4
			Programmer: Christian Tampus
			// ---------------------------------------------------------------------------
			*/
			// ---------------------------------------------------------------------------
			//Start
			if (currentItem->info->getType() == "consume")
			{
				if (currentItem->info->getQuantity() >= 0)
				{
					std::cout << "\t" << currentItem->info->getName() << ": x" << currentItem->info->getQuantity() << std::endl;
				}
				else
				{
					std::cout << "\t" << currentItem->info->getName() << std::endl;	
				};
			}
			else
			{
				std::cout << "\t" << currentItem->info->getName() << std::endl;	
			};
	        //End
	        // ---------------------------------------------------------------------------
			currentItem = currentItem->link;
		};
	}
	else
	{
		std::cout << "No items are in this area." << std::endl;
	};
	/*
	// ---------------------------------------------------------------------------
	Project 4
	Programmer: Christian Tampus
	// ---------------------------------------------------------------------------
	*/
	// ---------------------------------------------------------------------------
	//Start
	if (this->enemies.length() > 0)
	{
		std::cout << "The following enemies are in this area:" << std::endl;
		nodeType<Enemy*>* currentEnemy = this->enemies.getFirst();
		while (currentEnemy != nullptr)
		{
			if (currentEnemy->info->getHealth() > 0)
			{
				std::cout << "\t[STATUS: ALIVE] Enemy Name: [" << currentEnemy->info->getName() << "] Enemy Health: [" << currentEnemy->info->getHealth() << "/" << currentEnemy->info->getInitialHealth() << "]" << std::endl;
				std::cout << "\tEnemy Description: [" << currentEnemy->info->getDesc() << "]" << std::endl;
			}
			else
			{
				std::cout << "\t[STATUS: DEAD] Enemy Name: [" << currentEnemy->info->getName() << "] Enemy Health: [" << currentEnemy->info->getHealth() << "/" << currentEnemy->info->getInitialHealth() << "]" << std::endl;
				std::cout << "\tEnemy Description: [" << currentEnemy->info->getDesc() << "]" << std::endl;
			};
			currentEnemy = currentEnemy->link;
		};
	}
	else
	{
		std::cout << "No enemies are in this area." << std::endl;
	};
	//End
	// ---------------------------------------------------------------------------
};
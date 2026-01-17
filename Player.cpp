// ---------------------------------------------------------------------------
// Group: 5
// Names: Christian Tampus, William Weatherby, Kori Gray, Amelia Joyner
// Course-Section: CS-355-01
// Assignment: Project #4 IF Your Turn - MAJOR CAPSTONE IF PROJECT
// Date due: 03/16/2025
// Description: This program is the IF (Interactive Fiction) game engine that can parse/handle any .IFD formated game files.
// ---------------------------------------------------------------------------
//Dependencies
#include <iostream>
#include <iomanip>
#include <string>
#include "ull.h"
#include "Player.h"
Player::Player(){
    lastLocation = NULL;
    currentLocation = NULL;
}
void Player::setCurrent(areaNode* loc){
    lastLocation = currentLocation;
    currentLocation = loc;
}
bool Player::playerMoved(){
    return !(lastLocation == currentLocation);
}
areaNode* Player::getCurrent(){
    return currentLocation;
}
/*
// ---------------------------------------------------------------------------
Description: Player::inventory(), First asks, “Take what item?” and then reads in a single string (could be multiple words).  It then either reports, “No items are in this area to take.” OR it searches the list of items in the current area for one with a name matching the string entered.  If such an item is found it is added to the inventory and removed from the area’s list of items and “You have taken: X” (where X is the item’s name) is printed out OR the text “No item by that name here.” is printed.
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void Player::inventory()
{
	nodeType<Item*>* temp;
	temp = this->items.getFirst();
	if (temp == NULL)
	{
		std::cout << "No items are in your inventory." << std::endl;
	}
	else
	{
		std::cout << "You have the following items:" << std::endl;
		while (temp != NULL)
		{
			/*
			// ---------------------------------------------------------------------------
			Project 4
			Programmer: William Weatherby
			// ---------------------------------------------------------------------------
			*/
			// ---------------------------------------------------------------------------
			//Start
		    if (temp->info->getQuantity() >= 0){
                std::cout << "\t" << temp->info->getName() << ": x" << temp->info->getQuantity() << std::endl;
		    }
            else {
                std::cout << "\t" << temp->info->getName() << std::endl;
            }
            //End
            // ---------------------------------------------------------------------------
            temp = temp->link;
		};
	};
};
/*
// ---------------------------------------------------------------------------
Description: Player::take(), First asks, “Take what item?” and then reads in a single string (could be multiple words).  It then either reports, “No items are in this area to take.” OR it searches the list of items in the current area for one with a name matching the string entered.  If such an item is found it is added to the inventory and removed from the area’s list of items and “You have taken: X” (where X is the item’s name) is printed out OR the text “No item by that name here.” is printed.
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void Player::take()
{
	std::cout << "Take what item?" << std::endl;
	std::string n;
	std::getline(std::cin,n);
	nodeType<Item*>* temp = NULL;
	temp = this->currentLocation->info.items.getFirst();
	if (temp == NULL)
	{
		std::cout << "No items are in this room to take." << std::endl;
	}
	else
	{
		bool found = false;
		while(temp != NULL && !found)
		{
			if (n == temp->info->getName())
			{
				found = true;
				this->items.insertLast(temp->info);
				this->currentLocation->info.items.deleteNode(temp->info);
			}
			else
			{
				temp = temp->link;
			};
		};
		if (found)
		{
			std::cout << "You have taken: " << n << std::endl;
		}
		else
		{
			std::cout << "No item by that name here." << std::endl;
		};
	};
};
/*
// ---------------------------------------------------------------------------
Description: Player::leave(), First asks, “Leave what item?” and then reads in a single string (could be multiple words).  It then either reports, “You have no items in your inventory.” OR it searches the inventory of items for one with a name matching the string entered.  If such an item is found it is removed from the inventory, added to the area’s list of items and “You have dropped: X” (where X is the item’s name) is printed out OR the text “No item by that name in your inventory.” is printed.
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void Player::leave()
{
	std::cout << "Leave what item?" << std::endl;
	std::string n;
	std::getline(std::cin,n);
	nodeType<Item*>* temp = NULL;
	temp = this->items.getFirst();
	if (temp == NULL)
	{
		std::cout << "You have no items in your inventory." << std::endl;
	}
	else
	{
		bool found = false;
		while (temp != NULL && !found)
		{
			if (n == temp->info->getName())
			{
				found = true;
				this->currentLocation->info.items.insertLast(temp->info);
				this->items.deleteNode(temp->info);
			}
			else
			{
				temp = temp->link;
			};
		};
		if (found)
		{
			std::cout << "You have dropped: " << n << std::endl;
		}
		else
		{
			std::cout << "No item by that name in your inventory." << std::endl;
		};
	};
};
/*
// ---------------------------------------------------------------------------
Description: Player::examine(), First asks, “Examine what item?” and then reads in a single string (could be multiple words).  It then either reports, “You have no items in your inventory to examine.” OR it searches the inventory for an item of that name.  The function will then either report “No item by that name in your inventory.” OR it will print the item’s description (using getDesc()).
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void Player::examine()
{
	std::cout << "Examine what item?" << std::endl;
	std::string n;
	std::getline(std::cin,n);
	nodeType<Item*>* temp = NULL;
	temp = this->items.getFirst();
	if (temp == NULL)
	{
		std::cout << "You have no items in your inventory to examine." << std::endl;
	}
	else
	{
		bool found = false;
		while (temp != NULL && !found)
		{
			if (n == temp->info->getName())
			{
				found = true;
				std::cout << temp->info->getDesc() << std::endl;
				/*
				// ---------------------------------------------------------------------------
				Project 4
				Programmer: Christian Tampus
				// ---------------------------------------------------------------------------
				*/
				// ---------------------------------------------------------------------------
				//Start
			    if (temp->info->getQuantity() >= 0)
				{
			    	std::cout << "Quantity: x" << temp->info->getQuantity() << std::endl;
			    };
	            //End
	            // ---------------------------------------------------------------------------
	            /*
				// ---------------------------------------------------------------------------
				Project 4
				Programmer: Kori Gray
				// ---------------------------------------------------------------------------
				*/
				// ---------------------------------------------------------------------------
				//Start
				string itemType = temp->info->getType();
				if (itemType == "weapon")
				{
					cout << "Weapon Damage: [" << temp->info->getDamage() << "]" << endl;
					cout << "Weapon Affinity: [" << temp->info->getAffinity() << "]" << endl;
					cout << "Weapon Stamina Use: [" << temp->info->getStaminaUse() << "]" << endl;
				}
				else if (itemType == "armor")
				{
					cout << "Armor Durability: [" << fixed << setprecision(2) << temp->info->getDurability() << "/" << fixed << setprecision(2) << temp->info->getInitialDurability() << "]" << endl;
					cout << "Armor Absorption: [" << temp->info->getAbsorption() << "%]" << endl;
				};
				//End
	            // ---------------------------------------------------------------------------
			}
			else
			{
				temp = temp->link;
			};
		};
		if (!found)
		{
			std::cout << "No item by that name in your inventory." << std::endl;
		};
	};
};
/*
// ---------------------------------------------------------------------------
Description: Player::getGameEndReason(), returns gameEndReason
Incoming Data: None
Outgoing Data: gameEndReason (String)
// ---------------------------------------------------------------------------
*/
std::string Player::getGameEndReason()
{
	return this->gameEndReason;
};
/*
// ---------------------------------------------------------------------------
Project 4
Programmer: Amelia Joyner
// ---------------------------------------------------------------------------
*/
// ---------------------------------------------------------------------------
//Start
void Player::equip()
{
	cout << "This player type cannot equip items!" << endl;
};
void Player::unequip()
{
	cout << "This player type cannot unequip items!" << endl;
};
//End
// ---------------------------------------------------------------------------
/*
// ---------------------------------------------------------------------------
Project 4
Programmer: Kori Gray
// ---------------------------------------------------------------------------
*/
// ---------------------------------------------------------------------------
//Start
void Player::attackEnemy(Map* mapptr)
{
	cout << "This player type cannot attack enemies!" << endl;
};
//End
// ---------------------------------------------------------------------------
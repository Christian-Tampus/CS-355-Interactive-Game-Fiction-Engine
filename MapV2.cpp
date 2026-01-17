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
#include <sstream>
#include <string>
#include <vector>
#include "MapV2.h"
#include "Item.h"
#include "ConsumeItem.h"
#include "UseItem.h"
#include "WeaponItem.h"
#include "ArmorItem.h"
/*
// ---------------------------------------------------------------------------
Description: MapV2::MapV2(), default constructor.
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
MapV2::MapV2(){};
/*
// ---------------------------------------------------------------------------
Description: MapV2::buildMap(), overwrites Map::buildMap() to handle maps with different item types & player types
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void MapV2::buildMap()
{
	Map::ifderr = false;
	Map::parser.tokenIt();
	Map::nextToken = Map::parser.getNext();
	if (Map::nextToken == "<game>")
	{
		Map::parser.eatToken();
		Map::nextToken = Map::parser.getNext();
		while(Map::nextToken != "</game>")
		{
			if (Map::nextToken == "<area>")
			{
				Map::parser.eatToken();
				Map::nextToken = Map::parser.getNext();
				Map::makeArea();
			}
			else if (Map::nextToken == "<links>")
			{
                Map::parser.eatToken();
				Map::nextToken = Map::parser.getNext();
				Map::makeLinks();
			}
			else if (Map::nextToken == "<item>")
			{
				Map::parser.eatToken();
				Map::nextToken = Map::parser.getNext();
				this->makeItem();
			}
			else if (Map::nextToken == "<ptype>")
			{
				Map::parser.eatToken();
				Map::nextToken = Map::parser.getNext();
				this->makePlayer();
			}
			/*
			// ---------------------------------------------------------------------------
			Project 4
			Programmer: William Weatherby
			// ---------------------------------------------------------------------------
			*/
			// ---------------------------------------------------------------------------
			//Start
			else if(Map::nextToken == "<enemy>")
			{
				Map::parser.eatToken();
				Map::nextToken = Map::parser.getNext();
				this->makeEnemy();	
			}
			//End
		    // ---------------------------------------------------------------------------
			else
			{
				std::cout << "Parse Error Location 1" << std::endl;
				Map::ifderr = true;
				break;
			};
			Map::parser.eatToken();
			Map::nextToken = Map::parser.getNext();
		};
		if (Map::ifderr)
		{
			std::cout << " :: ERROR :: IF Document Formatting Error" << std::endl;
			std::cout << "Game Loading Failed" << std::endl;
			std::cout << "General Area of Parsing Failure:" << std::endl;
			std::cout << "-------------------------------------" << std::endl;
			std::cout << Map::nextToken << std::endl;
			Map::parser.eatToken();
			Map::nextToken = Map::parser.getNext();
			std::cout << Map::nextToken << std::endl;
			Map::parser.eatToken();
            Map::nextToken = Map::parser.getNext();
			std::cout << Map::nextToken << std::endl;
            Map::parser.eatToken();
            Map::nextToken = Map::parser.getNext();
            std::cout << Map::nextToken << std::endl;
            std::cout <<"-------------------------------------" << std::endl;
			return;
		};
	}
	else
	{
		std::cout << " :: ERROR :: No \"<game>\" tag found." << std::endl;
		std::cout << "Game Loading Failed" << std::endl;
	};
	Map::linkLinks();
	this->insertItems();
	this->insertEnemies();
};
/*
// ---------------------------------------------------------------------------
Description: MapV2::makeItem(), Creates a unique item type (basic, consume, use) and calls makeItemType method passing tempItemPointer & the ending tag associated with the item type
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void MapV2::makeItem()
{
	Item* tempItemPointer = nullptr;
	while (Map::nextToken != "</item>")
	{
		if (Map::nextToken == "<basic>")
		{
			tempItemPointer = new Item();
			tempItemPointer->setType("basic");
			this->makeItemType(tempItemPointer,"</basic>");
		}
		else if (Map::nextToken == "<consume>")
		{
			tempItemPointer = new ConsumeItem();
			tempItemPointer->setType("consume");
			this->makeItemType(tempItemPointer,"</consume>");
		}
		else if (Map::nextToken == "<use>")
		{
			tempItemPointer = new UseItem();
			tempItemPointer->setType("use");
			this->makeItemType(tempItemPointer,"</use>");
		}
		/*
		// ---------------------------------------------------------------------------
		Project 4
		Programmer: Kori Gray
		// ---------------------------------------------------------------------------
		*/
		// ---------------------------------------------------------------------------
		//Start
		else if(Map::nextToken == "<weapon>")
		{
			tempItemPointer = new WeaponItem();
			tempItemPointer->setType("weapon");
			this->makeItemType(tempItemPointer, "</weapon>");
		}
		else if(Map::nextToken == "<armor>")
		{
			tempItemPointer = new ArmorItem();
			tempItemPointer->setType("armor");
			this->makeItemType(tempItemPointer, "</armor>");
		}
		//End
		// ---------------------------------------------------------------------------
		else
		{
			std::cout << "Parse Error Location 2" << std::endl;
			Map::ifderr = true;
			break;
		};
		Map::parser.eatToken();
		Map::nextToken = Map::parser.getNext();
	};
	itemsVector.push_back(tempItemPointer);
};
/*
// ---------------------------------------------------------------------------
Description: MapV2::makeItemType(Item*& inputItemPointer, std::string itemTypeClosingTag), creates the unique item types and parses their attributes then sets them to the tempItemPointer
Incoming Data: inputItemPointer (Item*&), itemTypeClosingTag (String)
Outgoing Data: inputItemPointer (Item*&)
// ---------------------------------------------------------------------------
*/
void MapV2::makeItemType(Item*& inputItemPointer, std::string itemTypeClosingTag)
{
	const char delimiter = ',';
	const int numberOfEndingTags = 15;
	const std::string endingTags[numberOfEndingTags] = {"</name>","</desc>","</star>","</actmess>","</actar>","</effect>","</rule>", "</quantity>", "</damage>", "</affinity>","</durability>", "</absorption>", "</attackmess>", "</breakmess>","</stamina>"};
	Map::parser.eatToken();
	Map::nextToken = Map::parser.getNext();
	while (Map::nextToken != itemTypeClosingTag)
	{
		if (Map::nextToken == "<name>")
		{
			Map::parser.eatToken();
			Map::nextToken = Map::parser.getNext();
			inputItemPointer->setName(Map::nextToken);
		}
		else if (Map::nextToken == "<desc>")
		{
			Map::parser.eatToken();
			Map::nextToken = Map::parser.getNext();
			inputItemPointer->setDesc(Map::nextToken);
		}
		else if (Map::nextToken == "<star>")
		{
			Map::parser.eatToken();
			Map::nextToken = Map::parser.getNext();
			inputItemPointer->setSR(std::stoi(Map::nextToken));
		}
		else if (Map::nextToken == "<actmess>")
		{
			Map::parser.eatToken();
			Map::nextToken = Map::parser.getNext();
			inputItemPointer->setActiveMessage(Map::nextToken);
		}
		else if (Map::nextToken == "<actar>")
		{
			Map::parser.eatToken();
			Map::nextToken = Map::parser.getNext();
			inputItemPointer->setActiveArea(std::stoi(Map::nextToken));
		}
		else if (Map::nextToken == "<rule>")
		{
			Rule* newRule = new Rule;
			std::string tempStringToken;
			Map::parser.eatToken();
			Map::nextToken = Map::parser.getNext();
			std::istringstream ss(Map::nextToken);
			std::getline(ss,tempStringToken,delimiter);
			newRule->beginRm = std::stoi(tempStringToken);
			std::getline(ss,tempStringToken,delimiter);
			newRule->direction = tempStringToken[0];
			std::getline(ss,tempStringToken,delimiter);
			newRule->destRm = std::stoi(tempStringToken);
			inputItemPointer->addRule(newRule);
		}
		else if (Map::nextToken == "<effect>")
		{
			Effect* newEffect = new Effect;
			std::string tempStringToken;
			Map::parser.eatToken();
			Map::nextToken = Map::parser.getNext();
			std::istringstream ss(Map::nextToken);
			std::getline(ss,tempStringToken,delimiter);
			newEffect->effectID = std::stoi(tempStringToken);
			std::getline(ss,tempStringToken,delimiter);
			newEffect->effectAmt = std::stoi(tempStringToken);
			inputItemPointer->addEffect(newEffect);
		}
		/*
		// ---------------------------------------------------------------------------
		Project 4
		Programmer: William Weatherby
		// ---------------------------------------------------------------------------
		*/
		// ---------------------------------------------------------------------------
		//Start
        else if (Map::nextToken == "<quantity>")
		{
		    Map::parser.eatToken();
			Map::nextToken = Map::parser.getNext();
			int newQuantity = std::stoi(Map::nextToken);
			inputItemPointer->setQuantity(newQuantity);
		}
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
		else if(Map::nextToken == "<damage>")
		{
			Map::parser.eatToken();
			Map::nextToken = Map::parser.getNext();
			int damage = std::stoi(Map::nextToken);
			inputItemPointer->setDamage(damage);
		}
		else if(Map::nextToken == "<affinity>")
		{
			Map::parser.eatToken();
			Map::nextToken = Map::parser.getNext();	
			inputItemPointer->setAffinity(nextToken);
		}
		else if(Map::nextToken == "<durability>")
		{
			Map::parser.eatToken();
			Map::nextToken = Map::parser.getNext();	
			int dura = std::stoi(Map::nextToken);
			inputItemPointer->setDurability(dura);
		}
		else if(Map::nextToken == "<absorption>")
		{
			Map::parser.eatToken();
			Map::nextToken = Map::parser.getNext();	
		    int abs = std::stoi(Map::nextToken);
			inputItemPointer->setAbsorption(abs);
		}
		//End
		// ---------------------------------------------------------------------------
		/*
		// ---------------------------------------------------------------------------
		Project 4
		Programmer: Amelia Joyner
		// ---------------------------------------------------------------------------
		*/
		// ---------------------------------------------------------------------------
		//Start
		else if (Map::nextToken == "<attackmess>")
		{
			Map::parser.eatToken();
			Map::nextToken = Map::parser.getNext();
			inputItemPointer->setAttackMess(nextToken);
		}
		else if (Map::nextToken == "<breakmess>")
		{
			Map::parser.eatToken();
			Map::nextToken = Map::parser.getNext();
			inputItemPointer->setBreakMess(nextToken);
		}
		//End
		// ---------------------------------------------------------------------------
		/*
		// ---------------------------------------------------------------------------
		Project 4
		Programmer: Christian Tampus
		// ---------------------------------------------------------------------------
		*/
		// ---------------------------------------------------------------------------
		//Start
		else if (Map::nextToken == "<stamina>")
		{
			Map::parser.eatToken();
			Map::nextToken = Map::parser.getNext();
			inputItemPointer->setStaminaUse(std::stoi(nextToken));
		}
		//End
		// ---------------------------------------------------------------------------
		else
		{
			bool doNothing = false;
			for (int index = 0; index < numberOfEndingTags; index++)
			{
				if (Map::nextToken == endingTags[index])
				{
					doNothing = true;
					break;
				};
			};
			if (!doNothing)
			{
				std::cout << "Parse Error Location 3" << std::endl;
				Map::ifderr = true;
				break;
			};
		};
		Map::parser.eatToken();
		Map::nextToken = Map::parser.getNext();
	};
};
/*
// ---------------------------------------------------------------------------
Description: MapV2::makePlayer(), Creates new player type by first validating the player type, if not valid will default to basic player type
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void MapV2::makePlayer()
{
	const int numberOfPlayerTypes = 3;
	const std::string validPlayerTypesArray[numberOfPlayerTypes] = {"basic","hpsp", "combat"};
	std::string playerType = Map::nextToken;
	bool isValidPlayerType = false;
	for (int index = 0; index < numberOfPlayerTypes; index++)
	{
		if (validPlayerTypesArray[index] == playerType)
		{
			isValidPlayerType = true;
			break;
		};
	};
	if (!isValidPlayerType)
	{
		std::cout << "Player Type: " << playerType << " Is An Invalid Player Type!" << std::endl;
		std::cout << "Defaulting To Basic Player Type!" << std::endl;
		playerType = "basic";
	};
	this->playerType = playerType;
	Map::parser.eatToken();
	Map::nextToken = Map::parser.getNext();
};
/*
// ---------------------------------------------------------------------------
Description: MapV2::insertItems(), loops itemsVector and gets the start room value offset by 1 and uses that to index the correct area in areasVec to insert the item.
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void MapV2::insertItems()
{
	for (int index = 0; index < this->itemsVector.size(); index++)
	{
		this->itemsVector[index]->updateItemUsedBoolean(false);
		/*
		// ---------------------------------------------------------------------------
		Project 4
		Programmer: Christian Tampus
		// ---------------------------------------------------------------------------
		*/
		// ---------------------------------------------------------------------------
		//Start
		if (this->itemsVector[index]->getSR() >= 1)
		{
			Map::areasVec[this->itemsVector[index]->getSR() - 1]->info.items.insertLast(this->itemsVector[index]);
		};
		//End
		// ---------------------------------------------------------------------------
	};
};
/*
// ---------------------------------------------------------------------------
Description: MapV2::resetItems(), method that moves all the pointers to the various Item objects back to their starting areas (this function is called from the resetGame() function in the Game class) and also resets the map area connection pointers.
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void MapV2::resetItems()
{
	for (int index = 0; index < Map::areasVec.size(); index++)
	{
		Map::areasVec[index]->info.items.destroyList();
	};
	this->insertItems();
	//This resets the area connection pointers
	Map::linkLinks();
	/*
	// ---------------------------------------------------------------------------
	Project 4
	Programmer: Christian Tampus
	// ---------------------------------------------------------------------------
	*/
	// ---------------------------------------------------------------------------
	//Start
	for (int index = 0; index < this->itemsVector.size(); index++)
	{
		this->itemsVector[index]->resetQuantity();
		this->itemsVector[index]->resetDurability();
	};
	//End
	// ---------------------------------------------------------------------------
	/*
	// ---------------------------------------------------------------------------
	Project 4
	Programmer: Amelia Joyner
	// ---------------------------------------------------------------------------
	*/
	// ---------------------------------------------------------------------------
	//Start
	for (int index = 0; index < this->enemiesVector.size(); index++)
	{
		this->enemiesVector[index]->setHealth(this->enemiesVector[index]->getInitialHealth());
	};
	//End
	// ---------------------------------------------------------------------------
};
/*
// ---------------------------------------------------------------------------
Description: ostream& operator<<(ostream& osObject, MapV2& mapV2), Prints the information of the areas and then the items in each area.
Incoming Data: osObject (ostream&), mapV2 (MapV2&)
Outgoing Data: osObject (ostream&)
// ---------------------------------------------------------------------------
*/
ostream& operator<<(ostream& osObject, MapV2& mapV2)
{
	osObject << "******************************************************************" << std::endl;
	osObject << "CHEATING!!!! Printing the set of areas and connections on the map." << std::endl;
	osObject << "******************************************************************" << std::endl;
	for (int index = 0; index < mapV2.areasVec.size(); index++)
	{
		osObject << "This is area: " << index + 1 << std::endl;
		osObject << mapV2.areasVec[index]->info.getDescription() << std::endl;
		if (mapV2.areasVec[index]->info.getID() == 1)
		{
			osObject << "Area is INSTADEATH." << std::endl;
		};
		if (mapV2.areasVec[index]->info.getGoal() == 1)
		{
			osObject << "Area is GOAL." << std::endl;
		};
		osObject << "Connections:" << std::endl;
		osObject << "\t u: Area #" << mapV2.reverseLookUp(mapV2.areasVec[index]->u) << std::endl;
		osObject << "\t d: Area #" << mapV2.reverseLookUp(mapV2.areasVec[index]->d) << std::endl;
		osObject << "\t l: Area #" << mapV2.reverseLookUp(mapV2.areasVec[index]->l) << std::endl;
		osObject << "\t r: Area #" << mapV2.reverseLookUp(mapV2.areasVec[index]->r) << std::endl;
	};
	osObject << "******************************************************************" << std::endl;
	osObject << "CHEATING!!!! ITEM LOCATIONS FOR ALL NON-INVENTORY ITEMS." << std::endl;
	osObject << "******************************************************************" << std::endl;
	for (int index = 0; index < mapV2.areasVec.size(); index++)
	{
		osObject << "Items for area " << index + 1 << ": " << mapV2.areasVec[index]->info.getDescription() << std::endl;
		mapV2.areasVec[index]->info.search();
	};
	return osObject;
};
/*
// ---------------------------------------------------------------------------
Project 4
Programmer: William Weatherby
// ---------------------------------------------------------------------------
*/
// ---------------------------------------------------------------------------
//Start
void MapV2::makeEnemy()
{
	Enemy* enemyPointer = new Enemy();
	const char delimiter = ',';
	const int numberOfEndingTags = 9;
	const std::string endingTags[numberOfEndingTags] = {"</name>", "</desc>", "</star>", "</health>", "</resistance>", "</attack>", "</attackmess>", "</deathmess>", "</drop>"};
	while (Map::nextToken != "</enemy>")
	{
		if (Map::nextToken == "<name>")
		{
			Map::parser.eatToken();
			Map::nextToken = Map::parser.getNext();
			enemyPointer->setName(Map::nextToken);
		}
		else if (Map::nextToken == "<desc>")
		{
			Map::parser.eatToken();
			Map::nextToken = Map::parser.getNext();
			enemyPointer->setDesc(Map::nextToken);
		}
		else if (Map::nextToken == "<star>")
		{
			Map::parser.eatToken();
			Map::nextToken = Map::parser.getNext();
			enemyPointer->setStar(stoi(Map::nextToken));
		}
		else if(Map::nextToken == "<health>")
		{
			Map::parser.eatToken();
			Map::nextToken = Map::parser.getNext();
			enemyPointer->setHealth(stod(Map::nextToken));
		}
		else if(Map::nextToken == "<resistance>")
		{
			Map::parser.eatToken();
			Map::nextToken = Map::parser.getNext();
			std::istringstream ss(Map::nextToken);
			std::string bleedResistance;
			std::string poisonResistance;
			std::string frostResistance;
			std::string fireResistance;
			std::getline(ss,bleedResistance,delimiter);
			std::getline(ss,poisonResistance,delimiter);
			std::getline(ss,frostResistance,delimiter);
			std::getline(ss,fireResistance,delimiter);
			enemyPointer->setResistance(stoi(bleedResistance),stoi(poisonResistance),stoi(frostResistance),stoi(fireResistance));
		}
		else if(Map::nextToken == "<attack>")
		{
			Map::parser.eatToken();
			Map::nextToken = Map::parser.getNext();
			enemyPointer->setAttack(stoi(Map::nextToken));
		}
		else if(Map::nextToken == "<attackmess>")
		{
			Map::parser.eatToken();
			Map::nextToken = Map::parser.getNext();
			enemyPointer->setAttackMess(Map::nextToken);
		}
		else if(Map::nextToken == "<deathmess>")
		{
			Map::parser.eatToken();
			Map::nextToken = Map::parser.getNext();
			enemyPointer->setDeathMess(Map::nextToken);
		}
		else if(Map::nextToken == "<drop>")
		{
			Map::parser.eatToken();
			Map::nextToken = Map::parser.getNext();
			enemyPointer->addDropItemName(Map::nextToken);
		}
		else
		{
			bool doNothing = false;
			for (int index = 0; index < numberOfEndingTags; index++)
			{
				if (Map::nextToken == endingTags[index])
				{
					doNothing = true;
					break;
				};
			};
			if (!doNothing)
			{
				std::cout << "Parse Error Location 2" << std::endl;
				Map::ifderr = true;
				break;
			};
		};
		Map::parser.eatToken();
		Map::nextToken = Map::parser.getNext();
	};
	enemiesVector.push_back(enemyPointer);
};
void MapV2::insertEnemies()
{
	for (int index = 0; index < this->enemiesVector.size(); index++)
	{
		Map::areasVec[this->enemiesVector[index]->getStar() - 1]->info.enemies.insertLast(this->enemiesVector[index]);
	};
};
//End
// ---------------------------------------------------------------------------	
/*
// ---------------------------------------------------------------------------
Project 4
Programmer: Christian Tampus
// ---------------------------------------------------------------------------
*/
// ---------------------------------------------------------------------------
//Start
Item* MapV2::getItem(std::string itemName)
{
	for (int index = 0; index < this->itemsVector.size(); index++)
	{
		if (this->itemsVector[index]->getName() == itemName)
		{
			return this->itemsVector[index];
		};
	};
	return nullptr;
};
//End
// ---------------------------------------------------------------------------	
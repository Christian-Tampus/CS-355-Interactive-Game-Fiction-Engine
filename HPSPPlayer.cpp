// ---------------------------------------------------------------------------
// Group: 5
// Names: Christian Tampus, William Weatherby, Kori Gray, Amelia Joyner
// Course-Section: CS-355-01
// Assignment: Project #4 IF Your Turn - MAJOR CAPSTONE IF PROJECT
// Date due: 03/16/2025
// Description: This program is the IF (Interactive Fiction) game engine that can parse/handle any .IFD formated game files.
// ---------------------------------------------------------------------------
//Dependencies
#include "HPSPPlayer.h"
/*
// ---------------------------------------------------------------------------
Description: HPSPPlayer::HPSPPlayer(), HPSPPlayer default constructor
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
HPSPPlayer::HPSPPlayer(){};
/*
// ---------------------------------------------------------------------------
Description: HPSPPlayer::setGameEndReason(std::string reason), sets Player::gameEndReason to reason
Incoming Data: reason (String)
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void HPSPPlayer::setGameEndReason(std::string reason)
{
	Player::gameEndReason = reason;
};
/*
// ---------------------------------------------------------------------------
Description: HPSPPlayer::isGameOver(), handles the game over logic, only prints out the unique game over output if HP or SP reaches <= 0
Incoming Data: None
Outgoing Data: lose/win/continue return values (Integer)
// ---------------------------------------------------------------------------
*/
int HPSPPlayer::isGameOver()
{
	bool isInstaDeathRoom = true;
	bool isGoalRoom = true;
	int loseReturnValue = 2;
	int winReturnValue = 1;
	int continueReturnValue = 0;
	bool currentLocationID = Player::currentLocation->info.getID();
	bool currentLocationGoal = Player::currentLocation->info.getGoal();
	if (currentLocationID == isInstaDeathRoom || this->playerHitPoints <= 0 || this->playerSanityPoints <= 0)
	{
		if (this->playerHitPoints <= 0 || this->playerSanityPoints <= 0)
		{
			this->setGameEndReason("~~~~~~~~~~~~~~~~~~~~~~~~~[!!!!!YOU DIED!!!!!]~~~~~~~~~~~~~~~~~~~~~~~~~");
		};
		return loseReturnValue;
	}
	else if (currentLocationGoal == isGoalRoom)
	{
		return winReturnValue;
	};
	return continueReturnValue;
};
/*
// ---------------------------------------------------------------------------
Description: HPSPPlayer::resetPlayerStats(), resets player HP & SP to 100
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void HPSPPlayer::resetPlayerStats()
{
	this->playerHitPoints = 100;
	this->playerSanityPoints = 100;
	std::cout << "[HPSPPlayer Stats Resetted Successfully!]" << std::endl;
	this->reportStats();
};
/*
// ---------------------------------------------------------------------------
Description: HPSPPlayer::reportStats(), displays HP & SP Integer health & HP & SP Bars
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void HPSPPlayer::reportStats()
{
	const int maxBars = 20;
	const int barStatsIncrement = 5;
	int hpBarsDisplayed = 1;
	int spBarsDisplayed = 1;
	std::cout << "[HPSPPlayer Stats]:" << std::endl;
	std::cout << "\t" << "[Player Health Points: " << this->playerHitPoints << "] HP:[";
	for (int hpBar = 1; hpBar <= this->playerHitPoints; hpBar += barStatsIncrement)
	{
		std::cout << "#";
		hpBarsDisplayed++;
	};
	for (int hpBar = hpBarsDisplayed; hpBarsDisplayed <= maxBars; hpBarsDisplayed++)
	{
		std::cout << "_";
	};
	std::cout << "]" << std::endl;
	std::cout << "\t" << "[Player Sanity Points: " << this->playerSanityPoints << "] SP:[";
	for (int spBar = 1; spBar <= this->playerSanityPoints; spBar += barStatsIncrement)
	{
		std::cout << "#";
		spBarsDisplayed++;
	};
	for (int spBar = spBarsDisplayed; spBarsDisplayed <= maxBars; spBarsDisplayed++)
	{
		std::cout << "_";
	};
	std::cout << "]" << std::endl;
};
/*
// ---------------------------------------------------------------------------
Description: HPSPPlayer::consume(Map* mapptr), calls helper method useOrConsumeItem() passing mapptr, false & "Consume"
Incoming Data: mapptr (Map*)
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void HPSPPlayer::consume(Map* mapptr)
{
	this->useOrConsumeItem(mapptr, false, "Consume");
};
/*
// ---------------------------------------------------------------------------
Description: HPSPPlayer::use(Map* mapptr), calls helper method useOrConsumeItem() passing mapptr, true & "Use"
Incoming Data: mapptr (Map*)
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void HPSPPlayer::use(Map* mapptr)
{
	this->useOrConsumeItem(mapptr, true, "Use");
};
/*
// ---------------------------------------------------------------------------
Description: HPSPPlayer::useOrConsumeItem(Map* mapptr, bool isUseItem, std::string prompt), handles the logic to use/consume Items
Incoming Data: mapptr (Map*), isUseItem (Boolean), prompt (String)
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void HPSPPlayer::useOrConsumeItem(Map* mapptr, bool isUseItem, std::string prompt)
{
	//Variables
	const int offset = 1;
	vector<areaNode*> areasVec = mapptr->getAreasVec();
	areaNode* currentArea = Player::getCurrent();
	nodeType<Item*>* currentItem = Player::items.getFirst();
	//Check if player items has anything inside it
	if (Player::items.length() > 0)
	{
		//prompt player to use/consume what item
		std::cout << prompt << " What Item?" << std::endl;
		std::string itemToUseOrConsume;
		std::getline(std::cin,itemToUseOrConsume);
		//traverse the linkedlist to find the item
		while (currentItem != nullptr && currentItem->info->getName() != itemToUseOrConsume)
		{
			currentItem = currentItem->link;
		};
		//proceed if item is found
		if (currentItem != nullptr && currentItem->info->getName() == itemToUseOrConsume)
		{
			//must check if item is a use item or consume item, if item is a use item and player has used it then do not proceed to check the activation area, currently consume has no logic to handle anything since consume items have no limit of usage
			bool canProceedToCheckActivationArea = false;
			std::vector<Rule*> rulesVector = currentItem->info->getItemUseRules();
			std::vector<Effect*> effectsVector = currentItem->info->getItemConsumeEffects();
			if (isUseItem)
			{
				if (!currentItem->info->hasUsedItem())
				{
					canProceedToCheckActivationArea = true;
				}
				else
				{
					std::cout << "You Already Used That Item!" << std::endl;
				};
			}
			else
			{
			    /*
				// ---------------------------------------------------------------------------
				Project 4
				Programmer: William Weatherby
				// ---------------------------------------------------------------------------
				*/
				// ---------------------------------------------------------------------------
				//Start
			    if (currentItem->info->getQuantity() > 0 || currentItem->info->getQuantity() == -1)
			    {
			    	canProceedToCheckActivationArea = true;
				}
				else
				{
					cout << "You cannot consume this item anymore, its empty!" << endl;	
				};
				//End
				// ---------------------------------------------------------------------------
			};
			//proceed to check the activation area if player CAN use/consume the item
			if (canProceedToCheckActivationArea)
			{
				int activeArea = currentItem->info->getActiveArea();
				bool validActivationArea = false;
				//validate the activation area
				if (activeArea == 0 || activeArea > 0 && areasVec[activeArea - offset] == currentArea)
				{
					validActivationArea = true;
				};
				//proceed if player is inside a valid activation area
				if (validActivationArea)
				{
					//handles the logic if player wanted to use/consume the item
					if (isUseItem)
					{
						//if player wants to USE the item, check if it has ANY RULES, if no rules, then it CANNOT be a USE item and thus print out cannot use statement
						if (rulesVector.size() > 0)
						{
							//update all rules and the specificied area connection pointers
							for (int index = 0; index < rulesVector.size(); index++)
							{
								switch(rulesVector[index]->direction)
								{
									case 'u':
										areasVec[rulesVector[index]->beginRm - offset]->u = areasVec[rulesVector[index]->destRm - offset];
										areasVec[rulesVector[index]->destRm - offset]->d = areasVec[rulesVector[index]->beginRm - offset];
										break;
									case 'd':
										areasVec[rulesVector[index]->beginRm - offset]->d = areasVec[rulesVector[index]->destRm - offset];
										areasVec[rulesVector[index]->destRm - offset]->u = areasVec[rulesVector[index]->beginRm - offset];
										break;
									case 'l':
										areasVec[rulesVector[index]->beginRm - offset]->l = areasVec[rulesVector[index]->destRm - offset];
										areasVec[rulesVector[index]->destRm - offset]->r = areasVec[rulesVector[index]->beginRm - offset];
										break;
									case 'r':
										areasVec[rulesVector[index]->beginRm - offset]->r = areasVec[rulesVector[index]->destRm - offset];
										areasVec[rulesVector[index]->destRm - offset]->l = areasVec[rulesVector[index]->beginRm - offset];
										break;
								};
							};
							//print the activeMessage then update the itemUsed boolean to PREVENT RE-ACTIVATION OF AN ALREADY USED ITEM
							std::cout << currentItem->info->getActiveMessage() << std::endl;
							currentItem->info->updateItemUsedBoolean(true);
						}
						else
						{
							std::cout << "This Item Is A Consume Item & Therefore Cannot Be Used!" << std::endl;
						}
					}
					else
					{
						//if player wants to CONSUME the item, check if it has ANY EFFECTS, if no effects, then it CANNOT be a CONSUME item and thus prints out cannot consume statement
						if (effectsVector.size() > 0)
						{
							//update all the effects applied to player stats
							for (int index = 0; index < effectsVector.size(); index++)
							{
								switch(effectsVector[index]->effectID)
								{
									case 0:
										this->playerHitPoints -= effectsVector[index]->effectAmt;
										break;
									case 1:
										this->playerHitPoints += effectsVector[index]->effectAmt;
										break;
									case 2:
										this->playerSanityPoints -= effectsVector[index]->effectAmt;
										break;
									case 3:
										this->playerSanityPoints += effectsVector[index]->effectAmt;
										break;
								};
							};
							/*
							// ---------------------------------------------------------------------------
							Project 4
							Programmer: William Weatherby
							// ---------------------------------------------------------------------------
							*/
							// ---------------------------------------------------------------------------
							//Start
						    currentItem->info->updateQuantity(-1);
							//End
							// ---------------------------------------------------------------------------
							//print the activateMessage, if later on consumables have a quantity, it will then update the quantity amount here
							std::cout << currentItem->info->getActiveMessage() << std::endl;
						}
						else
						{
							std::cout << "This Item Is A Use Item & Therefore Cannot Be Consumed!" << std::endl;
						};
					};
				}
				//if player is not inside a valid activation area and the active area is -1, this means that the item is a basic item
				else if (!validActivationArea && activeArea == -1)
				{
					std::cout << currentItem->info->getActiveMessage() << std::endl;
				}
				else
				{
					//this handles the logic if player CAN use/consume the item BUT cannot use it in the current AREA, if player attempts to use a CONSUMABLE ITEM, it will prevent it, likewise if a player attemps to consume a USE ITEM, it will also prevent it.
					std::vector<Rule*> rulesVector = currentItem->info->getItemUseRules();
					std::vector<Effect*> effectsVector = currentItem->info->getItemConsumeEffects();
					if (isUseItem && rulesVector.size() > 0 || !isUseItem && effectsVector.size() > 0)
					{
						std::cout << "I Can't " << prompt << " This Item Here!" << std::endl;
					}
					else if (isUseItem && rulesVector.size() == 0)
					{
						std::cout << "This Item Is A Consume Item & Therefore Cannot Be Used!" << std::endl;
					}
					else if (!isUseItem && effectsVector.size() == 0)
					{
						std::cout << "This Item Is A Use Item & Therefore Cannot Be Consumed!" << std::endl;
					};
				};
			};
		}
		else
		{
			std::cout << "No Item To " << prompt << " By That Name In Your Inventory." << std::endl;
		};
	}
	else
	{
		std::cout << "There Are No Items In Your Inventory To " << prompt << std::endl;
	};
};
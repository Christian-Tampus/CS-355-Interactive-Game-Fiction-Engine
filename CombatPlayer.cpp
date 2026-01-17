// ---------------------------------------------------------------------------
// Group: 5
// Names: Christian Tampus, William Weatherby, Kori Gray, Amelia Joyner
// Course-Section: CS-355-01
// Assignment: Project #4 IF Your Turn - MAJOR CAPSTONE IF PROJECT
// Date due: 03/16/2025
// Description: This program is the IF (Interactive Fiction) game engine that can parse/handle any .IFD formated game files.
// ---------------------------------------------------------------------------
//Dependencies
#include "CombatPlayer.h"
#include <iomanip>
/*
// ---------------------------------------------------------------------------
Project 4
Programmer: Amelia Joyner
// ---------------------------------------------------------------------------
*/
// ---------------------------------------------------------------------------
//Start
CombatPlayer::CombatPlayer()
{
	weapon = nullptr;
	armor = nullptr;
};
//End
// ---------------------------------------------------------------------------
//Set Game End Reason
void CombatPlayer::setGameEndReason(std::string reason)
{
	Player::gameEndReason = reason;
};
int CombatPlayer::isGameOver(){
	bool isInstaDeathRoom = true;
	bool isGoalRoom = true;
	int loseReturnValue = 2;
	int winReturnValue = 1;
	int continueReturnValue = 0;
	bool currentLocationID = Player::currentLocation->info.getID();
	bool currentLocationGoal = Player::currentLocation->info.getGoal();
	if (currentLocationID == isInstaDeathRoom || this->playerHitPoints <= 0)
	{
		if (this->playerHitPoints <= 0)
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
void CombatPlayer::resetPlayerStats(){
	/*
	// ---------------------------------------------------------------------------
	Project 4
	Programmer: Amelia Joyner
	// ---------------------------------------------------------------------------
	*/
	// ---------------------------------------------------------------------------
	//Start
	this->armor = nullptr;
	this->weapon = nullptr;
	//End
	// ---------------------------------------------------------------------------
	this->playerHitPoints = 100;
	this->playerStaminaPoints = 100;
	std::cout << "[CombatPlayer Stats Resetted Successfully!]" << std::endl;
	this->reportStats();
};
void CombatPlayer::reportStats(){
	const int maxBars = 20;
	const int barStatsIncrement = 5;
	int hpBarsDisplayed = 1;
	int spBarsDisplayed = 1;
	std::cout << "[CombatPlayer Stats]:" << std::endl;
	std::cout << "\t" << "[Player Health Points: " << std::fixed << std::setprecision(2) << this->playerHitPoints << "] HP:[";
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
	std::cout << "\t" << "[Player Stamina Points: " << std::fixed << std::setprecision(2) << this->playerStaminaPoints << "] SP:[";
	for (int spBar = 1; spBar <= this->playerStaminaPoints; spBar += barStatsIncrement)
	{
		std::cout << "#";
		spBarsDisplayed++;
	};
	for (int spBar = spBarsDisplayed; spBarsDisplayed <= maxBars; spBarsDisplayed++)
	{
		std::cout << "_";
	};
	std::cout << "]" << std::endl;
	/*
	// ---------------------------------------------------------------------------
	Project 4
	Programmer: Amelia Joyner
	// ---------------------------------------------------------------------------
	*/
	// ---------------------------------------------------------------------------
	//Start
	if (armor == nullptr)
	{
		cout << "\t" << "Armor Name: [No Armor Equipped]" << endl;
		cout << "\t" << "Armor Durability: [No Armor Equipped]" << endl;
		cout << "\t" << "Armor Absorption: [No Armor Equipped]" << endl;
	}
	else
	{
		cout << "\tArmor Name: [" << fixed << setprecision(2) << armor->getName() << "]" << endl;
		cout << "\tArmor Durability: [" << fixed << setprecision(2) << armor->getDurability() << "/" << fixed << setprecision(2) << armor->getInitialDurability() << "]" << endl;
		cout << "\tArmor Absorption: [" << fixed << setprecision(2) << + armor->getAbsorption() << "%]" << endl;
	};
	if (weapon == nullptr)
	{
		cout << "\t" << "Weapon Name: [No Weapon Equipped]" << endl;
		cout << "\t" << "Weapon Damage: [No Weapon Equipped]" << endl;
		cout << "\t" << "Weapon Affinity: [No Weapon Equipped]" << endl;
		cout << "\t" << "Weapon Stamina Use: [No Weapon Equipped]" << endl;
	}
	else
	{
		cout << "\t" << "Weapon Name: [" << weapon->getName() << "]" << endl;
		cout << "\t" << "Weapon Damage: [" << weapon->getDamage() << "]" << endl;
		cout << "\t" << "Weapon Affinity: [" << weapon->getAffinity() << "]" << endl;
		cout << "\t" << "Weapon Stamina Use: [" << weapon->getStaminaUse() << "]" << endl;
	};
	//End
	// ---------------------------------------------------------------------------
};
void CombatPlayer::consume(Map* mapptr)
{
	this->useOrConsumeItem(mapptr, false, "Consume");
};
void CombatPlayer::use(Map* mapptr)
{
	this->useOrConsumeItem(mapptr, true, "Use");
};
void CombatPlayer::useOrConsumeItem(Map* mapptr, bool isUseItem, std::string prompt)
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
							/*
							// ---------------------------------------------------------------------------
							Project 4
							Programmer: Christian Tampus
							// ---------------------------------------------------------------------------
							*/
							// ---------------------------------------------------------------------------
							//Start
							for (int index = 0; index < effectsVector.size(); index++)
							{
								switch(effectsVector[index]->effectID)
								{
									case 10:
										this->playerHitPoints -= effectsVector[index]->effectAmt;
										break;
									case 11:
										this->playerHitPoints += effectsVector[index]->effectAmt;
										break;
									case 12:
										this->playerStaminaPoints -= effectsVector[index]->effectAmt;
										break;
									case 13:
										this->playerStaminaPoints += effectsVector[index]->effectAmt;
										break;
								};
							};
							if (this->playerStaminaPoints <= 0)
							{
								this->playerStaminaPoints = 0;
							};
							if (this->playerHitPoints <= 0)
							{
								this->playerHitPoints = 0;
							};
							//End
							// ---------------------------------------------------------------------------
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
/*
// ---------------------------------------------------------------------------
Project 4
Programmer: Amelia Joyner
// ---------------------------------------------------------------------------
*/
// ---------------------------------------------------------------------------
//Start
void CombatPlayer::equip(){
	if (Player::items.length() > 0)
	{
		cout << "Equip which item?" << endl;
		string toEquip;
		getline(cin, toEquip);
		nodeType<Item*>* currentItem = Player::items.getFirst();
		while (currentItem != nullptr && currentItem->info->getName() != toEquip)
		{
			currentItem = currentItem->link;	
		};
		if (currentItem != nullptr && currentItem->info->getName() == toEquip)
		{
			if (currentItem->info->getType() == "weapon")
			{
				weapon = currentItem->info;
				cout << "Weapon: " << weapon->getName() << endl;
			}
			else if (currentItem->info->getType() == "armor")
			{
				armor = currentItem->info;
				cout << "Armor: " << armor->getName() << endl;
			}
			else
			{
				cout << "This item cannot be equipped because it is not a weapon or an armor" << endl;
			};
		}
		else
		{
			cout << "No items of that name to equip in your inventory" << endl;	
		};
	}
	else
	{
		cout << "No items to equip inside your inventory" << endl;
	};
};
void CombatPlayer::unequip(){
	if (Player::items.length() > 0)
	{
		cout << "Unequip which item?" << endl;
		string toUnequip;
		getline(cin, toUnequip);
		nodeType<Item*>* currentItem = Player::items.getFirst();
		while (currentItem != nullptr && currentItem->info->getName() != toUnequip)
		{
			currentItem = currentItem->link;	
		};
		if (currentItem != nullptr && currentItem->info->getName() == toUnequip)
		{
			if (currentItem->info->getType() == "weapon")
			{
				if (weapon != nullptr)
				{
					cout << "Unequipped weapon " << weapon->getName() << endl;
				}
				else
				{
					cout << "No weapon equipped to unequip" << endl;
				};
				weapon = nullptr;
			}
			else if (currentItem->info->getType() == "armor")
			{
				if (armor != nullptr)
				{
					cout << "Unequipped armor " << armor->getName() << endl;
				}
				else
				{
					cout << "No armor equipped to unequip" << endl;
				};
				armor = nullptr;
			}
			else
			{
				cout << "This item cannot be unequipped because it is not a weapon or an armor" << endl;	
			};
		};
	}
	else
	{
		cout << "No items to unequip inside your inventory" << endl;	
	};
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
void CombatPlayer::leave()
{
	Player::leave();
	nodeType<Item*>* currentItem = Player::items.getFirst();
	if (currentItem == nullptr)
	{
		this->armor = nullptr;
		this->weapon = nullptr;
	}
	else
	{
		bool unequipArmor = true;
		bool unequipWeapon = true;
		while (currentItem != nullptr)
		{
			if (this->armor != nullptr && this->armor->getName() == currentItem->info->getName())
			{
				unequipArmor = false;
				break;
			}
			else if (this->weapon != nullptr && this->weapon->getName() == currentItem->info->getName())
			{
				unequipWeapon = false;
				break;
			};
			currentItem = currentItem->link;
		};
		if (unequipArmor && this->armor != nullptr)
		{
			this->armor = nullptr;
		};
		if (unequipWeapon && this->weapon != nullptr)
		{
			this->weapon = nullptr;	
		};
	};
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
void CombatPlayer::attackEnemy(Map* mapptr)
{
	if(weapon != nullptr)
	{
		/*
		// ---------------------------------------------------------------------------
		Project 4
		Programmer: Christian Tampus
		// ---------------------------------------------------------------------------
		*/
		// ---------------------------------------------------------------------------
		//Start
		if (this->playerStaminaPoints <= 0)
		{
			std::cout << "You Are Too Tired (Not Enough Stamina Points) To Attack An Enemy!" << std::endl;
			return;	
		};
		//End
		// ---------------------------------------------------------------------------
		areaNode* currentArea = Player::getCurrent();
		nodeType<Enemy*>* currentEnemy = currentArea->info.enemies.getFirst();
		if (currentEnemy != nullptr)
		{
			cout << "Attack which enemy?" << endl;
			string enemyName;
			getline(cin, enemyName);
			while (currentEnemy != nullptr && currentEnemy->info->getName() != enemyName)
			{
				currentEnemy = currentEnemy->link;
			};
			if (currentEnemy != nullptr && currentEnemy->info->getName() == enemyName)
			{
				if (currentEnemy->info->getHealth() > 0) 
				{
					/*
					// ---------------------------------------------------------------------------
					Project 4
					Programmer: Amelia Joyner
					// ---------------------------------------------------------------------------
					*/
					// ---------------------------------------------------------------------------
					//Start
					int weaponDamage = weapon->getDamage();
					string weaponAffinity = weapon->getAffinity();
					double enemyHealth = currentEnemy->info->getHealth();
					double enemyResistance = currentEnemy->info->getResistance(weaponAffinity)/100;
					double damageMultiplier = 1-enemyResistance;
					double totalDamage = weaponDamage * damageMultiplier;
					cout << weapon->getAttackMess() << endl;
					cout << currentEnemy->info->getAttackMess() << endl;
					if (armor != nullptr)
					{
						double armorDurability = armor->getDurability();	
						double armorAbsorption = armor->getAbsorption();
						double damageReduced = currentEnemy->info->getAttack() * (armorAbsorption / 100);
						if (armorDurability - damageReduced >= 0) 
						{
							double enemyAttack = currentEnemy->info->getAttack() - damageReduced;
							playerHitPoints -= enemyAttack;
							armor->updateDurability(armorDurability - damageReduced);
						}
						else
						{
							if (armor->getDurability() > 0)
							{
								cout << armor->getBreakMess() << endl;
							};
							double enemyAttack = currentEnemy->info->getAttack() - armorDurability;
							armor->updateDurability(0);
							playerHitPoints -= enemyAttack;
						};
					}
					else
					{
						if(playerHitPoints - currentEnemy->info->getAttack() >= 0)
						{
							playerHitPoints -= currentEnemy->info->getAttack();
						}
						else
						{
							playerHitPoints = 0;
						};
					};
					if (enemyHealth - totalDamage >= 0)
					{
						currentEnemy->info->updateHealth(enemyHealth-totalDamage);
						cout << "Enemy Name: [" << currentEnemy->info->getName() << "] Enemy Health: [" << currentEnemy->info->getHealth() << "/" << currentEnemy->info->getInitialHealth() << "]" << endl;
					}
					else
					{
						currentEnemy->info->updateHealth(0);
					};
					if (currentEnemy->info->getHealth() <= 0)
					{
						cout << currentEnemy->info->getDeathMess() << endl;
						vector<areaNode*> areasVec = mapptr->getAreasVec();
						vector<string> dropItemNamesVec = currentEnemy->info->getDropItemNamesVec();
						for (int i = 0; i < dropItemNamesVec.size(); i++)
						{
							Item* dropItemPtr = mapptr->getItem(dropItemNamesVec[i]);
							areasVec[currentEnemy->info->getStar() - 1]->info.items.insertLast(dropItemPtr);
							if (dropItemPtr->getType() == "consume")
							{
								cout << "[DROP] " << dropItemPtr->getName() << ": x" << dropItemPtr->getQuantity() << std::endl;
							}
							else
							{
								cout << "[DROP] " << dropItemPtr->getName() << endl;
							};
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
					this->playerStaminaPoints -= weapon->getStaminaUse();
					if (this->playerStaminaPoints <= 0)
					{
						this->playerStaminaPoints = 0;
					}
					//End
					// ---------------------------------------------------------------------------
				}
				else 
				{
					cout << "This enemy is already dead and therefore cannot be attacked" << endl; 
				};
			}
			else
			{
				cout << "There are no enemies with that name in this area to attack" << endl;
			}
		}
		else
		{
			cout << "There are currently no enemies in this area to attack" << endl;
		};
	}
	else
	{
		cout << "You do not have any equipped weapons therefore you cannot attack any enemies" << endl;
	};
};
//End
// ---------------------------------------------------------------------------
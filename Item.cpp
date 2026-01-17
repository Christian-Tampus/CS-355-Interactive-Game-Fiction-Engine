// ---------------------------------------------------------------------------
// Group: 5
// Names: Christian Tampus, William Weatherby, Kori Gray, Amelia Joyner
// Course-Section: CS-355-01
// Assignment: Project #4 IF Your Turn - MAJOR CAPSTONE IF PROJECT
// Date due: 03/16/2025
// Description: This program is the IF (Interactive Fiction) game engine that can parse/handle any .IFD formated game files.
// ---------------------------------------------------------------------------
//Dependencies
#include "Item.h"
#include <iostream>
/*
// ---------------------------------------------------------------------------
Description: Item::Item(), default constructor, sets activeMessage, activeArea & type
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
Item::Item(){
	this->activeMessage = "That seems quite impossible.";
	this->activeArea = -1;
	this->type = "basic";
};
/*
// ---------------------------------------------------------------------------
Description: Item::setName(std::string newItemName), sets itemName
Incoming Data: newItemName (String)
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void Item::setName(std::string newItemName)
{
	this->itemName = newItemName;
};
/*
// ---------------------------------------------------------------------------
Description: Item::setDesc(std::string newItemDescription), sets itemDescription
Incoming Data: newItemDescription (String)
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void Item::setDesc(std::string newItemDescription)
{
	this->itemDescription = newItemDescription;
};
/*
// ---------------------------------------------------------------------------
Description: Item::setSR(int newSR), sets SR
Incoming Data: newSR (Integer)
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void Item::setSR(int newSR)
{
	this->SR = newSR;
};
/*
// ---------------------------------------------------------------------------
Description: Item::getName(), returns itemName
Incoming Data: None
Outgoing Data: itemName (String)
// ---------------------------------------------------------------------------
*/
std::string Item::getName()
{
	return this->itemName;
};
/*
// ---------------------------------------------------------------------------
Description: Item::getDesc(), returns itemDescription
Incoming Data: None
Outgoing Data: itemDescription (String)
// ---------------------------------------------------------------------------
*/
std::string Item::getDesc()
{
	return this->itemDescription;
};
/*
// ---------------------------------------------------------------------------
Description: Item::getSR(), returns SR
Incoming Data: None
Outgoing Data: SR (Integer)
// ---------------------------------------------------------------------------
*/
int Item::getSR()
{
	return this->SR;
};
/*
// ---------------------------------------------------------------------------
Description: Item::displayName(), prints itemName
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void Item::displayName()
{
	std::cout << this->itemName << std::endl;
};
/*
// ---------------------------------------------------------------------------
Description: Item::displayDesc(), prints itemDescription
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void Item::displayDesc()
{
	std::cout << this->itemDescription << std::endl;
};
std::string Item::getType()
{
	return this->type;
};
/*
// ---------------------------------------------------------------------------
Description: ostream& operator<<(ostream& outStream, Item& item), insertion operator overloaded to print itemName, itemDescription & SR
Incoming Data: outStream (ostream&), item (Item&)
Outgoing Data: outStream (ostream&)
// ---------------------------------------------------------------------------
*/
ostream& operator<<(ostream& outStream, Item& item)
{
	outStream << "Item Name: " << item.getName() << std::endl;
	outStream << "Item Description: " << item.getDesc() << std::endl;
	outStream << "Item Start Room:" << item.getSR() << std::endl;
	return outStream;
};
void Item::setActiveMessage(std::string s)
{
	std::cout << "DEBUG WARNING: Objects of the Item (basic items) class don't have active messages." << std::endl;
};
std::string Item::getActiveMessage()
{
	//Objects of the Item (basic items) class don't have active messages.
	std::string aM = "You see no way to do that.";
	return aM;
};
void Item::setActiveArea(int i)
{
	std::cout <<"DEBUG WARNING: Objects of the Item (basic items) class don't have active areas." << std::endl;
};
int Item::getActiveArea()
{
	//as this is a basic item, it doesn't have an active area
	return -1;
};
void Item::addRule(Rule* temp)
{
	std::cout <<"DEBUG WARNING: Objects of the Item (basic items) class don't have associated rules." << std::endl;
};
std::vector<Rule*> Item::getItemUseRules()
{
	//shouldn't ever call this method directly
	std::vector<Rule*> blank;
	return blank;
};
void Item::addEffect(Effect* temp)
{
	std::cout << "DEBUG WARNING: Objects of the Item (basic items) class don't have associated effects." << std::endl;
}
std::vector<Effect*> Item::getItemConsumeEffects()
{
	//shouldn't ever call this method directly
	std::vector<Effect*> blank;
	return blank;
};
/*
// ---------------------------------------------------------------------------
Description: Item::updateItemUsedBoolean(bool newBoolean), sets itemUsed to newBoolean
Incoming Data: newBoolean (Boolean)
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void Item::updateItemUsedBoolean(bool newBoolean)
{
	this->itemUsed = newBoolean;
};
/*
// ---------------------------------------------------------------------------
Description: Item::hasUsedItem(), returns itemUsed
Incoming Data: None
Outgoing Data: itemUsed (Boolean)
// ---------------------------------------------------------------------------
*/
bool Item::hasUsedItem()
{
	return this->itemUsed;
};
/*
// ---------------------------------------------------------------------------
Project 4
Programmer: William Weatherby
// ---------------------------------------------------------------------------
*/
// ---------------------------------------------------------------------------
//Start
void Item::setQuantity(int newQuantity){};
int Item::getQuantity()
{
    return -1;
}
void Item::updateQuantity(int updatedQuantity){};
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
void Item::resetQuantity(){};
void Item::resetDurability(){};
void Item::setStaminaUse(int){};
int Item::getStaminaUse()
{
	return 0;
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
void Item::setDamage(int d){};
void Item::setAffinity(string aff){};
int Item::getDamage()
{
	return 0;
};
string Item::getAffinity()
{
	return "";
};
void Item::setDurability(double dura){};
void Item::setAbsorption(int abs){};
double Item::getDurability()
{
	return 0;
};
double Item::getInitialDurability()
{
	return 0;
};
int Item::getAbsorption()
{
	return 0;
};
void Item::setType(string t)
{
	type = t;
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
void Item::setAttackMess(string newAttackMess){};
string Item::getAttackMess()
{
	return "";	
};
void Item::updateDurability(double updatedDurability){};
void Item::setBreakMess(string){};
string Item::getBreakMess()
{
	return "";
};
//End
// ---------------------------------------------------------------------------
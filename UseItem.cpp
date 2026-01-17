// ---------------------------------------------------------------------------
// Group: 5
// Names: Christian Tampus, William Weatherby, Kori Gray, Amelia Joyner
// Course-Section: CS-355-01
// Assignment: Project #4 IF Your Turn - MAJOR CAPSTONE IF PROJECT
// Date due: 03/16/2025
// Description: This program is the IF (Interactive Fiction) game engine that can parse/handle any .IFD formated game files.
// ---------------------------------------------------------------------------
//Dependencies
#include "UseItem.h"
/*
// ---------------------------------------------------------------------------
Description: UseItem::setActiveMessage(std::string newActiveMessage), sets activeMessage to newActiveMessage
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void UseItem::setActiveMessage(std::string newActiveMessage)
{
	this->activeMessage = newActiveMessage;
};
/*
// ---------------------------------------------------------------------------
Description: UseItem::getActiveMessage(), returns activeMessage
Incoming Data: newActiveMessage (String)
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
std::string UseItem::getActiveMessage()
{
	return this->activeMessage;
};
/*
// ---------------------------------------------------------------------------
Description: UseItem::setActiveArea(int newActiveArea), sets activeArea to newActiveArea
Incoming Data: newActiveArea (Integer)
Outgoing Data: activeMessage (String)
// ---------------------------------------------------------------------------
*/
void UseItem::setActiveArea(int newActiveArea)
{
	this->activeArea = newActiveArea;
};
/*
// ---------------------------------------------------------------------------
Description: UseItem::getActiveArea(), returns activeArea
Incoming Data: None
Outgoing Data: activeArea (Integer)
// ---------------------------------------------------------------------------
*/
int UseItem::getActiveArea()
{
	return this->activeArea;
};
/*
// ---------------------------------------------------------------------------
Description: UseItem::addRule(Rule* temp), adds a new rule to the rulesVector
Incoming Data: temp (Rule*)
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void UseItem::addRule(Rule* temp)
{
	this->rulesVector.push_back(temp);
};
/*
// ---------------------------------------------------------------------------
Description: UseItem::getItemUseRules(), returns rulesVector
Incoming Data: None
Outgoing Data: rulesVector (Rule* Vector)
// ---------------------------------------------------------------------------
*/
std::vector<Rule*> UseItem::getItemUseRules()
{
	return this->rulesVector;
};
/*
// ---------------------------------------------------------------------------
Description: UseItem::addEffect(Effect* temp), adds a new effect to effectsVector
Incoming Data: temp (Effect*)
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void UseItem::addEffect(Effect* temp)
{
	this->effectsVector.push_back(temp);
};
/*
// ---------------------------------------------------------------------------
Description: UseItem::getItemConsumeEffects(), returns effectsVector
Incoming Data: None
Outgoing Data: effectsVector (Effect* Vector>
// ---------------------------------------------------------------------------
*/
std::vector<Effect*> UseItem::getItemConsumeEffects()
{
	return this->effectsVector;
};
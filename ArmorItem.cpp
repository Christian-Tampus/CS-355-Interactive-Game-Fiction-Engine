// ---------------------------------------------------------------------------
// Group: 5
// Names: Christian Tampus, William Weatherby, Kori Gray, Amelia Joyner
// Course-Section: CS-355-01
// Assignment: Project #4 IF Your Turn - MAJOR CAPSTONE IF PROJECT
// Date due: 03/16/2025
// Description: This program is the IF (Interactive Fiction) game engine that can parse/handle any .IFD formated game files.
// ---------------------------------------------------------------------------
//Dependencies
#include "ArmorItem.h"
/*
// ---------------------------------------------------------------------------
Project 4
Programmer: Kori Gray
// ---------------------------------------------------------------------------
*/
// ---------------------------------------------------------------------------
//Start
void ArmorItem::setDurability(double dura)
{
	durability = dura;
	initialDurability = dura;
};
void ArmorItem::setAbsorption(int abs)
{
	absorption = abs;
};
double ArmorItem::getDurability()
{
	return durability;
};
double ArmorItem::getInitialDurability()
{
	return initialDurability;
};
int ArmorItem::getAbsorption()
{
	return absorption;
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
void ArmorItem::resetDurability()
{
	this->durability = this->initialDurability;
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
void ArmorItem::updateDurability(double updatedDurability)
{
	durability = updatedDurability;
};
void ArmorItem::setBreakMess(string newBreakMess)
{
	breakMess = newBreakMess;
};
string ArmorItem::getBreakMess()
{
	return breakMess;
};
//End
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// Group: 5
// Names: Christian Tampus, William Weatherby, Kori Gray, Amelia Joyner
// Course-Section: CS-355-01
// Assignment: Project #4 IF Your Turn - MAJOR CAPSTONE IF PROJECT
// Date due: 03/16/2025
// Description: This program is the IF (Interactive Fiction) game engine that can parse/handle any .IFD formated game files.
// ---------------------------------------------------------------------------
//Dependencies
#include "WeaponItem.h"
/*
// ---------------------------------------------------------------------------
Project 4
Programmer: Kori Gray
// ---------------------------------------------------------------------------
*/
// ---------------------------------------------------------------------------
//Start
void WeaponItem::setDamage(int d)
{
	damage = d;
};
void WeaponItem::setAffinity(string aff)
{
	affinity = aff;
};
int WeaponItem::getDamage()
{
	return damage;
};
string WeaponItem::getAffinity()
{
	return affinity;
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
void WeaponItem::setAttackMess(string newAttackMess)
{
	attackMess = newAttackMess;
};
string WeaponItem::getAttackMess()
{
	return attackMess;
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
void WeaponItem::setStaminaUse(int newStaminaUse)
{
	this->staminaUse = newStaminaUse;
};
int WeaponItem::getStaminaUse()
{
	return this->staminaUse;
};
//End
// ---------------------------------------------------------------------------
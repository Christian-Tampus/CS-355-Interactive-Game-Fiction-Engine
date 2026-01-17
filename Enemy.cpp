// ---------------------------------------------------------------------------
// Group: 5
// Names: Christian Tampus, William Weatherby, Kori Gray, Amelia Joyner
// Course-Section: CS-355-01
// Assignment: Project #4 IF Your Turn - MAJOR CAPSTONE IF PROJECT
// Date due: 03/16/2025
// Description: This program is the IF (Interactive Fiction) game engine that can parse/handle any .IFD formated game files.
// ---------------------------------------------------------------------------
//Dependencies
#include "Enemy.h"
#include <iostream>
/*
// ---------------------------------------------------------------------------
Project 4
Programmer: William Weatherby
// ---------------------------------------------------------------------------
*/
// ---------------------------------------------------------------------------
//Start
Enemy::Enemy(){};
void Enemy::setName(string newName)
{
	name = newName;
};
void Enemy::setDesc(string newDesc)
{
	desc = newDesc;
};
void Enemy::setStar(int newStar)
{
	star = newStar;
};
void Enemy::setHealth(double newHealth)
{
	health = newHealth;
	initialHealth = newHealth;
};
void Enemy::updateHealth(double updatedHealth)
{
	health = updatedHealth;
};
void Enemy::setResistance(int newBleedResistance, int newPoisonResistance, int newFrostResistance, int newFireResistance)
{
	bleedResistance = newBleedResistance;
	poisonResistance = newPoisonResistance;
	frostResistance = newFrostResistance;
	fireResistance = newFireResistance;
};
void Enemy::setAttack(int newAttack)
{
	attack = newAttack;
};
void Enemy::setAttackMess(string newAttackMess)
{
	attackMess = newAttackMess;
};
void Enemy::setDeathMess(string newDeathMess)
{
	deathMess = newDeathMess;
};
string Enemy::getName()
{
	return name;
};
string Enemy::getDesc()
{
	return desc;
};
int Enemy::getStar()
{
	return star;
};
double Enemy::getHealth()
{
	return health;
};
double Enemy::getInitialHealth()
{
	return initialHealth;	
};
double Enemy::getResistance(string getResistanceType)
{
	if (getResistanceType == "Bleed")
	{
		return bleedResistance;
	}
	else if (getResistanceType == "Poison")
	{
		return poisonResistance;
	}
	else if (getResistanceType == "Frost")
	{
		return frostResistance;
	}
	else if (getResistanceType == "Fire")
	{
		return fireResistance;
	}
	return 0;
};
int Enemy::getAttack()
{
	return attack;
};
string Enemy::getAttackMess()
{
	return attackMess;
};
string Enemy::getDeathMess()
{
	return deathMess;
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
void Enemy::addDropItemName(string newDropItemName)
{
	dropItemNamesVec.push_back(newDropItemName);
};
vector<string> Enemy::getDropItemNamesVec()
{
	return dropItemNamesVec;
};
//End
// ---------------------------------------------------------------------------
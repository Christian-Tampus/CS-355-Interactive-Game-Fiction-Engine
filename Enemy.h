// ---------------------------------------------------------------------------
// Group: 5
// Names: Christian Tampus, William Weatherby, Kori Gray, Amelia Joyner
// Course-Section: CS-355-01
// Assignment: Project #4 IF Your Turn - MAJOR CAPSTONE IF PROJECT
// Date due: 03/16/2025
// Description: This program is the IF (Interactive Fiction) game engine that can parse/handle any .IFD formated game files.
// ---------------------------------------------------------------------------
//Headers
#ifndef H_ENEMY
#define H_ENEMY
//Dependencies
#include <string>
#include <iostream>
#include <vector>
//Namespaces
using namespace std;
//Class Declaration
class Enemy
{
	public:
		/*
		// ---------------------------------------------------------------------------
		Project 4
		Programmer: William Weatherby
		// ---------------------------------------------------------------------------
		*/
		// ---------------------------------------------------------------------------
		//Start
		Enemy();
		void setName(string);
		void setDesc(string);
		void setStar(int);
		void setHealth(double);
		void updateHealth(double);
		void setResistance(int, int, int, int);
		void setAttack(int);
		void setAttackMess(string);
		void setDeathMess(string);
		string getName();
		string getDesc();
		int getStar();
		double getHealth();
		double getInitialHealth();
		double getResistance(string getResistanceType);
		int getAttack();
		string getAttackMess();
		string getDeathMess();
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
		void addDropItemName(string);
		vector<string> getDropItemNamesVec();
		//End
		// ---------------------------------------------------------------------------
	private:
		string name;
		string desc;
		int star;
		double health;
		double initialHealth;
		int bleedResistance;
		int poisonResistance;
		int frostResistance;
		int fireResistance;
		int attack;
		string attackMess;
		string deathMess;
		vector<string> dropItemNamesVec;
};
#endif
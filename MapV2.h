// ---------------------------------------------------------------------------
// Group: 5
// Names: Christian Tampus, William Weatherby, Kori Gray, Amelia Joyner
// Course-Section: CS-355-01
// Assignment: Project #4 IF Your Turn - MAJOR CAPSTONE IF PROJECT
// Date due: 03/16/2025
// Description: This program is the IF (Interactive Fiction) game engine that can parse/handle any .IFD formated game files.
// ---------------------------------------------------------------------------
//Headers
#ifndef H_MAPV2
#define H_MAPV2
//Dependencies
#include "Map.h"
#include "Enemy.h"
#include <iostream>
//Namespaces
using namespace std;
//Class Declaration
class MapV2 : public Map
{
	private:
		std::vector<Item*> itemsVector;
		/*
		// ---------------------------------------------------------------------------
		Project 4
		Programmer: William Weatherby
		// ---------------------------------------------------------------------------
		*/
		// ---------------------------------------------------------------------------
		//Start
		std::vector<Enemy*> enemiesVector;
		//End
	    // ---------------------------------------------------------------------------
	public:
		MapV2();
		void buildMap();
		void makeItem();
		void makeItemType(Item*&, std::string);
		void makePlayer();
		void insertItems();
		void resetItems();
		friend ostream& operator<<(ostream&, MapV2&);
		//Stores String For PlayerType, Defaults To basic PlayerType
		std::string playerType = "basic";
		/*
		// ---------------------------------------------------------------------------
		Project 4
		Programmer: William Weatherby
		// ---------------------------------------------------------------------------
		*/
		// ---------------------------------------------------------------------------
		//Start
		void makeEnemy();
		void insertEnemies();
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
		Item* getItem(string) override;
		//End
	    // ---------------------------------------------------------------------------
};
#endif
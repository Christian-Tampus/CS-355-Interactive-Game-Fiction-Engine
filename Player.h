// ---------------------------------------------------------------------------
// Group: 5
// Names: Christian Tampus, William Weatherby, Kori Gray, Amelia Joyner
// Course-Section: CS-355-01
// Assignment: Project #4 IF Your Turn - MAJOR CAPSTONE IF PROJECT
// Date due: 03/16/2025
// Description: This program is the IF (Interactive Fiction) game engine that can parse/handle any .IFD formated game files.
// ---------------------------------------------------------------------------
//Headers
#ifndef H_PLAYER
#define H_PLAYER
//Dependencies
#include "areaNode.h"
#include "ull.h"
#include "Item.h"
#include "Map.h"
//Class Declaration
class Player{
	public:
		uLList<Item*> items;
		Player();
		void setCurrent(areaNode*);
		bool playerMoved();
		areaNode* getCurrent();
		void inventory();
		void take();
		/*
		// ---------------------------------------------------------------------------
		Project 4
		Programmer: Christian Tampus
		// ---------------------------------------------------------------------------
		*/
		// ---------------------------------------------------------------------------
		//Start
		//Modified leave to be a virtual method to be able to unequip weapons/armor for the CombatPlayer class
		virtual void leave();
		//End
		// ---------------------------------------------------------------------------
		void examine();
		//Get The Game End Reason
		std::string getGameEndReason();
		//Set The Game End Reason (Pure Virtual Method)
		virtual void setGameEndReason(std::string) = 0;
		virtual int isGameOver() = 0;
		virtual void resetPlayerStats() = 0;
		virtual void reportStats() = 0;
		virtual void consume(Map* mapptr) = 0;
		virtual void use(Map* mapptr) = 0;
		/*
		// ---------------------------------------------------------------------------
		Project 4
		Programmer: Amelia Joyner
		// ---------------------------------------------------------------------------
		*/
		// ---------------------------------------------------------------------------
		//Start
		virtual void equip();
		virtual void unequip();
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
		virtual void attackEnemy(Map* mapptr);
		//End
		// ---------------------------------------------------------------------------
	protected:
		areaNode* currentLocation;
		areaNode* lastLocation;
		//Changes The Ouptut Upon Player Death, The Default Is InstaDeathOrGoalRooms Which Means That The Output SHOULD NOT APPEAR
		std::string gameEndReason = "InstaDeathOrGoalRooms";
};
#endif
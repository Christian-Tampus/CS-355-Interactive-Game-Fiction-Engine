// ---------------------------------------------------------------------------
// Group: 5
// Names: Christian Tampus, William Weatherby, Kori Gray, Amelia Joyner
// Course-Section: CS-355-01
// Assignment: Project #4 IF Your Turn - MAJOR CAPSTONE IF PROJECT
// Date due: 03/16/2025
// Description: This program is the IF (Interactive Fiction) game engine that can parse/handle any .IFD formated game files.
// ---------------------------------------------------------------------------
//Headers
#ifndef H_COMBATPLAYER
#define H_COMBATPLAYER
//Dependencies
#include "Player.h"
//Class Declaration
class CombatPlayer : public Player
{
	public:
		/*
		// ---------------------------------------------------------------------------
		Project 4
		Programmer: Amelia Joyner
		// ---------------------------------------------------------------------------
		*/
		// ---------------------------------------------------------------------------
		//Start
		CombatPlayer();
		//End
		// ---------------------------------------------------------------------------
		//Set Game End Reason
		void setGameEndReason(std::string) override;
		int isGameOver() override;
		void resetPlayerStats() override;
		void reportStats() override;
		void consume(Map* mapptr) override;
		void use(Map* mapptr) override;
		void useOrConsumeItem(Map* mapptr, bool isUseItem, std::string prompt);
		/*
		// ---------------------------------------------------------------------------
		Project 4
		Programmer: Amelia Joyner
		// ---------------------------------------------------------------------------
		*/
		// ---------------------------------------------------------------------------
		//Start
		void equip() override;
		void unequip() override;
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
		void leave() override;
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
		void attackEnemy(Map* mapptr) override;
		//End
		// ---------------------------------------------------------------------------
	private:
		/*
		// ---------------------------------------------------------------------------
		Project 4
		Programmer: Amelia Joyner
		// ---------------------------------------------------------------------------
		*/
		// ---------------------------------------------------------------------------
		//Start
		double playerHitPoints = 100;
		double playerStaminaPoints = 100;
		Item* armor;
		Item* weapon;
		//End
		// ---------------------------------------------------------------------------
};
#endif
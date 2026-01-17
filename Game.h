// ---------------------------------------------------------------------------
// Group: 5
// Names: Christian Tampus, William Weatherby, Kori Gray, Amelia Joyner
// Course-Section: CS-355-01
// Assignment: Project #4 IF Your Turn - MAJOR CAPSTONE IF PROJECT
// Date due: 03/16/2025
// Description: This program is the IF (Interactive Fiction) game engine that can parse/handle any .IFD formated game files.
// ---------------------------------------------------------------------------
#ifndef H_GAME
#define H_GAME
#include "MapV2.h"
#include "Player.h"
#include "BasicPlayer.h"
#include "HPSPPlayer.h"
#include "CombatPlayer.h"
class Game{
	private:
		Player* player1;
		MapV2 map;
  	public:
		Game();
		void play();
		void resetGame();
		/*
		// ---------------------------------------------------------------------------
		Project 4
		Programmer: Christian Tampus
		// ---------------------------------------------------------------------------
		*/
		// ---------------------------------------------------------------------------
		//Start
		void displayHelp();
		//End
		// ---------------------------------------------------------------------------
};
#endif
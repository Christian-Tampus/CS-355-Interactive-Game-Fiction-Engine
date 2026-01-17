// ---------------------------------------------------------------------------
// Group: 5
// Names: Christian Tampus, William Weatherby, Kori Gray, Amelia Joyner
// Course-Section: CS-355-01
// Assignment: Project #4 IF Your Turn - MAJOR CAPSTONE IF PROJECT
// Date due: 03/16/2025
// Description: This program is the IF (Interactive Fiction) game engine that can parse/handle any .IFD formated game files.
// ---------------------------------------------------------------------------
//Headers
#ifndef H_HPSPPLAYER
#define H_HPSPPLAYER
//Dependencies
#include "Player.h"
//Class Declaration
class HPSPPlayer : public Player
{
	public:
		HPSPPlayer();
		//Set Game End Reason
		void setGameEndReason(std::string) override;
		int isGameOver() override;
		void resetPlayerStats() override;
		void reportStats() override;
		void consume(Map* mapptr) override;
		void use(Map* mapptr) override;
		//Helper Method To Optimize The Use/Consume Commands
		void useOrConsumeItem(Map* mapptr, bool isUseItem, std::string prompt);
	private:
		int playerHitPoints = 100;
		int playerSanityPoints = 100;
};
#endif
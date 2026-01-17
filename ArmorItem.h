// ---------------------------------------------------------------------------
// Group: 5
// Names: Christian Tampus, William Weatherby, Kori Gray, Amelia Joyner
// Course-Section: CS-355-01
// Assignment: Project #4 IF Your Turn - MAJOR CAPSTONE IF PROJECT
// Date due: 03/16/2025
// Description: This program is the IF (Interactive Fiction) game engine that can parse/handle any .IFD formated game files.
// ---------------------------------------------------------------------------
//Headers
#ifndef H_ARMORITEM
#define H_ARMORITEM
//Dependencies
#include "Item.h"
//Namespaces
using namespace std;
//Class Declaration
class ArmorItem : public Item
{
	public:
		/*
		// ---------------------------------------------------------------------------
		Project 4
		Programmer: Kori Gray
		// ---------------------------------------------------------------------------
		*/
		// ---------------------------------------------------------------------------
		//Start
		void setDurability(double) override;
		void setAbsorption(int) override;
		double getDurability() override;
		double getInitialDurability() override;
		int getAbsorption() override;
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
		void resetDurability();
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
		void updateDurability(double) override;
		void setBreakMess(string) override;
		string getBreakMess() override;
		//End
		// ---------------------------------------------------------------------------
	private:
		double durability;
		double initialDurability;
		int absorption;
		string breakMess;
};
#endif
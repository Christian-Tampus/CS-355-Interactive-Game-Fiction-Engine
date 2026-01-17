// ---------------------------------------------------------------------------
// Group: 5
// Names: Christian Tampus, William Weatherby, Kori Gray, Amelia Joyner
// Course-Section: CS-355-01
// Assignment: Project #4 IF Your Turn - MAJOR CAPSTONE IF PROJECT
// Date due: 03/16/2025
// Description: This program is the IF (Interactive Fiction) game engine that can parse/handle any .IFD formated game files.
// ---------------------------------------------------------------------------
//Headers
#ifndef H_USEITEM
#define H_USEITEM
//Dependencies
#include "Item.h"
//Namespaces
using namespace std;
//Class Declaration
class UseItem : public Item
{
	public:
		void setActiveMessage(std::string) override;
		std::string getActiveMessage();
		void setActiveArea(int);
		int getActiveArea();
		void addRule(Rule*);
		std::vector<Rule*> getItemUseRules();
		void addEffect(Effect* temp);
		std::vector<Effect*> getItemConsumeEffects();
	private:
		std::vector<Rule*> rulesVector;
		std::vector<Effect*> effectsVector;
};
#endif
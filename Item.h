// ---------------------------------------------------------------------------
// Group: 5
// Names: Christian Tampus, William Weatherby, Kori Gray, Amelia Joyner
// Course-Section: CS-355-01
// Assignment: Project #4 IF Your Turn - MAJOR CAPSTONE IF PROJECT
// Date due: 03/16/2025
// Description: This program is the IF (Interactive Fiction) game engine that can parse/handle any .IFD formated game files.
// ---------------------------------------------------------------------------
//Headers
#ifndef H_ITEM
#define H_ITEM
//Dependencies
#include <string>
#include <iostream>
#include <vector>
#include "structs.h"
//Namespaces
using namespace std;
//Class Declaration
class Item
{
	public:
		Item();
		void setName(std::string);
		void setDesc(std::string);
		void setSR(int);
		std::string getName();
		std::string getDesc();
		int getSR();
		void displayName();
		void displayDesc();
		std::string getType();
		friend ostream& operator<<(ostream&, Item&);
		//Update Item Used Boolean
		void updateItemUsedBoolean(bool);
		//Check If Has Used The Item
		bool hasUsedItem();
		virtual void setActiveMessage(std::string);
		virtual std::string getActiveMessage();
		virtual void setActiveArea(int);
		virtual int getActiveArea();
		virtual void addRule(Rule*);
		virtual std::vector<Rule*> getItemUseRules();
		virtual void addEffect(Effect* temp);
		virtual std::vector<Effect*> getItemConsumeEffects();
		/*
		// ---------------------------------------------------------------------------
		Project 4
		Programmer: William Weatherby
		// ---------------------------------------------------------------------------
		*/
		// ---------------------------------------------------------------------------
		//Start
		virtual void setQuantity(int);
		virtual int getQuantity();
		virtual void updateQuantity(int);
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
		virtual void resetQuantity();
		virtual void resetDurability();
		virtual void setStaminaUse(int);
		virtual int getStaminaUse();
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
		virtual void setDamage(int);
		virtual void setAffinity(string);
		virtual int getDamage();
		virtual string getAffinity();
		virtual void setDurability(double);
		virtual void setAbsorption(int);
		virtual double getDurability();
		virtual double getInitialDurability();
		virtual int getAbsorption();
		void setType(string);
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
		virtual void setAttackMess(string);
		virtual string getAttackMess();
		virtual void updateDurability(double);
		virtual void setBreakMess(string);
		virtual string getBreakMess();
		//End
		// ---------------------------------------------------------------------------
	protected:
		std::string itemName;
		std::string itemDescription;
		int SR;
		std::string activeMessage;
		int activeArea;
		std::string type;
		//Item Used Boolean To Prevent Use Items From Being Re-Used After Activation
		bool itemUsed = false;
};
#endif
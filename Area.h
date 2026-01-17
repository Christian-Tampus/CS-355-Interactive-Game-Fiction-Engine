// ---------------------------------------------------------------------------
// Group: 5
// Names: Christian Tampus, William Weatherby, Kori Gray, Amelia Joyner
// Course-Section: CS-355-01
// Assignment: Project #4 IF Your Turn - MAJOR CAPSTONE IF PROJECT
// Date due: 03/16/2025
// Description: This program is the IF (Interactive Fiction) game engine that can parse/handle any .IFD formated game files.
// ---------------------------------------------------------------------------
//
//Headers
#ifndef H_AREA
#define H_AREA
//Dependencies
#include "ull.h"
#include "Item.h"
#include "Enemy.h"
#include <string>
#include <iostream>
//Namespaces
using namespace std;
//Class Declaration
class Area{
  public:
    void setDescription (string);
    void setGoal(bool);
    void setID(bool);
    string getDescription();
    bool getID();
    bool getGoal();
    void displayArea();
    uLList<Item*> items;
    /*
	// ---------------------------------------------------------------------------
	Project 4
	Programmer: William Weatherby
	// ---------------------------------------------------------------------------
	*/
	// ---------------------------------------------------------------------------
	//Start
	uLList<Enemy*> enemies;
	//End
	// ---------------------------------------------------------------------------
    void search();
  private:
     string description;
     bool instadeath;
     bool goal;
};
#endif
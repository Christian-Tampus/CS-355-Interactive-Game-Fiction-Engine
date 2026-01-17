// ---------------------------------------------------------------------------
// Group: 5
// Names: Christian Tampus, William Weatherby, Kori Gray, Amelia Joyner
// Course-Section: CS-355-01
// Assignment: Project #4 IF Your Turn - MAJOR CAPSTONE IF PROJECT
// Date due: 03/16/2025
// Description: This program is the IF (Interactive Fiction) game engine that can parse/handle any .IFD formated game files.
// ---------------------------------------------------------------------------
#ifndef H_MAP
#define H_MAP
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "areaNode.h"
#include "IFDParser.h"
#include "LinkData.h"
#include "Area.h"
using namespace std;
class Map{
	protected:
		vector<areaNode*> areasVec;
		int areacnt;
	  	IFDParser parser;
        vector<LinkData*> linkVec;
		string nextToken;
		bool ifderr;
	public:
	    Map();
	    void buildMap();
		void makeArea();
		void makeLinks();
		void linkLinks();
		areaNode* getStart();
		int reverseLookUp(areaNode*);
		friend ostream& operator<<(ostream&, Map&);
		vector<areaNode*> getAreasVec();
		/*
		// ---------------------------------------------------------------------------
		Project 4
		Programmer: Christian Tampus
		// ---------------------------------------------------------------------------
		*/
		// ---------------------------------------------------------------------------
		//Start
		virtual Item* getItem(string);
		//End
	    // ---------------------------------------------------------------------------
};
#endif
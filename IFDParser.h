// ---------------------------------------------------------------------------
// Group: 5
// Names: Christian Tampus, William Weatherby, Kori Gray, Amelia Joyner
// Course-Section: CS-355-01
// Assignment: Project #4 IF Your Turn - MAJOR CAPSTONE IF PROJECT
// Date due: 03/16/2025
// Description: This program is the IF (Interactive Fiction) game engine that can parse/handle any .IFD formated game files.
// ---------------------------------------------------------------------------
#ifndef H_IFDPARSER
#define H_IFDPARSER
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
using namespace std;
class IFDParser{
	public:
		IFDParser();
        void tokenIt();
        void eatToken();
        string getNext();
        void trim(string& s);
        void printTokens();
	private:
		int pos;
		string gameFile;
        vector<string> tokenVec;
};
#endif
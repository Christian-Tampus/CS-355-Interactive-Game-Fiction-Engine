// ---------------------------------------------------------------------------
// Group: 5
// Names: Christian Tampus, William Weatherby, Kori Gray, Amelia Joyner
// Course-Section: CS-355-01
// Assignment: Project #4 IF Your Turn - MAJOR CAPSTONE IF PROJECT
// Date due: 03/16/2025
// Description: This program is the IF (Interactive Fiction) game engine that can parse/handle any .IFD formated game files.
// ---------------------------------------------------------------------------
#include <iostream>
#include "IFDParser.h"
IFDParser::IFDParser()
{
    pos = 0;
    gameFile = "DragonCrawl3.ifd";
    //--------------------------------------------------
    //Assignment #2 - Load Any IFD File
    //Declare variables & request user to enter the IF game file name
    std::string userInput;
    std::cout << "Please Enter A Valid Interactive Fiction Game File (.ifd) [Type 'd' For The Default 'DragonCrawl3.ifd' Game File]." << std::endl;
    std::cout << "Example Input:OhioRing.ifd" << std::endl;
    std::cout << "Input:";
	/*
		*IMPORTANT NOTE: I did not put any extra input validation like i normally would for the userInput to update the gameFile since the specifications states that we can assume that the file is an actual IFD formatted file
		*IMPORTANT NOTE: and that we are assuming that the user enters the correct file name input like SpaceEscape.ifd or OhioRing.ifd
		*ALSO: Try out my game OhioRing.ifd :)
	*/
	//Check if userInput does not equal 'd' for the default gameFile, if true then update gameFile to userInput, if false then do nothing to keep gameFile equal to the default 'DragonCrawl.ifd' file
	std::getline(std::cin,userInput);
	if (userInput != "d")
	{
		this->gameFile = userInput;
	};
	std::cout << "Now Loading Interactive Fiction Game: '" << this->gameFile << "'..." << std::endl;
    //--------------------------------------------------
}
void IFDParser::tokenIt()
{
    string token="";
    string nextLine;
    char c;
    ifstream inFile;
    inFile.open(gameFile.c_str());
    while(!inFile.eof()){
        getline(inFile, nextLine);
        trim(nextLine);
        c=nextLine[0];

        //dump any comment or blank line (all comments exist alone on their lines)
        if(c=='%' || nextLine == ""){
            //do nothing
        }
        else{
            //tokenize the entire line
            //cout<<nextLine<<endl;
            for(int i=0; i<nextLine.length(); i++){
                if(nextLine[i] == '>'){
                    token = token + nextLine[i];
                    if(token !="\n" && token !="" && token !=" " && token !="\t"){
                        tokenVec.push_back(token);
                    }
                    token = "";
                }
                else if(nextLine[i]=='<'){
                    if(token !="\n" && token !="" && token !=" " && token !="\t"){
                        tokenVec.push_back(token);
                    }
                    token = "";
                    token = token + nextLine[i];
                }
                else{
                    token = token + nextLine[i];
                }
            }
        }
    }//while !eof
    inFile.close();
    return;
}// end of tokenIt()
void IFDParser::eatToken()
{
    pos++;
}
string IFDParser::getNext(){
    return tokenVec[pos];
}
//helper function for trimming a string's white space
void IFDParser::trim(string& s)
{
    size_t p = s.find_first_not_of(" \t");
    s.erase(0, p);
    p = s.find_last_not_of(" \t");
    if (string::npos != p)
    {
        s.erase(p+1);
    }
}
void IFDParser::printTokens()
{
    cout<<":::Printing the Tokens in Order:::"<<endl;
    for(int i=0; i<tokenVec.size(); i++){
        cout<<i<<": "<<tokenVec[i]<<endl;
    }
}
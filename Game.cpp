// ---------------------------------------------------------------------------
// Group: 5
// Names: Christian Tampus, William Weatherby, Kori Gray, Amelia Joyner
// Course-Section: CS-355-01
// Assignment: Project #4 IF Your Turn - MAJOR CAPSTONE IF PROJECT
// Date due: 03/16/2025
// Description: This program is the IF (Interactive Fiction) game engine that can parse/handle any .IFD formated game files.
// ---------------------------------------------------------------------------
#include <iostream>
#include "Game.h"
Game::Game(){
    map.buildMap();
    std::string playerType = this->map.playerType;
    if (playerType == "basic")
    {
    	std::cout << "Creating Basic Player Type ... ";
		this->player1 = new BasicPlayer();
		std::cout << "READY!" << std::endl;
	}
	else if (playerType == "hpsp")
	{
		std::cout << "Creating HPSP Player Type ... ";
		this->player1 = new HPSPPlayer();
		std::cout << "READY!" << std::endl;
	}
	/*
	// ---------------------------------------------------------------------------
	Project 4
	Programmer: Amelia Joyner
	// ---------------------------------------------------------------------------
	*/
	// ---------------------------------------------------------------------------
	//Start
	else if (playerType == "combat")
	{
		cout << "Creating Combat Player Type ...";
		player1 = new CombatPlayer();
		cout << "READY!" << endl;
	};
	//End
	// ---------------------------------------------------------------------------
    this->player1->setCurrent(map.getStart());
}
void Game::play(){
	//Constants
	const std::string standardGameEndReason = "InstaDeathOrGoalRooms";
	const int numberOfCommands = 13;
	const std::string KEY_WORDS_ARRAY[numberOfCommands] = {"reset","search","inventory","take","leave","examine","help","stats","use","consume","equip","unequip","attack"};
    string userInput;
    /*
	// ---------------------------------------------------------------------------
	Project 4
	Programmer: Christian Tampus
	// ---------------------------------------------------------------------------
	*/
	// ---------------------------------------------------------------------------
	//Start
	std::cout << "[GAME COMMANDS]" << std::endl;
    this->displayHelp();
    //End
	// ---------------------------------------------------------------------------
    //cin.ignore();
    while(true){
        //check game status
        if(this->player1->isGameOver() != 0){
        	//if game ended in standardGameEndReason, then just print the displayArea, if not then get the updated gameEndReason
        	if (this->player1->getGameEndReason() == standardGameEndReason)
        	{
        		this->player1->getCurrent()->info.displayArea();
			}
			else
			{
				std::cout << this->player1->getGameEndReason() << std::endl;
			}
            return;
        }
        //display area data
        if(this->player1->playerMoved()){
            this->player1->getCurrent()->info.displayArea();
        }
        else{
        	/*
        	IMPORTANT: Rewrote the logic to prevent printing out "There appears to be no way to go that direction" after entering a keyword (i.e like "search") immediately after you enter "reset" keyword
        	*/
        	bool isKeyword = false;
        	for (int index = 0; index < numberOfCommands; index++)
        	{
        		if (userInput == KEY_WORDS_ARRAY[index])
				{
        			isKeyword = true;
        			break;
				};
			};
			if (!isKeyword)
			{
				std::cout <<"There appears to be no way to go that direction." << std::endl;
			};
        }
        //get movement selection
        cout<<"Which way would you like to go?  Enter u, d, l, or r"<<endl;
        getline(cin, userInput);
        //update area
        if(userInput == "u"){
            this->player1->setCurrent(this->player1->getCurrent()->u);
        }
        else if(userInput == "d"){
            this->player1->setCurrent(this->player1->getCurrent()->d);
        }
        else if(userInput == "l"){
            this->player1->setCurrent(this->player1->getCurrent()->l);
        }
        else if(userInput == "r"){
            this->player1->setCurrent(this->player1->getCurrent()->r);
        }
        else if(userInput == "iseedeadpeople"){ //issdeadpeople cheat code to reveal map
            //map.print();
            cout<<map;
        }
        else if(userInput == "reset"){
            resetGame();
        }
        else if(userInput == "exit"){
            cout<<"Good bye!"<<endl;
            return;
        }
        else if(userInput == "search"){
            this->player1->getCurrent()->info.search();
        }
        else if(userInput == "inventory"){
            this->player1->inventory();
        }
        else if(userInput == "take"){
            this->player1->take();
        }
        else if(userInput == "leave"){
            this->player1->leave();
        }
        else if(userInput == "examine"){
            this->player1->examine();
        }
        else if(userInput == "stats")
        {
        	this->player1->reportStats();
		}
		else if(userInput == "use")
		{
			Map* currentMap = &this->map;
			this->player1->use(currentMap);
		}
		else if (userInput == "consume")
		{
			Map* currentMap = &this->map;
			this->player1->consume(currentMap);
		}
		/*
		// ---------------------------------------------------------------------------
		Project 4
		Programmer: Amelia Joyner
		// ---------------------------------------------------------------------------
		*/
		// ---------------------------------------------------------------------------
		//Start
		else if (userInput == "equip")
		{
			this->player1->equip();
		} 
		else if (userInput == "unequip")
		{
			this->player1->unequip();
		}
		else if (userInput == "attack")
		{
			Map* currentMap = &this->map;
			this->player1->attackEnemy(currentMap);
		}
		//End
		// ---------------------------------------------------------------------------
        else if(userInput == "help"){
        	/*
			// ---------------------------------------------------------------------------
			Project 4
			Programmer: Christian Tampus
			// ---------------------------------------------------------------------------
			*/
			// ---------------------------------------------------------------------------
			//Start
        	this->displayHelp();
        	//End
			// ---------------------------------------------------------------------------
        }
        else{
            cout<<"I do not understand: "<<userInput<<endl<<endl;
        }
    }//end while
}//end play()
void Game::resetGame(){
    this->player1->setCurrent(map.getStart());
    this->player1->items.destroyList();
    this->player1->resetPlayerStats();
    map.resetItems();
};
void Game::displayHelp()
{
	cout<<"You may type: "<<endl;
    cout<<"\t u, d, l, or r: to move up, down, left or right on the map,"<<endl;
    cout<<"\t search: to search for items in current area,"<<endl;
    cout<<"\t take: to attempt to take an item,"<<endl;
    cout<<"\t leave: to attempt to leave an item,"<<endl;
    cout<<"\t examine: to examine an item in your inventory,"<<endl;
    std::cout << "\t inventory: to check what items are in your inventory," << std::endl;
    std::cout << "\t stats: to check your player's stats," << std::endl;
    std::cout << "\t use: to use a item," << std::endl;
    std::cout << "\t consume: to consume an item," << std::endl;
    /*
	// ---------------------------------------------------------------------------
	Project 4
	Programmer: Christian Tampus
	// ---------------------------------------------------------------------------
	*/
	// ---------------------------------------------------------------------------
	//Start
	std::cout << "\t equip: to equip an item in your inventory," << std::endl;
	std::cout << "\t unequip: to unequip an item in your inventory," << std::endl;
	std::cout << "\t attack: to attack an enemy inside your current area," << std::endl;
	//End
	// ---------------------------------------------------------------------------
    std::cout << "\t help: to display the commands in the game," << std::endl;
    cout<<"\t reset: to reset the game,"<<endl;
    cout<<"\t exit: to exit the game."<<endl;
	std::cout << "___________________________________________________________________________" << std::endl;
};
/*
 In this file shall live all the upkeep related function definitions that
 are outlined in upkeep.hpp.
 */

/* Declare our standard C++ headers. */
#include <time.h>
#include <iostream>

/* Our project headers */
#include "upkeep.h"
#include "player.h"

/*
 Prints instructions for the game if the player requests them at initialization
 of game
 */
void PrintInstructions(void)
{
    std::cout << "\nYou are the ruler of a 15th century Italian city state.\n";
    std::cout << "If you rule well, you will receive higher titles. The\n";
    std::cout << "first player to become king or queen wins. Life expectancy\n";
    std::cout << "then was brief, so you may not live long enough to win.\n";
    std::cout << "The computer will draw a map of your state. The size\n";
    std::cout << "of the area in the wall grows as you buy more land. The\n";
    std::cout << "size of the guard tower in the upper left corner shows\n";
    std::cout << "the adequacy of your defenses. If it shrinks, equip more\n";
    std::cout << "soldiers! If the horse and plowman is touching the top of the wall,\n";
    std::cout << "all your land is in production. Otherwise you need more\n";
    std::cout << "serfs, who will migrate to your state if you distribute\n";
    std::cout << "more grain than the minimum demand. If you distribute less\n";
    std::cout << "grain, some of your people will starve, and you will have\n";
    std::cout << "a high death rate. High taxes raise money, but slow down\n";
    std::cout << "economic growth. (The game will now begin)\n\n";
    return;
}

/*
 This function will get user input to define the number of players.
 */
void getPlayers(int &NumOfPlayers)
{
    int people = 1; // Init to 1 since at least 1 player must play
    
    std::cout << "\nHow many people want to play (1 to 6)? ";
    std::cin >> people;
    
    while(people < 0 || people > 6)
    {
        // Check for correct input and allow user to correct
        std::cout << "\nPlease remember that only 1 to 6 players can play!\n";
        std::cout << "How many people want to play (1 to 6)? ";
        std::cin >> people;
    }
    
    NumOfPlayers = people;
}

/*
 Creates a random number, takes in int and returns a random number b/w 0-Hi
 */
int Random(int Hi)
{
    int randHi;
    randHi = rand() % (Hi + 1); // random b/w 0-Hi
    return randHi;
}

/*
 Takes in player object and prints the grain in respect to the input player
 */
void PrintGrain(player *Me)
{
	switch(Me->Harvest)
	{
		case 0:
		case 1: std::cout << "Drought. Famine Threatens.\n"; break;
		case 2: std::cout << "Bad Weather. Poor Harvest.\n"; break;
		case 3: std::cout << "Normal Weather. Average Harvest.\n"; break;
		case 4: std::cout << "Good Weather. Fine Harvest.\n"; break;
		case 5: std::cout << "Excellent Weather. Great Harvest!\n"; break;
	}
	return;
}

/*

 */
int ReleaseGrain(player *Me)
{
    double xp, zp;
    float x, z;
    char string[256];
    int HowMuch, Maximum, Minimum;
    bool IsOK = false;
    std::string input;

    Minimum = Me->GrainReserve / 5;
    Maximum = (Me->GrainReserve - Minimum);

    while(IsOK == false)
    {
	    std::cout <<"How much grain will you release for consumption?\n";
	    std::cout <<"1 = Minimum (" << Minimum << "), 2 = Maximum(" << Maximum << "), or enter a value: ";
	    std::cin >> HowMuch;

	    // HowMuch = (int)atoi(string);
	    if(HowMuch == 1)
	        HowMuch = Minimum;
        if(HowMuch == 2)
            HowMuch = Maximum;
	    /* Are we being a Scrooge? */
	        if(HowMuch < Minimum)
	    std::cout <<"You must release at least 20% of your reserves.\n";
	    /* Whoa. Slow down there son. */
	        else if(HowMuch > Maximum)
	    std::cout << "You must keep at least 20%.\n";
	        else
	        IsOK = true;
    }

    Me->SoldierPay = Me->MarketRevenue = Me->NewSerfs = Me->DeadSerfs = 0;
    Me->TransplantedSerfs = Me->FleeingSerfs = 0;
    Me->InvadeMe = false;
    Me->GrainReserve -= HowMuch;
    z = (float)HowMuch / (float)Me->GrainDemand - 1.0;
    if(z > 0.0)
    	z /= 2.0;
    if(z > 0.25)
    	z = z / 10.0 + 0.25;
    zp = 50.0 - (double)Me->CustomsDuty - (double)Me->SalesTax -
        (double)Me->IncomeTax;
    if(zp < 0.0)
    	zp *= (double)Me->Justice;
    	zp /= 10.0;
    if(zp > 0.0)
    	zp += (3.0 - (double)Me->Justice);
    	z += ((float)zp / 10.0);
    if(z > 0.5)
    	z = 0.5;
    if(HowMuch < (Me->GrainDemand - 1))
    {
	    x = ((float)Me->GrainDemand - (float)HowMuch) / (float)Me->GrainDemand * 100.0 - 9.0;
	    xp = (double)x;
	    if(x > 65.0)
	    	x = 65.0;
	    if(x < 0.0)
	    {
		    xp = 0.0;
		    x = 0.0;
	    }

	    SerfsProcreating(Me, 3.0);
	    SerfsDecomposing(Me, xp + 8.0);
    }

    else
    {
	    SerfsProcreating(Me, 7.0);
	    SerfsDecomposing(Me, 3.0);

	    if((Me->CustomsDuty + Me->SalesTax) < 35)
	   		Me->Merchants += Random(4);
	    if(Me->IncomeTax < Random(28))
	    {
		    Me->Nobles += Random(2);
		    Me->Clergy += Random(3);
	    }
	    if(HowMuch > (int)((float)Me->GrainDemand * 1.3))
	    {
		    zp = (double)Me->Serfs / 1000.0;
		    z = ((float)HowMuch - (float)(Me->GrainDemand)) / (float)Me->GrainDemand * 10.0;
		    z *= ((float)zp * (float)Random(25));
		    z += (float)Random(40);
	        Me->TransplantedSerfs = (int)z;
	        Me->Serfs += Me->TransplantedSerfs;
	        std::cout << Me->TransplantedSerfs << " serfs move to the city\n";
		    zp = (double)z;
		    z = ((float)zp * (float)rand()) / (float)RAND_MAX;

		    if(z > 50.0)
			    z = 50.0;

		    Me->Merchants += (int)z;
		    Me->Nobles++;
		    Me->Clergy += 2;
	    }
    }

    if(Me->Justice > 2)
    {
	    Me->JusticeRevenue = Me->Serfs / 100 * (Me->Justice - 2) * (Me->Justice - 2);
	    Me->JusticeRevenue = Random(Me->JusticeRevenue);
	    Me->Serfs -= Me->JusticeRevenue;
	    Me->FleeingSerfs = Me->JusticeRevenue;
        std::cout << Me->FleeingSerfs << " serfs flee harsh justice\n";
    }

    Me->MarketRevenue = Me->Marketplaces * 75;
    if(Me->MarketRevenue > 0)
    {
    	Me->Treasury += Me->MarketRevenue;
        std::cout << "Your market earned " << Me->MarketRevenue << " florins.\n";
    }

    Me->MillRevenue = Me->Mills * (55 + Random(250));
    if(Me->MillRevenue > 0)
    {
    	Me->Treasury += Me->MillRevenue;
        std::cout << "Your woolen mill earned " << Me->MillRevenue << " florins.\n";
    }

    Me->SoldierPay = Me->Soldiers * 3;
    Me->Treasury -= Me->SoldierPay;
    std::cout << "You paid your soldiers " << Me->SoldierPay << " florins.\n";
    std::cout << "You have " << Me->Serfs << " serfs in your city.\n";
    std::cout << "(Press ENTER): ";
    std::cin >> input;

    if((Me->Land / 1000) > Me->Soldiers)
    {
    	Me->InvadeMe = true;
    	return(3);
    }

    if((Me->Land / 500) > Me->Soldiers)
    {
    	Me->InvadeMe = true;
    	return(3);
    }

    return(0);
}

/*
	When the player has gone bankrupt, this function is called to alert the player
*/
void SeizeAssets(player *Me)
{
    std::string enter;

    Me->Marketplaces = 0;
    Me->Palace = 0;
    Me->Cathedral = 0;
    Me->Mills = 0;
    Me->Land = 6000;
    Me->PublicWorks = 1.0;
    Me->Treasury = 100;
    Me->IsBankrupt = false;
    std::cout << "\n\n" << Me->Title << " " << Me->Name << " is bankrupt.\n";
    std::cout << "\nCreditors have seized much of your assets.\n";
    std::cout << "\n(Press ENTER): ";
    std::cin >> enter;
    return;
}


/*
	Calculates the number of Serfs that died in the turn phase of the player
*/
void SerfsDecomposing(player *Me, float MyScale)
{
    int absc;
    float ord;
    absc = (int)MyScale;
    ord = MyScale - (float)absc;

    Me->DeadSerfs = (int)((((float)Random(absc) + ord) * (float)Me->Serfs) / 100.0);
    Me->Serfs -= Me->DeadSerfs;
    std::cout << Me->DeadSerfs << " serfs die this year.\n";
    return;
}

/*
	Calculates the number of Serfs born in the turn phase of the player
*/
void SerfsProcreating(player *Me, float MyScale)
{
    int absc;
    float ord;
    absc = (int)MyScale;
    ord = MyScale - (float)absc;
    Me->NewSerfs = (int)((((float)Random(absc) + ord) * (float)Me->Serfs) / 100.0);
    Me->Serfs += Me->NewSerfs;
    std::cout << Me->NewSerfs << " serfs born this year.\n";
    return;
}

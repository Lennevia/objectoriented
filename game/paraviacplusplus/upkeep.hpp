/*
 In this file will live all details in relationship to the upkeep
 of the game, whether that be in the setup of the intial game, or
 the updates taken between turns of the game
 
 Needed definitions for the outlined details below can be found in
 actions.cpp
 */

#ifndef UPKEEP_HPP
#define UPKEEP_HPP

#include "player.hpp"
#include "actions.hpp"

void PrintInstructions(void);
int Random(int);
void getPlayers(int&);
void PrintGrain(player *);
void SerfsDecomposing(player *, float);
void SerfsProcreating(player *, float);
void AddRevenue(player *);
int AttackNeighbor(player *, player *);
int limit10(int, int);
bool CheckNewTitle(player *);
void GenerateHarvest(player *);
void GenerateIncome(player *);
void ChangeTitle(player *);
void NewLandAndGrainPrices(player *);
int ReleaseGrain(player *);
void SeizeAssets(player *);
void NewTurn(player *, int, player [], player *);
void AdjustTax(player *);
void StatePurchases(player *, int, player []);
void ShowStats(player [], int);
void ImDead(player *);


/*
 In this file shall live all the upkeep related function definitions that
 are outlined in upkeep.hpp.
 */

/* Declare our standard C++ headers. */
#include <time.h>
#include <iostream>

/* Our project headers */
#include "upkeep.hpp"
#include "player.hpp"

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
void ChangeTitle(player *Me)
{
    if(Me->MaleOrFemale == true)
    	(Me->Title).assign(MaleTitles[Me->TitleNum]);
        // strcpy(Me->Title, MaleTitles[Me->TitleNum]);
    else
    	(Me->Title).assign(FemaleTitles[Me->TitleNum]);
        // strcpy(Me->Title, FemaleTitles[Me->TitleNum]);

    if(Me->TitleNum == 7)
    {
        Me->IWon = true;
        return;
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

/*
    Calculates the number of Serfs born in the turn phase of the player
*/
void AddRevenue(player *Me)
{
    Me->Treasury += (Me->JusticeRevenue + Me->CustomsDutyRevenue);
    Me->Treasury += (Me->IncomeTaxRevenue + Me->SalesTaxRevenue);
    
    /* Penalize deficit spending. */
    if(Me->Treasury < 0)
        Me->Treasury = (int)((float)Me->Treasury * 1.5);
    
    /* Will a title make the creditors happy (for now)? */
    if(Me->Treasury < (-10000 * Me->TitleNum))
        Me->IsBankrupt = true;
    
    return;
}

/*
   
*/
int AttackNeighbor(player *Me, player *Him)
{
    int LandTaken;
    int deadsoldiers = 0;

    if(Me->WhichPlayer == 7)
        LandTaken = Random(9000) + 1000;
    else
        LandTaken = (Me->Soldiers * 1000) - (Me->Land / 3);
    if(LandTaken > (Him->Land - 5000))
        LandTaken = (Him->Land - 5000) / 2;
    Me->Land += LandTaken;
    Him->Land -= LandTaken;

    std::cout << "\n" << Me->Title << " " << Me->Name << " of " << Me->City 
              << " invades and seizes " << LandTaken << " hectares of land!\n";

    deadsoldiers = Random(40);
    if(deadsoldiers > (Him->Soldiers - 15))
        deadsoldiers = Him->Soldiers - 15;
    Him->Soldiers -= deadsoldiers;

    std::cout << Him->Title << " " << Him->Name << " loses " << deadsoldiers
              << " soldiers in battle.\n";

    return(LandTaken);
}

/*
   Limits buying of things to ten
*/
int limit10(int num, int denom)
{
    int val;
    val = num / denom;
    return(val > 10 ? 10 : val);
}

/*
   Check new title to see if we have progressed enough in game for
   a change up, or a change down if the player did that poorly
*/
bool CheckNewTitle(player *Me)
{
    int Total;
    /* Tally up our success so far . . . . */
    Total = limit10(Me->Marketplaces, 1);
    Total += limit10(Me->Palace, 1);
    Total += limit10(Me->Cathedral, 1);
    Total += limit10(Me->Mills, 1);
    Total += limit10(Me->Treasury, 5000);
    Total += limit10(Me->Land, 6000);
    Total += limit10(Me->Merchants, 50);
    Total += limit10(Me->Nobles, 5);
    Total += limit10(Me->Soldiers, 50);
    Total += limit10(Me->Clergy, 10);
    Total += limit10(Me->Serfs, 2000);
    Total += limit10((int)(Me->PublicWorks * 100.0), 500);

    Me->TitleNum = (Total / Me->Difficulty) - Me->Justice;
    if(Me->TitleNum > 7)
    Me->TitleNum = 7;
    if(Me->TitleNum < 0)
    Me->TitleNum = 0;

    /* Did we change (could be backwards or forwards)? */
    if(Me->TitleNum > Me->OldTitle)
    {
        Me->OldTitle = Me->TitleNum;
        ChangeTitle(Me);

        std::cout << "\nGood news! " << Me->Name << " has achieved the rank of "
                  << Me->Title << "\n\n";

        return(true);
    }
        
    Me->TitleNum = Me->OldTitle;
    return(false);
}

/*
   Randomly generates the new harvest for the new turn
*/
void GenerateHarvest(player *Me)
{
    Me->Harvest = (Random(5) + Random(6)) / 2;
    Me->Rats = Random(50);
    Me->GrainReserve = ((Me->GrainReserve * 100) -
            (Me->GrainReserve * Me->Rats)) / 100;
    return;
}

/*
   
*/
void GenerateIncome(player *Me)
{
    float y;
    int revenues = 0;
    char string[256];
    Me->JusticeRevenue = (Me->Justice * 300 - 500) * Me->TitleNum;
    switch(Me->Justice)
    {
        case 1: strcpy(string, "Very Fair"); break;
        case 2: strcpy(string, "Moderate"); break;
        case 3: strcpy(string, "Harsh"); break;
        case 4: strcpy(string, "Outrageous");
    }
    y = 150.0 - (float)Me->SalesTax - (float)Me->CustomsDuty -
        (float)Me->IncomeTax;
    if(y < 1.0)
    y = 1.0;
    y /= 100.0;

    Me->CustomsDutyRevenue = Me->Nobles * 180 + Me->Clergy * 75 +
         Me->Merchants * 20 * y;
    Me->CustomsDutyRevenue += (int)(Me->PublicWorks * 100.0);
    Me->CustomsDutyRevenue = (int)((float)Me->CustomsDuty / 100.0 *
             (float)Me->CustomsDutyRevenue);
    Me->SalesTaxRevenue = Me->Nobles * 50 + Me->Merchants * 25 +
         (int)(Me->PublicWorks * 10.0);
    Me->SalesTaxRevenue *= (y * (5 - Me->Justice) * Me->SalesTax);
    Me->SalesTaxRevenue /= 200;
    Me->IncomeTaxRevenue = Me->Nobles * 250 + (int)(Me->PublicWorks * 20.0);
    Me->IncomeTaxRevenue += (10 * Me->Justice * Me->Nobles * y);
    Me->IncomeTaxRevenue *= Me->IncomeTax;
    Me->IncomeTaxRevenue /= 100;
    revenues = Me->CustomsDutyRevenue + Me->SalesTaxRevenue +
        Me->IncomeTaxRevenue + Me->JusticeRevenue;

    std::cout << "State Revenue " << revenues << " gold florins.\n";    
    std::cout << "Customs Duty: " << Me->CustomsDutyRevenue << "\n";
    std::cout << "Sales Tax: " << Me->SalesTaxRevenue << "\n";
    std::cout << "Income Tax: " << Me->IncomeTaxRevenue << "\n";
    std::cout << "Justice: " << Me->JusticeRevenue << "\n";
    std::cout << string << "\n\n";

    // printf("Customs Duty\tSales Tax\tIncome Tax\tJustice\n");
    // printf("%d\t\t%d\t\t%d\t\t%d %s\n", ,
    //         Me->SalesTaxRevenue, Me->IncomeTaxRevenue,
    //         Me->JusticeRevenue, string);
    return;
}

/*
   
*/
void NewLandAndGrainPrices(player *Me)
{
    float x, y, MyRandom;
    int h;
    /* Generate an offset for use in later int->float conversions. */
    MyRandom = (float)((float)rand() / (float)RAND_MAX);
    /* If you think this C code is ugly, you should see the original BASIC. */
    x = (float)Me->Land;
    y = (((float)Me->Serfs - (float)Me->Mills) * 100.0) * 5.0;

    if(y < 0.0)
        y = 0.0;

    if(y < x)
        x = y;

    y = (float)Me->GrainReserve * 2.0;
    if(y < x)
        x = y;

    y = (float)Me->Harvest + (MyRandom - 0.5);
    h = (int)(x * y);
    Me->GrainReserve += h;
    Me->GrainDemand = (Me->Nobles * 100) + (Me->Cathedral * 40) +
         (Me->Merchants * 30);
    Me->GrainDemand += ((Me->Soldiers * 10) + (Me->Serfs * 5));
    Me->LandPrice = (3.0 * (float)Me->Harvest + (float)Random(6) + 10.0) / 10.0;

    if(h < 0)
        h *= -1;
    if(h < 1)
        y = 2.0;
    else
    {
        y = (float)((float)Me->GrainDemand / (float)h);
        if(y > 2.0)
            y = 2.0;
    }

    if(y < 0.8)
        y = 0.8;

    Me->LandPrice *= y;
    if(Me->LandPrice < 1.0) Me->LandPrice = 1.0;
        Me->GrainPrice = (int)(((6.0 - (float)Me->Harvest) * 3.0 + (float)Random(5)
                + (float)Random(5)) * 4.0 * y);

    Me->RatsAte = h;
    return;
}

/*
   
*/
void NewTurn(player *Me, int HowMany, player MyPlayers[6], player *Baron)
{
    int i;
    GenerateHarvest(Me);
    NewLandAndGrainPrices(Me);
    BuySellGrain(Me);
    ReleaseGrain(Me);
    if(Me->InvadeMe == true)
    {
        for(i = 0; i < HowMany; i++)
            if(i != Me->WhichPlayer)
                if(MyPlayers[i].Soldiers > (Me->Soldiers * 2.4))
                {
                    AttackNeighbor(&MyPlayers[i], Me);
                    i = 9;
                }
        if(i != 9)
            AttackNeighbor(Baron, Me);
    }
    AdjustTax(Me);

    StatePurchases(Me, HowMany, MyPlayers);
    CheckNewTitle(Me);
    
    Me->Year++;
    if(Me->Year == Me->YearOfDeath)
        ImDead(Me);
    if(Me->TitleNum >= 7)
        Me->IWon = true;
}

/*
   
*/
void AdjustTax(player *Me)
{
    // char string[256];
    int val = 1, duty = 0;
    std::string[0] = '\0';
    int number = 0; //Initialize this variable that will be used throughout this function

    while(val != 0 || string[0] != 'q')
    {
        std::cout << "\n" << Me->Title << " " << Me->Name << "\n\n";
        GenerateIncome(Me);
        std::cout << "1. Customs Duty: " << Me->CustomsDuty << "%\n";
        std::cout << "2. Sales Tax: " << Me->SalesTax << "%\n";
        std::cout << "3. Income Tax: " << Me->IncomeTax << "%\n";
        std::cout << "4. Justice: " << Me->Justice << "%\n";
        std::cout << "Enter tax number for changes, q to continue: ";
        std::cin << val;
        
        switch(val)
        {
            case 1: std::cout << "New customs duty (0 to 100): ";
            	std::cin >> duty;
                if(duty > 100) 
                	duty = 100;
                if(duty < 0) 
                	duty = 0;
                Me->CustomsDuty = duty;
                break;
            case 2: std::cout << "New sales tax (0 to 50): ";
            	std::cin >> duty;
                if(duty > 50) 
                	duty = 50;
                if(duty < 0) 
                	duty = 0;
                Me->SalesTax = duty;
                break;
            case 3: std::cout << "New wealth tax (0 to 25): ";
            	std::cin >> duty;
                if(duty > 25) 
                	duty = 25;
                if(duty < 0) 
                	duty = 0;
                Me->IncomeTax = duty;
                break;
            case 4: std::cout << "Justice: 1. Very fair, 2. Moderate";
                std::cout << " 3. Harsh, 4. Outrageous: ";
                std::cin >> duty;
                if(duty > 4) 
                	duty = 4;
                if(duty < 1) 
                	duty = 1;
                Me->Justice = duty;
                break;
        }
    
    }
    AddRevenue(Me);
    if(Me->IsBankrupt == true)
    SeizeAssets(Me);
}   

/*
   
*/
void StatePurchases(player *Me, int HowMany, player MyPlayers[6])
{
    char string[256];
    int val = 1;
    string[0] = '\0';

    while(val != 0 || string[0] != 'q')
    {
	    std::cout << "\n\n" << Me->Title << " " << Me->Name << "\nState purchases.\n";
	    std::cout << "\n1. Marketplace (You have: " << Me->Marketplaces << ")" 
	    		  << "Buy another for: 1000 florins\n";
	    std::cout << "\n2. Woolen mill (You have: " << Me->Mills << ")" 
	    		  << "Buy another for: 2000 florins\n";
	 	std::cout << "\n3. Palace (partial) (You have: " << Me->Palace << ")" 
	    		  << "Buy another for: 3000 florins\n";
	    std::cout << "\n4. Cathedral (partial) (You have: " << Me->Cathedral << ")" 
	    		  << "Buy another for: 5000 florins\n";
		std::cout << "5. Equip one platoon of serfs as soldiers for: 500 florins\n";

        std::cout << "\nYou have " << Me->Treasury << " gold florins.\n";
        std::cout << "\nTo continue, enter q. To compare standings, enter 6\n";
        std::cout << "Your choice: ";

        std::cin >> val;
        switch(val)
        {
            case 1: BuyMarket(Me); 
            		break;
            case 2: BuyMill(Me); 
            		break;
            case 3: BuyPalace(Me); 
            		break;
            case 4: BuyCathedral(Me); 
            		break;
            case 5: BuySoldiers(Me); 
            		break;
            case 6: ShowStats(MyPlayers, HowMany);

            default: std::cout << "\nBad choice, bye!\n";
        }
    }
    return;
}

/*
   When you are about to make StatePurchases, you have the option to see
   the stats 
*/
void ShowStats(player MyPlayers[6], int HowMany)
{
    int i = 0;
    std::string fillerInput;

    for(; i < HowMany; i++)
    {
    	std::cout << "\nStats of Player: " << MyPlayers[i].Title << " " << MyPlayers[i].Name << "\n";
    	std::cout << "Nobles: " << MyPlayers[i].Nobles << "\n";
    	std::cout << "Soldiers: " << MyPlayers[i].Soldiers << "\n";
    	std::cout << "Clergy: " << MyPlayers[i].Clergy << "\n";
    	std::cout << "Merchants: " << MyPlayers[i].Merchants << "\n";
    	std::cout << "Serfs: " << MyPlayers[i].Serfs << "\n";
    	std::cout << "Land: " << MyPlayers[i].Land << "\n";
    	std::cout << "Treasury: " << MyPlayers[i].Treasury << "\n";
    }

    std::cout << "\n(Press ENTER): ";
    std::cin >> fillerInput;
    return;
}

/*
   If you die, you get to have a reason why
*/
void ImDead(player *Me)
{
    std::string fillerInput;
    int why;
    
    std::cout << "\n\nVery sad news.\n" << Me->Title << " " << Me->Name << " has just died\n";
    std::cout << "R.I.P.\n";
    if(Me->Year > 1450)
        std::cout << "of old age after a long reign.\n";
    else
    {
        why = Random(8);
        switch(why)
        {
            case 0:
            case 1:
            case 2:
            case 3: std::cout << "of pneumonia after a cold winter in a drafty castle.\n"; break;
            case 4: std::cout << "of typhoid after drinking contaminated water.\n"; break;
            case 5: std::cout << "in a smallpox epidemic.\n"; break;
            case 6: std::cout << "after being attacked by robbers while travelling.\n"; break;
            case 7:
            case 8: std::cout << "of food poisoning.\n"; break;
        }
    }
    Me->IsDead = true;
    std::cout << "\n(Press ENTER): ";
    std::cin >> fillerInput;
    return;
}


#endif
/*
 In this file will live all details in relationship to the player
 as it pertains to the class.
 
 Needed definitions for the outlined details below can be found in
 player.cpp
 */
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

#include "upkeep.hpp"

/* Declare our list of cities. */
char CityList[7][15] = {"Santa Paravia", "Fiumaccio", "Torricella", "Molinetto",
"Fontanile", "Romanga", "Monterana"};

/* Declare our male titles. */
char MaleTitles[8][15] = {"Sir", "Baron", "Count", "Marquis", "Duke",
 "Grand Duke", "Prince", "* H.R.H. King"};

/* Declare our female titles. */
char FemaleTitles[8][15] = {"Lady", "Baroness", "Countess", "Marquise",
"Duchess", "Grand Duchess", "Princess",
            "* H.R.H. Queen"};

/* Declare our player definition. */
struct player
{
    int Cathedral;
    int Clergy;
    int CustomsDuty;
    int CustomsDutyRevenue;
    int DeadSerfs;
    int Difficulty;
    int FleeingSerfs;
    int GrainDemand;
    int GrainPrice;
    int GrainReserve;
    int Harvest;
    int IncomeTax;
    int IncomeTaxRevenue;
    int RatsAte;
    int Justice;
    int JusticeRevenue;
    int Land;
    int Marketplaces;
    int MarketRevenue;
    int Merchants;
    int MillRevenue;
    int Mills;
    int NewSerfs;
    int Nobles;
    int OldTitle;
    int Palace;
    int Rats;
    int SalesTax;
    int SalesTaxRevenue;
    int Serfs;
    int SoldierPay;
    int Soldiers;
    int TitleNum;
    int TransplantedSerfs;
    int Treasury;
    int WhichPlayer;
    int Year;
    int YearOfDeath;
    char City[15];
    char Name[25];
    char Title[15];
    float PublicWorks;
    float LandPrice;
    bool InvadeMe;
    bool IsBankrupt;
    bool IsDead;
    bool IWon;
    bool MaleOrFemale; // This is 2018, we should have a nonbinary option
    bool NewTitle;
};

/* Function definitions that use the player class */
void InitializePlayer(player *Me, int year, int city, int level, std::string name,
                      bool MorF);
// void PlayGame(player [], int);


/*
 In this file shall live all the player related function definitions that
 are outlined in player.hpp.
 */

/* Declare our standard C++ headers. */
#include <string>
#include <stdio.h>

/* Our project headers */
#include "player.hpp"
#include "upkeep.hpp"


void InitializePlayer(player *Me, int year, int city, int level, std::string name,
                      bool MorF)
{
    /* This is pretty straightforward. */
    Me->Cathedral = 0;
    (Me->City).assign(CityList[city]);
    Me->Clergy = 5;
    Me->CustomsDuty = 25;
    Me->Difficulty = level;
    Me->GrainPrice = 25;
    Me->GrainReserve = 5000;
    Me->IncomeTax = 5;
    Me->IsBankrupt = false;
    Me->IsDead = false;
    Me->IWon = false;
    Me->Justice = 2;
    Me->Land = 10000;
    Me->LandPrice = 10.0;
    Me->MaleOrFemale = MorF;
    Me->Marketplaces = 0;
    Me->Merchants = 25;
    Me->Mills = 0;
    (Me->Name).assign(name);
    name.copy(Me->Name, name.length(), 0);
    Me->Nobles = 4;
    Me->OldTitle = 1;
    Me->Palace = 0;
    Me->PublicWorks = 1.0;
    Me->SalesTax = 10;
    Me->Serfs = 2000;
    Me->Soldiers = 25;
    Me->TitleNum = 1;
    
    if(Me->MaleOrFemale)
        (Me->Title).assign(MaleTitles[0]);
        // strcpy(Me->Title, MaleTitles[0]);
    else
        (Me->Title).assign(FemaleTitles[0]);
        // strcpy(Me->Title, FemaleTitles[0]);
    
    if(city == 6)
        (Me->Title).assign("Baron";
        strcpy(Me->Title, "Baron");
    
    Me->Treasury = 1000;
    Me->WhichPlayer = city;
    Me->Year = year;
    Me->YearOfDeath = year + 20 + Random(35);
    
    return;
}

void PlayGame(player MyPlayers[6], int NumOfPlayers)
{
    bool AllDead, Winner;
    int i, WinningPlayer = 0;
    player Baron;
    AllDead = false;
    Winner = false;
    InitializePlayer(&Baron, 1400, 6, 4, "Peppone", true);
    while(AllDead == false && Winner == false)
    {
        for(i = 0; i < NumOfPlayers; i++)
        {
            if(MyPlayers[i].IsDead == false)
                NewTurn(&MyPlayers[i], NumOfPlayers, MyPlayers,
                        &Baron); 
        }
        AllDead = true;
        for(i = 0; i < NumOfPlayers; i++)
        {
            if(AllDead == true && MyPlayers[i].IsDead == false)
                AllDead = false;
        }
        for(i = 0; i < NumOfPlayers; i++)
        {
            if(MyPlayers[i].IWon == true)
            {
                Winner = true;
                WinningPlayer = i;
            }
        }
    }
    if(AllDead == true)
    {
        std::cout << "The game has ended.\n";
        return;
    }
    std::cout << "Game Over. " << MyPlayers[WinningPlayer].Title << " " 
              << MyPlayers[WinningPlayer].Name << " wins.\n";
    return;
}


#endif



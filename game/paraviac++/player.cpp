/*
 In this file shall live all the player related function definitions that
 are outlined in player.hpp.
 */

/* Declare our standard C++ headers. */
#include <string>
#include <stdio.h>

/* Our project headers */
#include "player.h"
#include "upkeep.h"


void player::InitializePlayer(player *Me, int year, int city, int level, std::string name,
                      bool MorF)
{
    /* This is pretty straightforward. */
    Me->Cathedral = 0;
    strcpy(Me->City, CityList[city]);
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
        strcpy(Me->Title, MaleTitles[0]);
    else
        strcpy(Me->Title, FemaleTitles[0]);
    
    if(city == 6)
        strcpy(Me->Title, "Baron");
    
    Me->Treasury = 1000;
    Me->WhichPlayer = city;
    Me->Year = year;
    Me->YearOfDeath = year + 20 + Random(35);
    
    return;
}

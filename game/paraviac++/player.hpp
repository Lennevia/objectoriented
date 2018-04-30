/*
 In this file will live all details in relationship to the player
 as it pertains to the class.
 
 Needed definitions for the outlined details below can be found in
 player.cpp
 */
#include <string.h>

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

/* Function definitions that use the player class */
void InitializePlayer(player *Me, int year, int city, int level, char *name,
                      boolean MorF);

/* Declare our player definition. */
struct Player
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
    int Justice
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
    std::string City;
    std::string Name;
    std::string Title;
    float PublicWorks;
    float LandPrice;
    bool InvadeMe;
    bool IsBankrupt;
    bool IsDead;
    bool IWon;
    bool MaleOrFemale; // This is 2018, we should have a nonbinary option
    bool NewTitle;
};

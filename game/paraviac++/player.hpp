/*
 In this file will live all details in relationship to the player
 as it pertains to the class.
 
 Needed definitions for the outlined details below can be found in
 player.cpp
 */
#include <string.h>

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

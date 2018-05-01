/*
 In this file shall live all the action related function definitions that
 are outlined in actions.hpp.
 */

#include <iostream>

#include "actions.h"
#include "upkeep.h"

void BuyCathedral(player *Me)
{
    Me->Cathedral += 1;
    Me->Clergy += Random(6);
    Me->Treasury -= 5000;
    Me->PublicWorks += 1.0;
    return;
}

void BuyGrain(player *Me)
{
    char string[256];
    int HowMuch;
    std::cout << "How much grain do you want to buy (0 to specify a total)?" << std::endl;
    fgets(string, 255, stdin);
    HowMuch = (int)atoi(string);

    if(HowMuch == 0)
    {
        std::cout << "How much total grain do you wish?" << std::endl;
        fgets(string, 255, stdin);
        HowMuch = (int)atoi(string);
        HowMuch -= Me->GrainReserve;
        if(HowMuch < 0)
        {
            std::cout << "Invalid total amount.\n\n" << std::endl;
            return;
        }
    }
    Me->Treasury -= (HowMuch * Me->GrainPrice / 1000);
    Me->GrainReserve += HowMuch;
    return;
}

void BuyLand(player *Me)
{
    char string[256];
    int HowMuch;
    std::cout << "How much land do you want to buy?" << std::endl;
    fgets(string, 255, stdin);
    HowMuch = (int)atoi(string);
    Me->Land += HowMuch;
    Me->Treasury -= (int)(((float)HowMuch * Me->LandPrice));
    return;
}

void BuyMarket(player *Me)
{
    Me->Marketplaces += 1;
    Me->Merchants += 5;
    Me->Treasury -= 1000;
    Me->PublicWorks += 1.0;
    return;
}

void BuyMill(player *Me)
{
    Me->Mills += 1;
    Me->Treasury -= 2000;
    Me->PublicWorks += 0.25;
    return;
}

void BuyPalace(player *Me)
{
    Me->Palace += 1;
    Me->Nobles += Random(2);
    Me->Treasury -= 3000;
    Me->PublicWorks += 0.5;
    return;
}

void BuySoldiers(player *Me)
{
    Me->Soldiers += 20;
    Me->Serfs -= 20;
    Me->Treasury -= 500;
}

void SellGrain(player *Me)
{
    char string[256];
    int HowMuch;
    std::cout << "How much grain do you want to sell? ";
    fgets(string, 255, stdin);
    HowMuch = (int)atoi(string);
    if(HowMuch > Me->GrainReserve)
    {
        std::cout << "You don't have it.\n";
    return;
    }
    Me->Treasury += (HowMuch * Me->GrainPrice / 1000);
    Me->GrainReserve -= HowMuch;
    return;
    
}

void SellLand(player *Me)
{
    char string[256];
    int HowMuch;
    std::cout << "How much land do you want to sell? ";
    fgets(string, 255, stdin);
    HowMuch = (int)atoi(string);
    if(HowMuch > (Me->Land - 5000))
    {
        std::cout << "You can't sell that much\n";
    return;
    }
    Me->Land -= HowMuch;
    Me->Treasury += (int)(((float)HowMuch * Me->LandPrice));
    return;
}

void BuySellGrain(player *Me)
{
    bool Finished = false;
    std::string whatsNext;

    while(Finished == false)
    {
        std::cout << "\nYear " << Me->Year << "\n" ;
        std::cout << "\n" << Me->Title << " " << Me->Name << "\n\n";
        std::cout << "Rats ate " << Me->Rats << "% of your grain reserves.\n";
        PrintGrain(Me);
        std::cout << Me->RatsAte << " steres\n\n";
        std::cout << "Grain Reserve: " << Me->GrainReserve << " steres\n";
        std::cout << "Grain Demand: " << Me->GrainDemand << " steres\n";
        std::cout << "Price of Grain: " << Me->GrainPrice << "1000 st.\n";
        std::cout << "Price of Land: " << Me->LandPrice << " hectares of land\n";
        std::cout << "Treasury: " << Me->Treasury << " gold florins\n";
        std::cout << "\nYou have " << Me->Land <<  " hectares of land.\n";
        std::cout << "\n1. Buy grain, 2. Sell grain, 3. Buy land,\n";
        std::cout <<  "4. Sell land\n(Enter q to continue): ";

        std::cin >> whatsNext[0];
        if(whatsNext[0] == 'q')
            Finished = true;
        if(whatsNext[0] == '1')
            BuyGrain(Me);
        if(whatsNext[0] == '2')
            SellGrain(Me);
        if(whatsNext[0] == '3')
            BuyLand(Me);
        if(whatsNext[0] == '4')
            SellLand(Me);
    }
    return;
}
/*
 In this file will live all details in relationship to the buying
 and selling of materials in the playing of the game
 
 Needed definitions for the outlined details below can be found in
 actions.cpp
 */
#ifndef ACTIONS_H
#define ACTIONS_H

#include "player.h"

void BuyCathedral(player *);
void BuyGrain(player *);
void BuyLand(player *);
void BuyMarket(player *);
void BuyMill(player *);
void BuyPalace(player *);
void BuySoldiers(player *);
void SellGrain(player *);
void SellLand(player *);
void BuySellGrain(player *);


#endif
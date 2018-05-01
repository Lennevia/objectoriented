/*
 In this file will live all details in relationship to the upkeep
 of the game, whether that be in the setup of the intial game, or
 the updates taken between turns of the game
 
 Needed definitions for the outlined details below can be found in
 actions.cpp
 */
#ifndef UPKEEP_H
#define UPKEEP_H

#include "player.h"

void PrintInstructions(void);
int Random(int);
void getPlayers(int&);
void PrintGrain(player *);
void SerfsDecomposing(player *, float);
void SerfsProcreating(player *, float);

#endif
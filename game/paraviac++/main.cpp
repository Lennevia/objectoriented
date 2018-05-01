/* Declare our standard C++ headers. */
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <iostream>

/* Our project headers */
#include "player.h"
#include "upkeep.h"
#include "actions.h"


/* Our prototypes. */
// int main(void);

void AddRevenue(player *);
int AttackNeighbor(player *, player *);

int limit10(int, int);
bool CheckNewTitle(player *);
void GenerateHarvest(player *);
void GenerateIncome(player *);
void ChangeTitle(player *);
void NewLandAndGrainPrices(player *);

void PlayGame(player[], int);
void NewTurn(player *, int, player [], player *);
void AdjustTax(player *);
void StatePurchases(player *, int, player []);
void ShowStats(player [], int);
void ImDead(player *);



int main(void)
{
    srand (time(NULL)); // Seed for random number generator
    player MyPlayers[6];
    int NumOfPlayers;
    int level;
    int people = 1; // Initiailize to 1 because at least one person must play
    std::string str;
    std::string gender;
    std::string name;
    bool MorF;
    
    /* Initialize the random number generator seed. */
    srand(time(NULL));
    
    /* Start the game. */
    std::cout << "\nSanta Paravia and Fiumaccio\n";
    std::cout << "\nDo you wish instructions (Y or N)? ";
    std::cin >> str;
    if(str[0] == 'y' || str[0] == 'Y')
        PrintInstructions();
    
    getPlayers(NumOfPlayers);
    
    std::cout << "What will be the difficulty of this game:\n1. Apprentice\n";
    std::cout << "2. Journeyman\n3. Master\n4. Grand Master\n\nChoose: ";
    std::cin >> level;
    if(level < 1)
        level = 1;
    if(level > 4)
        level = 4;

    for(int i = 0; i < NumOfPlayers; i++)
    {
        std::cout << "Who is the ruler of " <<  CityList[i] << "? ";
        std::cin >> name;
        
        std::cout << "Is " << name << " a man or a woman (M or F)? ";
        std::cin >> gender;

        if(gender[0] == 'm' || gender[0] == 'M')
            MorF = true; // true is male
        else
            MorF = false; // false is female, I feel a little hurt here
        
        InitializePlayer(&MyPlayers[i], 1400, i, level, name, MorF);
    }
    /* Enter the main game loop. */
    // PlayGame(MyPlayers, NumOfPlayers);
    /* We're finished. */
    return(0);
}




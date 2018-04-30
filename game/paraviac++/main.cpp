/* Declare our standard C++ headers. */
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "player.hpp"
#include <random.h>
// #include <curses.h>

/* Declare our list of cities. */
char CityList[7][15] = {"Santa Paravia", "Fiumaccio", "Torricella", "Molinetto",
    "Fontanile", "Romanga", "Monterana"};

/* Declare our male titles. */
char MaleTitles[8][15] = {"Sir", "Baron", "Count", "Marquis", "Duke",
    "Grand Duke", "Prince", "* H.R.H. King"};

/* Declare our female titles. */
char FemaleTitles[8][15] = {"Lady", "Baroness", "Countess", "Marquise",
    "Duchess", "Grand Duchess", "Princess", "* H.R.H. Queen"};

/* Our prototypes. */
int main(void);
int Random(int);
void AddRevenue(player *);
int AttackNeighbor(player *, player *);
void BuyCathedral(player *);
void BuyGrain(player *);
void BuyLand(player *);
void BuyMarket(player *);
void BuyMill(player *);
void BuyPalace(player *);
void BuySoldiers(player *);
int limit10(int, int);
boolean CheckNewTitle(player *);
void GenerateHarvest(player *);
void GenerateIncome(player *);
void ChangeTitle(player *);
void NewLandAndGrainPrices(player *);
void PrintGrain(player *);
int ReleaseGrain(player *);
void SeizeAssets(player *);
void SellGrain(player *);
void SellLand(player *);
void SerfsDecomposing(player *, float);
void SerfsProcreating(player *, float);
void PrintInstructions(void);
void PlayGame(player[], int);
void NewTurn(player *, int, player [], player *);
void BuySellGrain(player *);
void AdjustTax(player *);
void DrawMap(player *);
void StatePurchases(player *, int, player []);
void ShowStats(player [], int);
void ImDead(player *);

void getPlayers(int);

int main(void)
{
    player MyPlayers[6];
    int NumOfPlayers;
    int level;
    int people = 1; // Initiailize to 1 because at least one person must play
    char string[255], name[25];
    bool MorF;
    
    /* Initialize the random number generator seed. */
    srand(time(NULL));
    
    /* Start the game. */
    std::cout << "Santa Paravia and Fiumaccio\n";
    std::cout << "\nDo you wish instructions (Y or N)? ";
    fgets(string, 254, stdin);
    if(string[0] == 'y' || string[0] == 'Y')
        PrintInstructions();
    
    getPlayers (&NumOfPlayers);
    
    std::cout << "What will be the difficulty of this game:\n1. Apprentice\n";
    std::cout << "2. Journeyman\n3. Master\n4. Grand Master\n\nChoose: ";
    fgets(string, 254, stdin);
    level = (int)atoi(string);
    if(level < 1)
        level = 1;
    if(level > 4)
        level = 4;
    for(int i = 0; i < NumOfPlayers; i++)
    {
        cout << "Who is the ruler of " <<  CityList[i] << "? ";
        fgets(name, 24, stdin);
        
        /* Strip off the trailing \n. */
        // name.pop_back(); // This should get rid of any trailing \n
//        name[strlen(name) - 1] = '\0'; // Not sure if this is relevant
        std::cout << "Is " << name << " a man or a woman (M or F)? ";
        fgets(string, 3, stdin);
        if(string[0] == 'm' || string[0] == 'M')
            MorF = true; // true is male
        else
            MorF = false; // false is female, I feel a little hurt here
        
        InitializePlayer(&MyPlayers[i], 1400, i, level, name, MorF);
    }
    /* Enter the main game loop. */
    PlayGame(MyPlayers, NumOfPlayers);
    /* We're finished. */
    return(0);
}

/*
 Prints instructions for the game if the player requests them at initialization
 of game
 */
void PrintInstructions(void)
{
    cout << "Santa Paravia and Fiumaccio\n\n";
    cout << "You are the ruler of a 15th century Italian city state.\n";
    cout << "If you rule well, you will receive higher titles. The\n";
    cout << "first player to become king or queen wins. Life expectancy\n";
    cout << "then was brief, so you may not live long enough to win.\n";
    cout << "The computer will draw a map of your state. The size\n";
    cout << "of the area in the wall grows as you buy more land. The\n";
    cout << "size of the guard tower in the upper left corner shows\n";
    cout << "the adequacy of your defenses. If it shrinks, equip more\n";
    cout << "soldiers! If the horse and plowman is touching the top of the wall,\n";
    cout << "all your land is in production. Otherwise you need more\n";
    cout << "serfs, who will migrate to your state if you distribute\n";
    cout << "more grain than the minimum demand. If you distribute less\n";
    cout << "grain, some of your people will starve, and you will have\n";
    cout << "a high death rate. High taxes raise money, but slow down\n";
    cout << "economic growth. (Press ENTER to begin game)\n";
    return;
}

/*
 This function will get user input to define the number of players.
 */
void getPlayers(&NumOfPlayers)
{
    int people = 1; // Init to 1 since at least 1 player must play
    
    std::cout << "How many people want to play (1 to 6)? ";
    cin >> people;
    
    while(people < 0 || people > 7)
    {
        // Check for correct input and allow user to correct
        cout << "Please remember that only 1 to 6 players can play!"
        std::cout << "How many people want to play (1 to 6)? ";
        cin >> people;
    }
    
    NumOfPlayers = people;
}

/*
 Creates a random number, takes in int and returns a random number b/w 0-Hi
 */
int Random(int Hi)
{
    std::random_device rd;
    std::uniform_int_distribution<int> dist(0, Hi);
    dist(rd);
    return rd;
    
//    float RanNum;
//    RanNum = (float)rand();
//    RanNum /= (float)RAND_MAX;
//    RanNum *= (float)Hi;
//    return((int)RanNum);
}


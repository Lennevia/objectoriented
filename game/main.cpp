/* Declare our standard C++ headers. */
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
// #include <curses.h>

/* Declare our player definition. */
struct Player
{
    int Cathedral, Clergy, CustomsDuty, CustomsDutyRevenue, DeadSerfs;
    int Difficulty, FleeingSerfs, GrainDemand, GrainPrice, GrainReserve;
    int Harvest, IncomeTax, IncomeTaxRevenue, RatsAte;
    int Justice, JusticeRevenue, Land, Marketplaces, MarketRevenue;
    int Merchants, MillRevenue, Mills, NewSerfs, Nobles, OldTitle, Palace;
    int Rats, SalesTax, SalesTaxRevenue, Serfs, SoldierPay, Soldiers, TitleNum;
    int TransplantedSerfs, Treasury, WhichPlayer, Year, YearOfDeath;
    char City[15], Name[25], Title[15];
    float PublicWorks, LandPrice;
    boolean InvadeMe, IsBankrupt, IsDead, IWon, MaleOrFemale, NewTitle;
} Player;

typedef struct Player player;

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
        printf("Who is the ruler of %s? ", CityList[i]);
        fgets(name, 24, stdin);
        
        /* Strip off the trailing \n. */
        name[strlen(name) - 1] = '\0';
        printf("Is %s a man or a woman (M or F)? ", name);
        fgets(string, 3, stdin);
        if(string[0] == 'm' || string[0] == 'M')
            MorF = True;
        else
            MorF = False;
        
        InitializePlayer(&MyPlayers[i], 1400, i, level, name, MorF);
    }
    /* Enter the main game loop. */
    PlayGame(MyPlayers, NumOfPlayers);
    /* We're finished. */
    return(0);
}

/*
 This function will get user input to define the number of players.
 */
void getPlayers(&NumOfPlayers)
{
    int people = 1; // Init to 1 since at least 1 player must play
    
    std::cout << "How many people want to play (1 to 6)? ";
    cin >> people;
    
    while(people < 0 && people > 7)
    {
        // Check for correct input and allow user to correct
        cout << "Please remember that only 1 to 6 players can play!"
        std::cout << "How many people want to play (1 to 6)? ";
        cin >> people;
    }
    
    NumOfPlayers = people;
}



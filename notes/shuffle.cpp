#include "bitcard.hpp"

int main()
{
    Deck d{}; // declares an empty vector
    // Deck d; also an empty vector
    
    //Declares a deck to be a sequence of cards
    Deck d1{
        {Ace, Spades}, // initializes a card object
        {Two, Spades},
        {Three, Spades},
        {Four, Spades},
        {Five, Spades},
        {Six, Spades},
        {Seven, Spades},
        {Eight, Spades},
        {Nine, Spades},
        {Ten, Spades},
        {Jack, Spades},
        {Queen, Spades},
        {King, Spades},
        
        {Ace, Clubs},
        {Two, Clubs},
        {Three, Clubs},
        {Four, Clubs},
        {Five, Clubs},
        {Six, Clubs},
        {Seven, Clubs},
        {Eight, Clubs},
        {Nine, Clubs},
        {Ten, Clubs},
        {Jack, Clubs},
        {Queen, Clubs},
        {King, Clubs},
        
        {Ace, Hearts},
        {Two, Hearts},
        {Three, Hearts},
        {Four, Hearts},
        {Five, Hearts},
        {Six, Hearts},
        {Seven, Hearts},
        {Eight, Hearts},
        {Nine, Hearts},
        {Ten, Hearts},
        {Jack, Hearts},
        {Queen, Hearts},
        {King, Hearts},
        
        {Ace, Diamonds},
        {Two, Diamonds},
        {Three, Diamonds},
        {Four, Diamonds},
        {Five, Diamonds},
        {Six, Diamonds},
        {Seven, Diamonds},
        {Eight, Diamonds},
        {Nine, Diamonds},
        {Ten, Diamonds},
        {Jack, Diamonds},
        {Queen, Diamonds},
        {King, Diamonds},
    };
    
    
  //  int n = rand(); //0..65535 (64K)
    
    shuffle(d1.begin(), d1.end());
    
    
#if 0
    //dynamically initialze each card
    Deck d2;
    for(ints = Spades; s <= Diamonds; ++s){
        for(intr = Ace; r <= King; ++r){
            //Creates and then copies a card into the vector
            d1.push_back({static_cast<Rank>(r),
                          static_cast<Suit>(s)});
            
            //Like above, but only one Card object is created
            d1.emplace_back(static_cast<Rank>(r),
                            static_cast<Suit>(s));
            
        }
    }
    
    
    
    
    
    
    
    
    
    
    
}

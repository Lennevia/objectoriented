#include "card.cpp"

// We need a way to keep track of the card types that exist in a deck of cards
// Therefore, we need to create a Rank and Suit type to keep track of the
// different cards
//
// The 'Rank' of a card is the value it represents
enum Rank {
    Ace,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
};

// The 'Suit' represents the suit of a card
enum Suit {
    Hearts,
    Diamonds,
    Cubs,
    Spades,
};


// This is the card "class" that pairs the 'Rank' and 'Suit' of a card to
// make it into an object that hold the proper info to tell us what card
// in the deck it may be
struct Card
{
    Rank r;
    Suit s;
}; 

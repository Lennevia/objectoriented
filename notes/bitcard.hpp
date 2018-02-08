#pragma once

#include <iostream>

// Defines a new type (user-defined type). Sometimes called
// a kind of type constructor (ignore that).
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

// Represents the suits of a card.
enum Suit {
    Hearts, // This is called an enumerator
    Diamonds,
    Clubs,
    Spades,
};


// A card is a Rank AND a SUIT.
//
// I want to do this:
//
//    Card c1{Ace, Spades}; // Construct from values
//    Card c2 = c1; // Copy constructor
//    c2 = c1; // Assignment operator
//    c1 == c2;
//    c1 != c2;
//
// Our representation has this layout: ssrrrr
//      where s is a suit bit and r is a rank bit
//
class Card {
public:
    Card() : bits()
    {
        
    }
    
    // Use c-style casts to make sure r and s are unsigned ints
    Card(Rank r, Suit s)
    : bits((unsigned)s << 4 | (unsigned)r)
    { }
    
    Rank get_rank() const {
        return (Rank) (0b001111 & bits); // 0xf & bits
    }
    
    Suit get_suit() const {
        return (Suit)((0b110000 & bits) >> 4);
    }
    
    // DON'T NEED A COPY CONSTRUCTOR BC COMPILER WILL AUTO MAKE IT UNLESS YOU NEED TO
    // ALLOCATE MEMORY
    // However, if one constructor is written, we cancel the ability of the Compiler to
    // be able to write the copy constructor for us
    
    // Can put in class if you're comparing it only with itself
    // If these implementations matter so much to the function of the class, make em members
    //
    // We can optimize the performanxe of the == operator by comparing int values
    bool operator==(Card c) const {
        return bits == c.bits;
    }
    
    // You may also see this from time to time
    // This is a friend funciton definition, a friend function is NOT a member
    // of the class, it actually lives outside the class, but has access to
    // private members of the class it's friends with.
    friend bool operator==(Card a, Card b){
        return a.bits == b.bits;
    }
    
    
private:
    unsigned char bits;
};


// Two cards are equal when they have the same
// rank and suit.
inline bool
operator==(Card a, Card b) {
    return a.bits == b.bits;
}

// If you define ==, then you had better define
// != also.
inline bool
operator!=(Card a, Card b) {
    return !(a == b);
}

// When do you pass by value?
// When do you pass by const reference?
//
// When the argument is only an input to the
// function.
//
// When do you copy vs. reference?
//
// DEFINITELY pass by const reference when your
// object dynamically allocates memory.


// When do you pass by reference?
//
// When the argument is an output of the
// function. The function modifies the value
// of the input.
//
// The parameter could also be "mutable".
// Also called an in/out parameter.
// The caller initializes it, the function
// modifies the value to indicate status.




#if 0
// When do you pass by reference/const reference?

void f(int n) {
    while (n != 0) {
        // Do stuff.
        --n;
    }
}

int x = 4;
f(x);
assert(x == 4);
#endif


#pragma once

#include <iostream>

// Represents the rank of a card.
enum Rank {
    Ace,   // 0001
    Two,   // 0010
    Three, // 0011
    Four,  // 0100
    Five,  // 0101
    Six,   // 0110
    Seven, // 0111
    Eight, // 1000
    Nine,  // 1001
    Ten,   // 1010
    Jack,  // 1011
    Queen, // 1100
    King,  // 1101
    // Unused bits: 1110, 1111, 0000
};

// Represents the suits of a card.
enum Suit {
    Clubs,    // 00
    Diamonds, // 01
    Hearts,   // 10
    Spades,   // 11
    // ordered alphabetically
};


// A card is a Rank AND a SUIT.
//
// Implement a card whose value is represented using a bitfield (or bitfields).
// You should support the following operations:
// 1. Default constructible
// 2. Copyable
// 3. Destructible (trivial)
// 4. Equality operators (==, !=)
// 5. Ordering (< and friends)
//
// Representation has this layout: ssrrrr
//      where s is a suit bit and r is a rank bit
//
class Card {
public:
    // let the bits have a value that is indeterminate, so we don't have to initialize it
    // we will have to assign values to them later
    // like writing int x;
    Card() : bits()
    {
        
    }
    
    // Same as above
    Card() = default;
    
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



#pragma once

// A card is basicallly a pair of rank and suit
//
// How do you represent a rank?
// How do you represent a suit?
//
//  -Just use ints. Right?
//

// How do you represent a pair of things?

// Defines a new type ( a used-defined type). Sometimes called
// a kind of type constructor (ignore that).
//
// enum will begin count at 0, so Ace will be 0, we may choose to explicitly
// set the values, but it's a value of "Ace" so it;s fine
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
    King, // Doesn't matter if there's a trailing comma here (for C++ at least)
};



// Represents the suits of a card.
enum Suit {
    Hearts, // This is an enumerator
    Diamonds,
    Cubs,
    Spades,
};
Suit s = Hearts;

// This is a scoped enum. Enumerator names are part of the enum, not the enclosing class
enum class Suit2 {
    Hearts2,
    Diamonds2,
    Cubs2,
    Spades2,
};
Suit2 c2 = Suit2::Hearts2;

// A card is a Rank AND Suit...
// We can build this using a pair. Pair is vocabulary type. This is reasonable,
// but not in our problem domain.
using Card = std::pair<Rank, Suit>;
Card c;
c.first = Ace;
c.second = Spades; // We can do better than this, build a class

// Technically this is a class.
// A card is a Rank AND Suit...
// (struct and class are fundamentally the same, just a difference in privacy)
// with struct, everything is public by default
// where class is private by default
class Card
{
    // const key-word makes object (and sub-objects) non-modifiable, we shouldn't make these const
    // declares a constructor taking a rank and a suit as arguments
    Card(Rank r, Suit s) : rank(r), suit(s) // The right way
    {
        /*
        rank = r; // The wrong way.
        suit = s;
         */
    }
    
    // Now we want the opposite of the constructor -- a destructor
    ~Card(){
        
    }
   
    
private: //using this keyword, we make these objects private
    Rank rank;
    Suit suit; // 'suit' is a sub-object
}

// With struct, we can now write:
void f () {
    Card c;
    c.rank = Ace;
    c.suit = Spades;
}

#if 0
//Type alias..


//
// Good abstraction?
using Card = int[2];

Card c;
c[0] = 3;
c[1] = 1;




// This is still a bad abstraction, why?
struct Card
{
    int first;
    int second;
}




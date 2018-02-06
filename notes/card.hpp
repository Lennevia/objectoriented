// Tells header file to only include it once ( should be in every header file)
// This is equivalent to the use of #ifndef CARD_HPP
//                                  #define CARD_HPP, etc
//                                  #endif
// #if 0 removes text for preprocessing, better than a comment can be disregarded
#pragma once

// Think about how to partition game into something more modular



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
//
// We want the class to have this type of functionality:
//  Card c =
class Card
{
    // const key-word makes object (and sub-objects) non-modifiable, we shouldn't make these const
    // declares a constructor taking a rank and a suit as arguments
    Card(Rank r, Suit s) : rank(r), suit(s) // The right way
    {}
    
    //A copy constructor ALWAYS has the following form (unless you're an expert)
    Card( const Card& c)
    : rank(c.rank), suit(c.suit)
    {}
    
    // A sopy assignment operator ALWAYS has the following form:
    // If c1 = c2,
    // "'this' is a pointer to c1"
    Card& operator=(const Card& c){
        rank = c.rank;
        suit = c.suit;
        
        // Ths code above is equivalent to this:
        this->rank = c.rank;
        this->suit = c.suit;
        return @this;
    }
    
    // Accessor functions (sometimes called observers
    
    // Mutators or modifier functions
    // Think about the need for a mutator before creating it for a private member,
    // they might be private for a reason
    void set_rank(Rank r) { rank = r; }
    void set_suit(Suit s) { suit = s; }
    
    
    // In-class member function defs are implicitly inline
    Rank get_rank() const { return rank; }
    Suit get_suit() const { return suit; }
    
    // A friend can access private members of this class
    // This can indicate that separate (logical) components are not in face separate
    // if a friend can modify private members
    /* friend bool operator==(Card a, Card b); */

    
    // Now we want the opposite of the constructor -- a destructor
    ~Card(){
        
    }
    
    
private: //using this keyword, we make these objects private
    Rank rank;
    Suit suit; // 'suit' is a sub-object
};

// Two cards are equal when they have the same rank and suit
//
// IN general, define == to mean that two objects represent the
// same entity. This means you can *substitute* equal values as
// inputs to (certain) functions and expect equal results.
inline
bool Card::operator==(Card a, Card b){
    return a.rank == b.rank && a.suit == b.suit;
}

// IF you define ==, you had better define != also
inline
bool Card::operator!=(Card a, Card b){
    return !(a == b);
}

// IF we get an error that includes 'symbol', we are probably breaking the ONE-DEF-RULE
// An error with "undefined symbols" has the declaration of something but no definition




// With struct, we can now write:
void f () {
    Card c;
    c.rank = Ace;
    c.suit = Spades;
}

// Rank is a type with a set of values = { Ace, Two, ..., King}
// so how would you describe 'Card'?
// Card can be described as a cross product: Card = Rank x Suit
struct Card{
    Suit suit;
    Rank rank;
};




// When do you pass by reference/const reference?
// Pass by reference when the argument is an output of the function. The fcuntion modifies the value of the input
// When do you pass by value: wehn the argument is only an input to the function
//
//The paramete coudl also be "mutable". Also called an in/out parameter.
//The caller intiiaizes the value to indicate status
//
// So what about "const int&"?:  a reference to a constant object that cannot be changed
//difference b/w above and "int const&": There is no difference.
//
// One can cannonically read types from right to left
//
// What does "const int* const" mean? One can rewrite this to "const int &"
// What does "int *const *" - a pointer to a constant pointer to an int
// so if we de-reference the pointer, we get another pointer
//
// When do you choose to copy or reference?
// IF a value is no larger than a register, use a value.
// Your compiler is usually good enough tp copy a piece of memory larger than a register by itself
// DEFINITELY pass by const reference when your object dynamically allocates memory.
//
// Almost every other object oriented programming language passes EVERYTHING by reference
// Java and C#  write everything by pointer so they can only use pointers, no vectors,
// having them suffer from performance errors
void f(int n) {
    
}

//So what value does c hold? Possibly indeterminate
// Meaning this 'c' could be an invalid card.
//
// We can by default construct a card if we want within the def of the class
// We can create a card object with the default contructor
Card c;
c.rank = Ace;
c.suit = Spades;

// If you can write 'Card c', you can also write this since Card is
// default constructible. Be careful, these have indeterminate values
Card cards[52];

// These cards are value (zero?) initialized, we don't know but it's doable
Card* ptr = new Card[52];


// One should almost never use arrays as they leave room for bugs, use VECTORS
// don't use 'naked' arrays
std::vector<Card> deck(52);

// We can copy cards, called copy construction
//
// What must be true after construction? It should be the case that c and c2
// have the **same value** (refer to same entity)
Card c2 = c;
assert(c2 == c); // Asserts if this is true, crashes if not true

// This is called copy assignment
//
// What must be true after assignment?
c2 = c;
assert(c2 == c);

// This is called a move constructor
// c3 takes over the place of c and takes value so there are no overlaps
// This is used when we have a huge amount of vectors and we take the bits
// from c and put them in c3. c is obliterated
Card c3 = std::move(c);

// This is called move assignment
c3 = std::move(c);

// Value semantics.
//
// Any type (class) that can be copied (and moved) is typically
// said to have "value semantics"
// what's something that isn't value semantic?
// not a semantic class, but it's a *resource class*
// We know it's not a semantic type bc we don't really know how to
// define equality or a methodo of copying
//
// Value semantic types are also said to be Regular types
File f1("~/.bashrc");
f2 = f1; // This is not a semantic type bc we don't know what will happen
// When the copy constructor is used


// You can provide values using an initializer-list
// This will select one of several constructors to initialiize the object
//
// If you don'r define any constructors, then this will still magically initialize the object
CArd c {Ace, Spades};

// These do the same things, but only use the latter form when dealing with a list
int n = 4;
int n {4};
int n {}; // guarantees a value of 0 (for ints)

Card c {}; /// guarantees everything is zero-bit assigned

// What does x hold? an indeterminate, something we don't know
int x;



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




/*
Represent a thing

~Use a variant
~Declarative union
~Bit tricks -  when using ints or whatever
~using the object oriented way with structs and classes and more:
*/


// Declare the base class
/*
 The card c0:
    |----------------|
    |     Card       |  id
    |----------------|
    |     Suit       |  spades
    |----------------|
    |     Rank       |  ace
    |----------------|
 
 
 */

struct Card
{
    int id; // So if we sort the deck in order, each card will have an id
    
    Card(int id)
    
};

/*
 Standard Card is the derived class or subclass, where Card is the base class or the super class
 The : means class inheritance
 
 Rules of inheritance:
 ~inheritance can be modified
 ~if a member in the base class is public, we inherit it as public, same for private
 ~There's a thing called private inheritance: whatever public members in the interface
 become private
        struct StandardCard : private Card
 Then we can no longer use StandardCard as a Card since we can't access anything
 
 */
// Declares a derived class. WE often say that Standard IS-A Card.
struct StandardCard : Card
{
    // WE "inherit" the members of the base
    // class almost as is they were declared here
    
    //Just a reg const..but
    //You can can call a base class const explicitly in the member initializer list
    StandardCard(int n, Rank r, Suit s)
    : Card(n), rank(r), Suit(s)
    {}
    
    // Any language that claims to be object oriented, passes variables by reference
    // Java/C# is technically a pass by value language
    
    Rank rank;
    Suit suit;
};

// Declares another derived class
class Joker : Card
{
public:
    JokerCard(int n, Color c)
    : Card(n), color(c)
    {}
    
    
    Color color;
};

/* Can happily continue making more classes that derive from card rather than modifying other sets */




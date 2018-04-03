#include "base_class.hpp"

#include <iostream>

int main()
{
    StandardCard c0(0, Ace, Spades);
    StandardCard c1(1, Two, Spades);
    
    std::cout << c0.id << '\n';
    std::cout << c0.get_id() << '\n';
    
    //This will compile, what will it do?
    // We've converted c0 to a Card.
    // This is called *object slicing*. You take only the bits in the base
    // class and discard the remainder.
    //
    // We want to enforce that you CANNOT make this kind of card
    Card c = c0;
    
    std::cout << c0.get_rank() << '\n'; // This still works
    
    // Does this return ace?
    // This will not compile
   // std::cout << c.get_rank();
    // But we can get the id to print out
    std::cout << c.get_id();
    
}

// Define algorithms on base classes. the derived classed may contain
// specialized info not used by the algorithm
void f(Card& c)
{
    std::cout << c_get_id() << '\n';
    //What's the static type of c?
}

void main2()
{
    // Static type is the type of the object locked in at compile time
    // Dynamic type can only change during runtime
    StandardCard c0(0, Ace, Spades);
//    JokerCard j0(52, Red);
    
    Card& c = c0;
    // Card is the static type of c
    // StandardCard is the dynamic type of c
    
    // Cannot narrow this reference, this will not work, a heisenberg object
//    JokerCard& j = c;
    
    c.rank == Ace; // error: no such member
    
    f(c0); // at this point, the dynamic type is StandardCard
    f(j0); // dynamic type if JokerCard
    
    // Can cast a pointer to a derived class or widen to base class
    // Pointers can be widened from derived to base classes
    Card* p = &c0;
    
    // Not ever Card is a StandardCard, this may not be a valid function
    // This actually is not allowed.
    // Cannot implicitly narrow a base class to a derived class
    StandardCard* p1 = p;
    
}

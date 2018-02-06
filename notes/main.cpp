#include "card.hpp"

#include <iostream> // This adds about 40K lines to process

// inline is used to cut down process time
// But now, inline function is used to unify definitions
// Then the compiler has the option to pick between which def it wants to
// use in the case that it's called -> Leading to undefined behavior
//
// Moral of the story: use inline with small header files, but it's
// normally in better practice to abstract header definitions with a source file
//
// this separates the *interface* of a class from its *implementation*
inline int foo() { return 42; }

int main()
{
    std::cout << "hello world\n";
    
    Rank r1 = King;
    Rank r2 = Queen;
    
    std::cout << (r1 == r2) << '\n';
    std::cout << (r1 < r2) << '\n';
    
    
    // We'll be using types to create restrcitions to prevent type errors
    // Narrowing conversion. (Large set to small set; narrowing)
    // Rank r3 = 4; //error -- can't convert to Rank
    
    // This shouldn't work
    Rank r4 = -1; // This will not work, -1 is an invalid rank -- type error
 
    
    // We can cast int to rank.
    // This is a potential error condition
    Rank r5 = static_cast<Rank>(4); // This would work for 4, as it's a valid enum
    Rank r5 = static_cast<Rank>(-1); // But wouldn't work here as -1 is invalid
    // You are obliged to verify that Ace <= n0 && n0 <= King
    int n0;
    Rank r5 = static_cast<Rank>(n0); // We don't know what this will do
    
    
    //This is a widening conversion and is guaranteed to work (almost certainly)
    int n = King;
}

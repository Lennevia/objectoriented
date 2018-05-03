// More on templates

float NaN = 0.0 / 0.0;
std::cout << NaN << '\n';

float f1 = NaN;
float f2 = NaN;
// If you ever have NaN, do not sort the array. You cannot do the
// min or max of NaN. You get subtle, undefined behavior.

// If a==b is part of the requirement, you need equality comparable
// So this EqualityComparable must require that a == b -> bool
//
// When are two things equal? x == y when you can sub y anywhere x is for a
// reasonable function
// The C++ way: if a == b is true => a equals b
// a equals if b is a copt of a???

// What is the relationship between equality and the ability to be ordered?
// Refinement: IT's almost like inheritance.

// Generics in different languages: templates in c++ work at runtime if they
// fit the given requirements

// For java and c#, you must write repetitive functions 


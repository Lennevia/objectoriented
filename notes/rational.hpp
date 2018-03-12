// COPYRIGHT (C) 2018 Laverena Wienclaw (llw50 ) All rights reserved.
//
// rational.hpp: Definition of rational class and its interface.


#include <cstdlib>
#include <iosfwd>
#include <iostream>
#include <stdlib.h>

// Represents a rational number. The rational numbers are the set of
// numbers that can be represented as the quotient of two integers.
class Rational
{
private:
    int num;
    int den;
    
public:
    // 1. A default constructor
    Rational();
    // 2. A constructor that takes an integer value
    Rational(int);
    // 3. A constructor that takes a pair of values
    Rational(int, int);
    
    // Returns the numerator.
    int getNum();
    // Returns the denominator
    int getDen();
};

//checks if rational numbers are the same, returns true if so
bool operator ==(Rational, Rational );

//checks if rational numbers are the same, returns true if not so
bool operator !=(Rational, Rational);

//Less than operator, <, if left side is less than right, return true
bool operator <(Rational, Rational);

//Greater than operator, >, if left is greater than right side, returns true
bool operator >(Rational, Rational);

//Less than or equal to operator, <=, if left is less than or equal to right, return true
bool operator <=(Rational, Rational);

//Greater than or equal to operator, >=, if left is greater than or equal to right, return true
bool operator >=(Rational, Rational);

//Overload + operator
double operator+(Rational, Rational);

//Overload - operator
double operator-(Rational, Rational);

//Overload * operator
double operator*(Rational, Rational);

//Overload / operator
double operator/(Rational, Rational);

// Reduces the fraction to be lower
void normalize(Rational);

// Input and Output of a Rational number
std::ostream& operator<<(std::ostream&, Rational);
std::istream& operator>>(std::istream&, Rational&);

// Mathematical helper functions.
//
// These are defined in rational.cpp
// They were given by Professor Crissey in CS2
int gcd(int, int);
int lcm(int, int);



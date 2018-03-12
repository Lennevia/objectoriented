// COPYRIGHT (C) 2018 Laverena Wienclaw (llw50) All rights reserved.
//
// rashinall.hpp: Definition of rational class and its interace.

#include "rational.hpp"
#include <iostream>

//Constructors
//Default Constructor
Rational::Rational()
{
    num = 0;
    den = 1;
}

//Constructor that takes an integer n and initializes rationalNum to be 1/n
Rational::Rational(int n)
{
    num = n;
    den = 1;
}

//Constructor
Rational::Rational(int top, int bottom)
{
    //denominator cannot be zero in a rational fraction
    if (bottom == 0)
    {
        std::cout << "The denominator is zero, this is an invalid denominator.\n";
    }
    
    //reduce fraction to its simplest form
    int temp;
    temp = gcd(top, bottom);
    top /= temp;
    bottom /= temp;
    //make sure top and bottom of rational number are in the correct order for later functions
    
    num = top;
    den = bottom;
}

//For following three functions:
//Precondition: Overloads the == operator for the rational values to check for equality
//Postcondition: a bool is returned, true if equal, false if not equal
bool operator ==(Rational  left, Rational right)
{
    return ((left.getNum() / left.getDen()) == (right.getNum() / right.getDen()));
}

//For following three functions:
//Precondition: Overloads the != operator for the rational values to check for inequality
//Postcondition: a bool is returned, true if not equal, false if equal
bool operator !=(Rational left, Rational right)
{
    return((left.getNum() / left.getDen()) != (right.getNum() / right.getDen()));
}


//For the following three functions:
//Precondition: takes in two values of class Rational
//Postcondition: returns true if left side is less than right, false otherwise
bool operator <(Rational left, Rational right)
{
    return !((left.getNum()/ left.getDen()) < (right.getNum() / right.getDen()));
}


//For the following three functions:
//Precondition: takes in two values of class Rational
//Postcondition: returns true if left side is greater than right, false otherwise
bool operator >(Rational left, Rational right)
{
    return !((left.getNum() / left.getDen()) > (right.getNum()/ right.getDen()));
}

//For the following three functions:
//Precondition: takes in two values of class Rational
//Postcondition: returns true if left side is less or equal to right, false otherwise
bool operator <=(Rational left, Rational right)
{
    return((left.getNum() / left.getDen()) <= (right.getNum() / right.getDen()));
}

//For the following three functions:
//Precondition: takes in two values of class Rational
//Postcondition: returns true if left side is greater or equal to right, false otherwise
bool operator >=(Rational left, Rational right)
{
    return ((left.getNum() / left.getDen()) >= (right.getNum() / right.getDen()));
}

//For the following three functions:
//Precondition: overloads the + operator to add rational numbers
//Postcondition: returns the value of the added rational numbers
double operator+(Rational left, Rational right)
{
    return((left.getNum() / left.getDen()) + (right.getNum() / right.getDen()));
}

//For the following three functions:
//Precondition: overloads the - operator to subtract rational numbers
//Postcondition: returns the value of the left number minace the right number rational numbers
double operator-(Rational left, Rational right)
{
    return((left.getNum() / left.getDen()) + (right.getNum() / right.getDen()));
}


//For the following three functions:
//Precondition: overloads the * operator to subtract rational numbers
//Postcondition: returns the value of the left number multiplied by the right number
double operator*(Rational left, Rational right)
{
    return ((left.getNum() * right.getNum()) / (left.getDen() * right.getDen()));
}

//For the following three functions:
//Precondition: overloads the * operator to subtract rational numbers
//Postcondition: returns the value of the left number multiplied by the right number
double operator/(Rational left, Rational right)
{
    double tempden, tempnum, topleft, bottomleft, topright, bottomright;
    topleft = left.getNum();
    bottomleft = left.getDen();
    topright = right.getNum();
    bottomright = right.getDen();
    
    tempnum = (topleft * bottomright);
    tempden = (bottomleft * topright);
    
    return (tempnum / tempden);
}

/*double operator/(double left, Rational right)
 {
 return(left / (right.getNum() / right.getDen()));
 }
 
 double operator/(Rational left, double right)
 {
 return((left.getNum() / left.getDen()) / right);
 }*/

// -------------------------------------------------------------//
// Helper functions

// Compute the GCD of two integer values using Euclid's algorithm.
int
gcd(int a, int b)
{
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}


// Compute the LCM of two integer values.
int
lcm(int a, int b)
{
    return (std::abs(a) / gcd(a, b)) * std::abs(b);
}

// -------------------------------------------------------------------------- //
// Rational implementation

// Make this print integers when the denominator is 1.
// overloaded operator of the << operator
std::ostream& operator<<(std::ostream& os, Rational r)
{
    if( r.getDen()== 1)
    {
        return os << r.getNum();
    }
    return os << r.getNum() << '/' << r.getDen();
}

// Make this read integer values if no '/' is given as a separator.
// You may assume that there is no space between the numerator and the
// slash. Hint, find and read the reference documentation for istream::peek().
//overloaded operation for the >> operator
std::istream& operator>>(std::istream& is, Rational& r)
{
    //read first number
    int p;
    is >> p;
    if(!is)
    {
        return is;
    }
    
    //check for '/'
    if(is.peek() != '/')
    {
        r = Rational(p);
        return is;;
    }
    is.get();
    
    //Read second number
    int q;
    is >> q;
    if (!q)
    {
        return is;
    }
    // Make sure that we didn't read p/0.
    if (q == 0) {
        is.setstate(std::ios::failbit);
        return is;
    }
    r = Rational(p, q);
    return is;
    
#if 0
    int p, q;
    char c;
    is >> p >> c >> q;
    if (!is)
        return is;
    // Require that the divider to be a '/'.
    if (c != '/') {
        is.setstate(std::ios::failbit);
        return is;
    }
    // Make sure that we didn't read p/0.
    r = Rational(p, q);
    return is;
#endif
}

// accessor functions to the private members num and den
int Rational::getNum()
{
    return num;
}

int Rational::getDen()
{
    return den;
}

void normalize (Rational object)
{
    numer = object.num;
    denom = object.den;
    //reduce fraction to its simplest form
    int temp;
    temp = gcd(numer, denom);
    numer /= temp;
    denom /= temp;
    }
    //make sure num and den are in the correct order for later functions
    if (numer < 0 && denom < 0)
    {
        numer *= -1;
        denom *= -1;
    }
    if (denom < 0 && numer > 0)
    {
        numer *= -1;
    }

    object.num = numer;
    object.den = denom;
}




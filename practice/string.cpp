#incude "string.hpp"
#include <cstring>

// Here are the hidden away abstractions of the functionality of the String class

// Default construct: string s;
String::String()
{
    len = 1; // make room for a null pointer
    str = new char[len];
    str[len - 1] = '\0'; // assign null char
}

// Construct and assign a literal value
String::String(const char *strnew)
{
    len = strlen(strnew) + 1; // account for Null
    str = new char[len];
    
    for(int i = 0; i < (len - 1); i++)
    {
        str[i] = strnew[i];
    }
    str[(len - 1)] = '\0'; // input the null
}

// Object independence
// s2 = "bar"; // Does not change the value of s1
String& String::operator=(const String& s)
{
    len = s.len;
    delete[] str;
    str = new char[len];
    
    for(int i = 0 ; i < (len -1);i++)
    {
        str[i] = s.str[i];
    }
    str[(len - 1)] = '\0';
    return *this;
}




Card::Card(const Card& c)
: rank(c.rank), suit(c.suit)
{ }

Card&
Card::operator=(const Card& c) {
    rank = c.rank;
    suit = c.suit;
    
    // // The code above is equivalent to this:
    // this->rank = c.rank;
    // this->suit = c.suit;
    return *this;
}


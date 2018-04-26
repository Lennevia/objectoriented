#pragma once

template<typename T>
min<template> (T a, T b)  //This may be totally wrong, check notes


T min(T a, T b)
{
    return a < b ? a : b;
}

//Object-oriented version:
//(Not a very good solution)


class Comparable
{
    virtual bool less(Comparable& that) = 0;
    
};

Comparable& min(Compareable& a, Comparable& b)
{
    if(a.less(b))
        return a;
    else
        return b;
}

int& min(int& a, int& b)
{
    return a < b ? a : b;
}

double& min(double& a, double& b)
{
    return a < b ? a : b;
}

// For built in types, we have to continuously spam the different definitions for
// different types. This is redundant and wasteful.

/// T is also called a template parameter. We need to provide arguments for this
// later. See below.

void f()
{
    // Explicitly specify the type arguments (or *template argrumants*)
    min<int>(0, 3;)
// This instantiates the template min. Instatntiation substitutes template arguments for their corresponding template parameters and prodices a NEW declaration
}


//The compiler actually generates something like this:
template<>
const int& min<int>(const int& a, const int& b)
{
    return a < b ? a : b;
}

//This is called a template specialization. This one has been generated implicitly by the instantiation above.
//
// Note that we can actually write this in our code in order to supply more efficient verisona of the algorithm.

// For example:
template<>
int min_value<int>(int a, int b)
{
    return y ^ ((x ^ y) & -(x < y));
}

//Note that we are substitiuting this version of the function for the more generic one. 





T& min(T& a, T& b)
{
    
}

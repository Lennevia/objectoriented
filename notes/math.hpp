/*
 April 17, 2018
 
 This Tuesday, Sutton talked about alternatives, variants, and built a
 recursive data structure within the files math.hpp and main.cpp
 
 Builds a discriminates union/variant by hand
 */

struct Value{
    enum Kind {
        boolean,
        integer,
        floating
    };
    union Data{
        bool b;
        int z;
        float f;
    };
    Value(float b) // avoid writing this yourself when you can, use std variant
        :kind(floating) //but for now we're stuck writing by hand
    {}
    }

/*
 Recursive data structure to represent expressions as an inhertitance hierarchy, we can
 say that because it's a tree-like data structure
 
 Data structure for representing alternatives - using a variant or discrim union,
 we would never use inheritance for this because we intend to copy. And you should NEVER do that with inheritance. 
 */
    
    
};
